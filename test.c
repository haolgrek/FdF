#include "mlx.h"
#include <stdio.h>

/*int	my_key_funct(int keycode, void *win)
{
	printf("key event %d\n", keycode);
	mlx_pixel_put(mlx, win, 300, 300, 0xFF00FF);
	return (0);
}*/

int	main()
{
	void	*mlx;
	void	*win;
	void	*img;
	int		x;
	int		y;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42");
	img = mlx_new_image(mlx, 200, 200);
	y = 50;
	while (y < 150)
	{
		x = 50;
		while (x < 150)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
//	mlx_key_hook(win, my_key_funct, win);
//	mlx_put_image_to_window(mlx, win, img, 50, 50);
	mlx_loop(mlx);
}
