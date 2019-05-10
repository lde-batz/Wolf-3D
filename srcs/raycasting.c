/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:02:51 by lde-batz          #+#    #+#             */
/*   Updated: 2019/04/11 14:48:30 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_update_screen(t_win *win)
{
	mlx_put_image_to_window(win->mlx, win->win, win->img.img_ptr, 0, 0);
	mlx_put_image_to_window(win->mlx, win->win, win->mmap_back.img_ptr, 0, 0);
	mlx_put_image_to_window(win->mlx, win->win, win->mmap_player.img_ptr, 0, 0);
	mlx_put_image_to_window(win->mlx, win->win,
		win->tex[6 + win->key.w].img_ptr, (WIN_W / 2) - 240, WIN_H - 480);
	ft_clear_mmap(win, 1);
}

void	ft_print_wall(t_win *win, t_detec *d)
{
	int	i;

	d->line = -1;
	while (++d->line < d->size_wall)
	{
		i = d->top + d->line;
		if (i >= 0 && i < WIN_H)
		{
			d->y_wall = ((d->line * BLOCK_SIZE) / d->size_wall);
			(win->img.data)[(i * win->img.l) + (d->col * 4)] =
				(win->tex[d->tex].data)[(d->y_wall * win->tex[d->tex].l)
				+ (d->x_wall * 4)];
			(win->img.data)[(i * win->img.l) + (d->col * 4) + 1] =
				(win->tex[d->tex].data)[(d->y_wall * win->tex[d->tex].l)
				+ (d->x_wall * 4) + 1];
			(win->img.data)[(i * win->img.l) + (d->col * 4) + 2] =
				(win->tex[d->tex].data)[(d->y_wall * win->tex[d->tex].l)
				+ (d->x_wall * 4) + 2];
		}
	}
}

void	ft_print_screen(t_win *win)
{
	t_detec d;

	d.col = -1;
	ft_clear_img(win, &win->img);
	d.rad = fmod((win->cam.rad + PI_6), PI_X_2);
	while (++d.col < WIN_W)
	{
		ft_detec_ver(&d, &win->cam, &win->map);
		ft_detec_hor(&d, &win->cam, &win->map);
		if (d.col == 0 || d.col == WIN_W - 1)
			d.vision[d.col / (WIN_W - 1)] = d.txy;
		ft_mmap_wall(win, &win->mmap_back, &d);
		d.d_true = (d.d_hor < d.d_ver) ? d.d_hor : d.d_ver;
		d.tex = (d.d_hor < d.d_ver) ? d.hor_tex : d.ver_tex;
		d.d_true *= cos(win->cam.rad - d.rad);
		d.size_wall = round((CAM_WIN * BLOCK_SIZE) / (d.d_true * BLOCK_SIZE));
		d.top = win->cam.h - (d.size_wall / 2);
		ft_print_wall(win, &d);
		d.rad = fmod((d.rad - DIF_RAD), PI_X_2);
		if (d.rad < 0)
			d.rad += PI_X_2;
	}
	ft_mmap_player(win, &d);
	ft_update_screen(win);
}
