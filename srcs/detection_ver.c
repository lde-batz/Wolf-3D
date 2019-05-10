/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detection_ver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:50:22 by lde-batz          #+#    #+#             */
/*   Updated: 2019/04/11 14:47:57 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_detec_left(t_detec *d, t_cam *c, t_map *m)
{
	d->ver_tex = 2;
	d->x_c = c->x;
	d->y = c->y + ((c->x - d->x_c) * tan(d->rad));
	while (d->check != 1)
	{
		if (d->x_c > 0 && d->x_c < m->w && d->y >= 0 && d->y < m->h)
		{
			d->y_c = d->y;
			if (m->map[d->y_c][d->x_c - 1] == '#')
				d->check = 1;
			if (d->check != 1)
			{
				d->y += d->y_a;
				d->x_c--;
			}
		}
		else
			d->check = 1;
	}
}

void	ft_detec_right(t_detec *d, t_cam *c, t_map *m)
{
	d->ver_tex = 0;
	d->x_c = c->x;
	d->x_c = (d->x_c == c->x) ? c->x : c->x + 1;
	d->y = c->y - ((d->x_c - c->x) * tan(d->rad));
	while (d->check != 1)
	{
		if (d->x_c > 0 && d->x_c < m->w && d->y >= 0 && d->y < m->h)
		{
			d->y_c = d->y;
			if (m->map[d->y_c][d->x_c] == '#')
				d->check = 1;
			if (d->check != 1)
			{
				d->y -= d->y_a;
				d->x_c++;
			}
		}
		else
			d->check = 1;
	}
}

void	ft_detec_ver(t_detec *d, t_cam *c, t_map *m)
{
	if (fmod(d->rad, M_PI) == M_PI / 2)
		d->rad += 0.000000001;
	d->y_a = 1 * tan(d->rad);
	d->check = 0;
	if (cos(d->rad) <= 0)
		ft_detec_left(d, c, m);
	else
		ft_detec_right(d, c, m);
	d->dif_x = d->x_c - c->x;
	d->dif_y = d->y - c->y;
	d->x_wall = fmod(d->y, 1) * BLOCK_SIZE;
	d->d_ver = sqrt((d->dif_x * d->dif_x) + (d->dif_y * d->dif_y));
	d->txy.x = d->x_c;
	d->txy.y = d->y;
}
