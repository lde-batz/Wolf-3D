/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 17:31:48 by lde-batz          #+#    #+#             */
/*   Updated: 2019/04/11 15:07:13 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_init_textures2(t_win *win)
{
	int	w;
	int	h;

	w = 1280;
	h = 176;
	ft_new_img(win, &win->tex[5], mlx_xpm_file_to_image(win->mlx,
			"textures/bottom.xpm", &w, &h), w);
	win->tex[5].data = mlx_get_data_addr(win->tex[5].img_ptr, &win->tex[5].bpp,
		&win->tex[5].l, &win->tex[5].endian);
	mlx_put_image_to_window(win->mlx, win->win, win->tex[5].img_ptr,
		0, WIN_H);
	w = 480;
	ft_new_img(win, &win->tex[6], mlx_xpm_file_to_image(win->mlx,
			"textures/gun1.xpm", &w, &w), w);
	win->tex[6].data = mlx_get_data_addr(win->tex[6].img_ptr, &win->tex[6].bpp,
		&win->tex[6].l, &win->tex[6].endian);
	ft_new_img(win, &win->tex[7], mlx_xpm_file_to_image(win->mlx,
			"textures/gun5.xpm", &w, &w), w);
	win->tex[7].data = mlx_get_data_addr(win->tex[7].img_ptr, &win->tex[7].bpp,
		&win->tex[7].l, &win->tex[7].endian);
}

void	ft_init_textures(t_win *win)
{
	int	w;
	int	h;

	w = BLOCK_SIZE;
	ft_new_img(win, &win->tex[0], mlx_xpm_file_to_image(win->mlx,
			"textures/brick.xpm", &w, &w), w);
	ft_new_img(win, &win->tex[1], mlx_xpm_file_to_image(win->mlx,
			"textures/stone.xpm", &w, &w), w);
	ft_new_img(win, &win->tex[2], mlx_xpm_file_to_image(win->mlx,
			"textures/wood.xpm", &w, &w), w);
	ft_new_img(win, &win->tex[3], mlx_xpm_file_to_image(win->mlx,
			"textures/mossy.xpm", &w, &w), w);
	h = -1;
	while (++h < 4)
		win->tex[h].data = mlx_get_data_addr(win->tex[h].img_ptr,
			&win->tex[h].bpp, &win->tex[h].l, &win->tex[h].endian);
	w = 7680;
	h = 720;
	ft_new_img(win, &win->tex[4], mlx_xpm_file_to_image(win->mlx,
			"textures/space_skybox.xpm", &w, &h), w);
	win->tex[4].data = mlx_get_data_addr(win->tex[4].img_ptr, &win->tex[4].bpp,
		&win->tex[4].l, &win->tex[4].endian);
	ft_init_textures2(win);
}
