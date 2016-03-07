/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:32:29 by rluder            #+#    #+#             */
/*   Updated: 2016/03/07 12:05:41 by rluder           ###   ########.fr       */
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

#endif
