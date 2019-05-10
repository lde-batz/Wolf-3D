/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 16:06:56 by lde-batz          #+#    #+#             */
/*   Updated: 2019/04/11 15:05:09 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_MAP_H
# define MINI_MAP_H

# define MAP_W 200

typedef struct	s_segment
{
	long int	x1;
	long int	y1;
	long int	x2;
	long int	y2;
	long int	dx;
	long int	dy;
	long int	x_inc;
	long int	y_inc;
	long int	cumul;
}				t_segment;

typedef struct	s_wall
{
	double	distance;
	double	h;
	double	wall_x[2];
	double	wall_y[2];
	int		screen_x;
	int		wich;
	double	win;
}				t_wall;

void			ft_print_segment(t_segment *s, t_img *img);

#endif
