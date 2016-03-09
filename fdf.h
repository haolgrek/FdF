/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:32:29 by rluder            #+#    #+#             */
/*   Updated: 2016/03/09 18:49:14 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct		s_fdf
{
	char			*line;
	char			**split;
	int				*tab;
	int				index;
	struct s_fdf	*next;
}					t_fdf;

typedef struct	s_brs
{
	int			ex;
	int			ey;
	int			dx;
	int			dy;
	int			Dx;
	int			Dy;
	int			i;
	int			Xincr;
	int			Yincr;
}				t_brs;

typedef struct	s_pos
{
	int			x1;
	int			y1;
	int			x2;
	int			y2;
}				t_pos;

void	bresenham_x(t_mlx *m, t_file *f);
void	bresenham_y(t_mlx *m, t_file *f);

#endif
