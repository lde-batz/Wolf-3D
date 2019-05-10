/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 15:37:22 by lde-batz          #+#    #+#             */
/*   Updated: 2019/04/11 14:48:02 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_new_img(t_win *win, t_img *img, void *img_ptr, int w)
{
	if ((img->img_ptr = img_ptr) == NULL)
		ft_quit("Error: error init img or textures no found", win, 2);
	img->bpp = 4;
	img->w = w;
	img->l = w * 4;
}

void	ft_skybox(t_win *win, t_img *img)
{
	int	top;
	int	i;
	int	j;
	int	left;

	top = WIN_H - win->cam.h;
	left = fmod(((win->cam.rad + PI_6) * 7680) / (2 * M_PI), 7680);
	i = -1;
	while (++i < WIN_W)
	{
		j = top;
		while (j < WIN_H)
		{
			(img->data)[((j - top) * win->img.l) + (i * 4)] =
				(win->tex[4].data)[(j * win->tex[4].l) + (left * 4)];
			(img->data)[((j - top) * win->img.l) + (i * 4) + 1] =
				(win->tex[4].data)[(j * win->tex[4].l) + (left * 4) + 1];
			(img->data)[((j - top) * win->img.l) + (i * 4) + 2] =
				(win->tex[4].data)[(j * win->tex[4].l) + (left * 4) + 2];
			j++;
		}
		if (--left < 0)
			left = 7679;
	}
}

void	ft_clear_img(t_win *win, t_img *img)
{
	int		i;
	int		j;
	short	grey;

	grey = 181;
	ft_skybox(win, img);
	i = win->cam.h - 1;
	while (++i < WIN_H)
	{
		j = -1;
		while (++j < img->w)
		{
			(img->data)[(i * img->l) + (j * 4)] = grey;
			(img->data)[(i * img->l) + (j * 4) + 1] = grey;
			(img->data)[(i * img->l) + (j * 4) + 2] = grey;
		}
	}
}
