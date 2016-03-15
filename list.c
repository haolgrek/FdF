/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 14:08:42 by rluder            #+#    #+#             */
/*   Updated: 2016/03/15 14:29:27 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	other_events(int keycode, t_mlx *m)
{
	if (keycode == 69 || (keycode == 78 && m->gap > 0) || keycode == 83 ||
			keycode == 84 || keycode == 89 || keycode == 91 || keycode == 15)
	{
		m->intab = zerotab(m);
		fillintab(m->data, m, m->intab);
		bresenham_x(m, m->data);
		bresenham_y(m, m->data);
	}
}

void	reset(t_mlx *m)
{
	m->height = 1;
	m->color = 16777215;
	m->xsize = 2048;
	m->ysize = 1024;
	m->imgx = 75;
	m->imgy = 75;
	m->gap = 1;
}

int		ft_linelen(char *str)
{
	int	i;
	int	space;
	int	len;

	i = 0;
	len = 0;
	space = 1;
	while (str[i])
	{
		if (str[i] != ' ' && space == 1)
		{
			space = 0;
			len++;
		}
		else if (str[i] == ' ')
			space = 1;
		i++;
	}
	return (len);
}

int		checkline(char *str)
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
