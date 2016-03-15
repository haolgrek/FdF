/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:32:29 by rluder            #+#    #+#             */
/*   Updated: 2016/03/15 10:19:03 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include <stdlib.h>
# include <mlx.h>

typedef struct		s_brs
{
	int				ex;
	int				ey;
	int				dx;
	int				dy;
	int				Dx;
	int				Dy;
	int				i;
	int				Xincr;
	int				Yincr;
}					t_brs;

typedef struct		s_pos
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
}					t_pos;

typedef struct		s_data
{
	int				*tab;
	int				len;
	int				y;
	struct s_data	*next;
}					t_data;

typedef struct		s_mlx
{
	int				gap;
	int				height;
	int				imgx;
	int				imgy;
	void			*mlx;
	void			*win;
	void			*img;
	int				bits;
	int				size;
	int				endian;
	int				*intab;
	int				xsize;
	int				ysize;
	int				maxx;
	int				maxy;
	int				color;
	t_data			*data;
}					t_mlx;

void	bresenham_x(t_mlx *m, t_data *data);
void	bresenham_y(t_mlx *m, t_data *data);
t_data	*parse(char *file);
t_data	*setlst(int fd, char *line);
t_mlx	*init_mlx(t_data *file);
void	other_events(int keycode, t_mlx *m);
int		*fillintab(t_data *file, t_mlx *m, int *intab);
int		*blacktab(t_mlx *m);
int		keys(int keycode, t_mlx *m);

#endif
