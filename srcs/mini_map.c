/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 16:09:02 by lde-batz          #+#    #+#             */
/*   Updated: 2019/04/11 14:48:14 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_clear_mmap(t_win *win, int c)
{
	int		x;
	int		y;
	short	color;

	color = 255;
	while (c++ < 2)
	{
		y = -1;
		while (++y < MAP_W)
		{
			x = -1;
			while (++x < MAP_W * 4)
			{
				if (c == 1)
					win->mmap_back.data[y * win->mmap_back.l + x] = color;
				else
					win->mmap_player.data[y * win->mmap_player.l + x] = color;
			}
			x = 0;
		}
	}
}

void	ft_init_mmap(t_win *win)
{
	ft_new_img(win, &win->mmap_back, mlx_new_image(win->mlx, MAP_W, MAP_W),
		MAP_W);
	win->mmap_back.data = mlx_get_data_addr(win->mmap_back.img_ptr,
		&win->mmap_back.bpp, &win->mmap_back.l, &win->mmap_back.endian);
	ft_new_img(win, &win->mmap_player, mlx_new_image(win->mlx, MAP_W, MAP_W),
		MAP_W);
	win->mmap_player.data = mlx_get_data_addr(win->mmap_player.img_ptr,
		&win->mmap_player.bpp, &win->mmap_player.l, &win->mmap_player.endian);
	ft_clear_mmap(win, 0);
}

void	ft_mmap_player(t_win *win, t_detec *d)
{
	t_segment	s;
	int			len;
	int			block_size;

	len = (win->map.w < win->map.h) ? win->map.h : win->map.w;
	block_size = MAP_W / len;
	s.x1 = (win->cam.x * block_size) - 3;
	s.y1 = (win->cam.y * block_size) - 3;
	s.x2 = (win->cam.x * block_size) + 3;
	s.y2 = (win->cam.y * block_size) + 3;
	ft_print_segment(&s, &win->mmap_player);
	s.x1 = (win->cam.x * block_size) + 3;
	s.y1 = (win->cam.y * block_size) - 3;
	s.x2 -= 6;
	ft_print_segment(&s, &win->mmap_player);
	s.x1 = d->vision[0].x * block_size;
	s.y1 = d->vision[0].y * block_size;
	s.x2 = win->cam.x * block_size;
	s.y2 = win->cam.y * block_size;
	ft_print_segment(&s, &win->mmap_player);
	s.x1 = d->vision[1].x * block_size;
	s.y1 = d->vision[1].y * block_size;
	ft_print_segment(&s, &win->mmap_player);
}

void	ft_mmap_wall(t_win *win, t_img *img, t_detec *d)
{
	short	color;
	int		block_size;
	int		len;

	color = 255;
	len = (win->map.w < win->map.h) ? win->map.h : win->map.w;
	block_size = (MAP_W / len);
	d->txy.x *= block_size;
	d->txy.y *= block_size;
	if (d->txy.x >= img->w)
		d->txy.x = img->w - 1;
	if (d->txy.y >= img->w)
		d->txy.y = img->w - 1;
	if (d->txy.x >= 0 && d->txy.x < img->w
			&& d->txy.y >= 0 && d->txy.y < img->w)
	{
		img->data[(int)(d->txy.y) * img->l + (int)(d->txy.x) * 4] = color;
		img->data[(int)(d->txy.y) * img->l + (int)(d->txy.x) * 4 + 1] = color;
		img->data[(int)(d->txy.y) * img->l + (int)(d->txy.x) * 4 + 2] = color;
		img->data[(int)(d->txy.y) * img->l + (int)(d->txy.x) * 4 + 3] = 0;
	}
}
