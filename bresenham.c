/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:16:23 by rluder            #+#    #+#             */
/*   Updated: 2016/03/07 17:38:18 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	putdata( int x, int y, int *data, int size)
{
	if ((x + y * size) < size * size)
		data[x + y * size] = 0x00FFFF00;
}

void	bresenham(int x1, int y1, int x2, int y2, int *data, int size)
{
	int	dx;
	int	dy;
	int	k;
	int	e;
	int	incx;
	int	incy;
	int	inc1;
	int	inc2;
	int	x;
	int	y;

	dx = x2 - x1;
	dy = y2 - y1;
	if (dx < 0)
		dx = -dx;
	if (dy < 0)
		dy = -dy;
	incx = 1;
	if(x2 < x1)
		incx = -1;
	incy = 1;
	if(y2 < y1)
		incy = -1;
	x = x1;
	y = y1;

	if(dx > dy)
	{
		putdata(x , y, data, size);
		e = 2 * dy - dx;
		inc1 = 2 * ( dy -dx);
		inc2 = 2 * dy;
		k = 0;
		while (k < dx)
		{
			if(e >= 0)
			{
				y += incy;
				e += inc1;
			}
			else
				e += inc2;
			x += incx;
			putdata(x , y, data, size);
			k++;
		}
	}
	else
	{
		putdata(x , y, data, size);
		e = 2 * dx - dy;
		inc1 = 2 * ( dx - dy);
		inc2 = 2 * dx;
		k = 0;
		while(k < dy)
		{
			if(e >= 0)
			{
				x += incx;
				e += inc1;
			}
			else
				e += inc2;
			y += incy;
			putdata(x , y, data, size);
			k++;
		}
	}
}
