/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 14:44:32 by lde-batz          #+#    #+#             */
/*   Updated: 2019/04/11 15:05:34 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# define PI_X_2 M_PI * 2
# define PI_6 M_PI / 6
# define CAM_WIN (WIN_W / 2) / tan(PI_6)
# define DIF_RAD (M_PI / 3) / WIN_W

typedef struct	s_xy
{
	double	x;
	double	y;
}				t_xy;

typedef struct	s_detec
{
	int		col;
	int		line;
	double	x;
	double	y;
	double	x_a;
	double	y_a;
	int		x_c;
	int		y_c;
	double	rad;
	double	dif_x;
	double	dif_y;
	int		ver_tex;
	int		hor_tex;
	int		tex;
	double	d_ver;
	double	d_hor;
	double	d_true;
	char	check;
	int		x_wall;
	int		y_wall;
	int		size_wall;
	int		top;
	t_xy	txy;
	t_xy	vision[2];
}				t_detec;

#endif
