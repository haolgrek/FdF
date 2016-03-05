#include "mlx.h"
#include "get_next_line.h"
#include <stdio.h>
#include "libft/libft.h"

/*int	my_key_funct(int keycode, void *win)
{
	printf("key event %d\n", keycode);
	mlx_pixel_put(mlx, win, 300, 300, 0xFF00FF);
	return (0);
}*/

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*data;
	int		x;
	int		y;
	char	**tab;
	char	*line;
	int		i;
	int		j;
	int		fd;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) != 0)
	{
		tab[i] = ft_strcpy(tab[i], line);
		i++;
	}
	i = 0;
	printf("line 0 = %s\n", tab[0]);
	printf("line 1 = %s\n", tab[1]);
	printf("line 2 = %s\n", tab[2]);
	return (0);
//	mlx = mlx_init();
//	win = mlx_new_window(mlx, 400, 400, "mlx 42");
//	img = mlx_new_image(mlx, 200, 200);
//	data = mlx_get_data_addr(img, 8, , 0);
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
//	mlx_key_hook(win, my_key_funct, win);
	mlx_put_image_to_window(mlx, win, img, 50, 50);
	mlx_loop(mlx);*/
}
