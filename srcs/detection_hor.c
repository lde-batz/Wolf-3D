/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detection_hor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:30:16 by lde-batz          #+#    #+#             */
/*   Updated: 2019/04/11 14:47:51 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_detec_up(t_detec *d, t_cam *c, t_map *m)
{
	d->hor_tex = 1;
	d->y_c = c->y;
	d->x = c->x + ((c->y - d->y_c) / tan(d->rad));
	while (d->check != 1)
	{
		if (d->x >= 0 && d->x < m->w && d->y_c > 0 && d->y_c < m->h)
		{
			d->x_c = d->x;
			if (m->map[d->y_c - 1][d->x_c] == '#')
				d->check = 1;
			if (d->check != 1)
			{
				d->x += d->x_a;
				d->y_c--;
			}
		}
		else
			d->check = 1;
	}
}

void	ft_detec_down(t_detec *d, t_cam *c, t_map *m)
{
	d->hor_tex = 3;
	d->y_c = c->y;
	d->y_c = (d->y_c == c->y) ? c->y : c->y + 1;
	d->x = c->x - ((d->y_c - c->y) / tan(d->rad));
	while (d->check != 1)
	{
		if (d->x >= 0 && d->x < m->w && d->y_c > 0 && d->y_c < m->h)
		{
			d->x_c = d->x;
			if (m->map[d->y_c][d->x_c] == '#')
				d->check = 1;
			if (d->check != 1)
			{
				d->x -= d->x_a;
				d->y_c++;
			}
		}
		else
			d->check = 1;
	}
}

void	ft_detec_hor(t_detec *d, t_cam *c, t_map *m)
{
	if (fmod(d->rad, M_PI) == M_PI_2)
		d->rad += 0.000000001;
	d->x_a = 1 / tan(d->rad);
	d->check = 0;
	if (d->rad < M_PI)
		ft_detec_up(d, c, m);
	else
		ft_detec_down(d, c, m);
	d->dif_x = d->x - c->x;
	d->dif_y = d->y_c - c->y;
	d->d_hor = sqrt((d->dif_x * d->dif_x) + (d->dif_y * d->dif_y));
	if (d->d_hor < d->d_ver)
	{
		d->x_wall = fmod(d->x, 1) * BLOCK_SIZE;
		d->txy.x = d->x;
		d->txy.y = d->y_c;
	}
}
