#include "mlx.h"
#include "get_next_line.h"
#include "fdf.h"
#include <stdio.h>
#include "libft/libft.h"

/*int	my_key_funct(int keycode, void *win)
  {
  printf("key event %d\n", keycode);
  mlx_pixel_put(mlx, win, 300, 300, 0xFF00FF);
  return (0);
  }*/



t_fdf	*ft_create_elem(char *file)
{
	t_fdf		*lst;
	int			i;

	i = ft_strlen(file);
	lst = malloc(sizeof(t_fdf));
	if (lst)
	{
		lst->line = file;
		lst->next = NULL;
	}
	return (lst);
}

t_fdf	*ft_list_insert_back(t_fdf *list, char *file)
{
	t_fdf	*tmp;
	t_fdf	*tmp2;

	tmp = ft_create_elem(file);
	if (tmp)
	{
		if (list)
		{
			tmp2 = list;
			while (tmp2->next)
				tmp2 = tmp2->next;
			tmp2->next = tmp;
		}
		else
			list = tmp;
	}
	return (list);
}

int	*ft_char_atoi(char **split)
{
	int	*tab;
	int	i;
	int	j;

	i = 0;
	while (split[i] != '\0')
		i++;
	tab = malloc(sizeof(int) * i);
	j = i;
	i = 0;
	while (i < j)
	{
		tab[i] = ft_atoi(split[i]);
		i++;
	}
	return (tab);
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	void	*img;
	int		bites;
	int		size_line;
	int		endian;
	int		*data;
	int		x;
	int		y;
	char	*line;
	int		i;
	int		j;
	int		fd;
	t_fdf	*list;
	t_fdf	*start;

/*	list = NULL;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) != 0)
		list = ft_list_insert_back(list, line);
	start = list;
	write (1, "a\n", 2);
	while (list)
	{
		list->split = ft_strsplit(list->line, ' ');
		list = list->next;
	}
	list = start;
	while (list)
	{
		list->tab = ft_char_atoi(list->split);
		list = list->next;
	}
	list = start;
	while (list)
	{
		i = 0;
		while (i < 19)
		{
			ft_putnbr(list->tab[i]);
			i++;
		}
		write (1, "\n", 1);
		list = list->next;
	}
	list = start;*/
//	return (0);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42");
	img = mlx_new_image(mlx, 400, 400);
	data = (int*)mlx_get_data_addr(img, &bites, &size_line, &endian);
	data[47] = 0x00FF0000;
	//	y = 40;
	/*	while (y < 150)
		{
		x = 40;
		while (x < 150)
		{
		mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
		x++;
		}
		y++;
		}
	//	mlx_key_hook(win, my_key_funct, win);*/
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);
}
