/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 19:56:14 by rluder            #+#    #+#             */
/*   Updated: 2016/03/15 11:51:37 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	other_events(int keycode, t_mlx *m)
{
	if (keycode == 69 || (keycode == 78 && m->gap > 0) || keycode == 83 ||
			keycode == 84 || keycode == 89 || keycode == 91 || keycode == 15)
	{
		m->intab = blacktab(m);
		fillintab(m->data, m, m->intab);
		bresenham_x(m, m->data);
		bresenham_y(m, m->data);
	}
}

void	reset(t_mlx *m)
{
	m->height = 1;
	m->color = 16777215;
	m->xsize = 2400;
	m->ysize = 1280;
	m->imgx = 75;
	m->imgy = 75;
	m->gap = 1;
}

void	directions(int keycode, t_mlx *m)
{
	if (keycode == 126)
		m->imgy -= 10;
	else if (keycode == 124)
		m->imgx += 10;
	else if (keycode == 125)
		m->imgy += 10;
	else if (keycode == 123)
		m->imgx -= 10;
}

int		keys(int keycode, t_mlx *m)
{
	if (keycode == 53)
		exit(0);
	directions(keycode, m);
	if (keycode == 69 && m->maxx * (m->gap + 2) < m->xsize)
		m->gap++;
	else if (keycode == 78 && m->gap > 0)
		m->gap--;
	else if (keycode == 83)
		m->color -= 512;
	else if (keycode == 84)
		m->color += 512;
	else if (keycode == 89 && m->height > -3)
		m->height--;
	else if (keycode == 91 && m->height < 3)
		m->height++;
	else if (keycode == 15)
		reset(m);
	mlx_clear_window(m->mlx, m->win);
	other_events(keycode, m);
	mlx_put_image_to_window(m->mlx, m->win, m->img, m->imgx, m->imgy);
	return (0);
}

int		*fillintab(t_data *file, t_mlx *m, int *intab)
{
	int	i;
	int	x;
	int	y;

	while (file)
	{
		i = 0;
		while (i < file->len)
		{
			x = i * m->gap - file->tab[i] * m->height;
			y = file->y * m->gap * m->xsize - file->tab[i] * m->height * 
				m->xsize;
			intab[/*m->maxx * m->xsize + m->maxy * m->ysize*/ + x + y + 50] = 0xFFFFFF
				- (file->tab[i] * 256);
			i++;
		}
		file = file->next;
	}
	return (intab);
}

int*max_sizes(t_data *file)
{
	int*max;

	max = malloc(sizeof(int) * 2);
	max[0] = 0;
	max[1] = 0;
	while (file)
	{
		if (file->len > max[0])
			max[0] = file->len;
		if (file->y > max[1])
			max[1] = file->y;
		file = file->next;
	}
	return (max);
}

t_mlx	*init_mlx(t_data *file)
{
	t_mlx	*m;
	int		*max;

	max = max_sizes(file);
	m = malloc(sizeof(t_mlx));
	m->height = 1;
	m->color = 16777215;
	m->data = file;
	m->mlx = mlx_init();
	m->xsize = 2400;
	m->ysize = 1280;
	m->maxx = max[0];
	m->maxy = max[1];
	m->imgx = 75;
	m->imgy = 75;
	m->gap = 1;
	m->win = mlx_new_window(m->mlx, m->xsize, m->ysize, "FdF");
	m->img = mlx_new_image(m->mlx, m->xsize, m->ysize);
	m->intab = fillintab(file, m, (int*)mlx_get_data_addr(m->img, &m->bits,
				&m->size, &m->endian));
	return (m);
}
