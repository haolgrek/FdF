/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 11:39:41 by rluder            #+#    #+#             */
/*   Updated: 2016/03/15 10:19:06 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "get_next_line.h"
#include "fdf.h"
#include <stdio.h>
#include "libft/libft.h"

int	ft_linelen(char *str)
{
	int	i;
	int	wasspace;
	int	len;

	i = 0;
	len = 0;
	wasspace = 1;
	while (str[i])
	{
		if (str[i] != ' ' && wasspace == 1)
		{
			wasspace = 0;
			len++;
		}
		else if (str[i] == ' ')
			wasspace = 1;
		i++;
	}
	return (len);
}

int	checkline(char *str)
{
	static int	lastlen;
	int			len;

	if (!str)
		return (0);
	len = ft_linelen(str);
	if (len == -1)
		return (0);
	if (lastlen > 0)
		if (lastlen != len)
			return (0);
	lastlen = len;
	return (1);
}

t_data	*ft_create_elem(int *tab, int len, int y)
{
	t_data	*lst;

	lst = malloc(sizeof(t_data));
	if (!lst)
		return (NULL);
	lst->tab = tab;
	lst->len = len;
	lst->y = y;
	lst->next = NULL;
	return (lst);
}

int	tablen(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int	*create_tab(char **split)
{
	int	i;
	int	j;
	int	*tab;

	i = 0;
	j = 0;
	while (split[i])
		i++;
	tab = malloc(sizeof(int) * i);
	while (j < i)
	{
		tab[j] = ft_atoi(split[j]);
		j++;
	}
	return (tab);
}

t_data	*get_file(int fd, char *line)
{
	int		*tab;
	int		len;
	int		y;
	t_data	*lst[2];

	y = 0;
	lst[0] = NULL;
	while (get_next_line(fd, &line))
	{
		if (!checkline(line))
			return (NULL);
		tab = create_tab(ft_strsplit(line, ' '));
		len = tablen(ft_strsplit(line, ' '));
		if (!lst[0])
		{
			lst[1] = ft_create_elem(tab, len, y++);
			lst[0] = lst[1];
		}
		else if (len > 0)
		{
			lst[1]->next = ft_create_elem(tab, len, y++);
			lst[1] = lst[1]->next;
		}
	}
	return (lst[0]);
}

t_data	*parse(char *file)
{
	int		fd;
	t_data	*start;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	start = get_file(fd, NULL);
	close (fd);
	return (start);
}

int	main(int argc, char **argv)
{
	t_data	*file;
	t_mlx	*m;

	if (argc != 2)
	{
		ft_putendl("Wrong number of arguments");
		return (0);
	}
	file = parse(argv[1]);
	if (!file)
	{
		ft_putendl("File error");
		return (0);
	}
	m = init_mlx(file);
	bresenham_x(m, file);
	bresenham_y(m, file);
	mlx_put_image_to_window(m->mlx, m->win, m->img, m->imgx, m->imgy);
	mlx_hook(m->win, 2, 1, keys, m);
	mlx_loop(m->mlx);
	return (0);
}
