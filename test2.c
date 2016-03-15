/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 10:01:02 by rluder            #+#    #+#             */
/*   Updated: 2016/03/15 10:07:29 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

int	my_key_funct(int keycode, void *param)
{
	printf("key = %d\n", keycode);
	return (0);
}


int	main()
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42");

	mlx_key_hook(win, my_key_funct, 0);
	mlx_loop(mlx);
}
