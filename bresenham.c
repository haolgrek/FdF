/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:16:23 by rluder            #+#    #+#             */
/*   Updated: 2016/03/15 11:51:56 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		*blacktab(t_mlx *m)
{
	int	i;

	i = 0;
	while (i < m->xsize * m->ysize)
		m->intab[i++] = 0;
	return (m->intab);
}

void	ft_put_pixels(int x, int y, t_mlx *m, int z)
{
	m->intab[/*m->maxx * m->xsize + m->maxy * m->ysize*/ +
		(x + 50 + y * m->xsize)] = m->color - (z * 0x00FFFF / 10);
}

t_brs	*init_brs(t_pos *p)
{
	t_brs	*b;

	b = malloc(sizeof(t_brs));
	if (!b)
		return ((void*)0);
	b->ex = p->x2 - p->x1 >= 0 ? p->x2 - p->x1 : - (p->x2 - p->x1);
	b->ey = p->y2 - p->y1 >= 0 ? p->y2 - p->y1 : - (p->y2 - p->y1);
	b->dx = 2 * b->ex;
	b->dy = 2 * b->ey;
	b->Dx = b->ex;
	b->Dy = b->ey;
	b->i = 0;
	b->Xincr = p->x1 >= p->x2 ? -1 : 1;
	b->Yincr = p->y1 >= p->y2 ? -1 : 1;
	return (b);
}

void	ft_line(t_mlx *m, t_pos *p, int z)
{
	t_brs	*b;

	b = init_brs(p);
	while (b->i++ < b->Dx && b->Dx >= b->Dy)
	{
		ft_put_pixels(p->x1, p->y1, m, z);
		p->x1 += b->Xincr;
		b->ex -= b->dy;
		if (b->ex < 0)
		{
			p->y1 += b->Yincr;
			b->ex += b->dx;
		}
	}
	while (b->i++ < b->Dy && b->Dx <= b->Dy)
	{
		ft_put_pixels(p->x1, p->y1, m, z);
		p->y1 += b->Yincr;
		b->ey -= b->dx;
		if (b->ey < 0)
		{
			p->x1 += b->Xincr;
			b->ey += b->dy;
		}
	}
}

void	bresenham_x(t_mlx *m, t_data *file)
{
	int		i;
	t_pos	p;

	while (file)
	{
		i = 0;
		while (i + 1 < file->len)
		{
			p.x1 = i * m->gap - file->tab[i] * m->height;
			p.y1 = (file->y * m->gap - file->tab[i] * m->height);
			p.x2 = (i + 1) * m->gap - file->tab[i + 1] * m->height;
			p.y2 = (file->y * m->gap - file->tab[i + 1] * m->height);
			ft_line(m, &p, file->tab[i]);
			i++;
		}
		file = file->next;
	}
}

void	bresenham_y(t_mlx *m, t_data *file)
{
	int		i;
	t_pos	p;

	while (file)
	{
		i = 0;
		while (i < file->len && file->next)
		{
			p.x1 = i * m->gap - file->tab[i] * m->height;
			p.y1 = (file->y * m->gap - file->tab[i] * m->height);
			p.x2 = i * m->gap - file->next->tab[i] * m->height;
			p.y2 = (file->next->y * m->gap) - file->next->tab[i] * m->height;
			ft_line(m, &p, file->tab[i]);
			i++;
		}
		file = file->next;
	}
}
