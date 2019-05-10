/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 11:51:52 by lde-batz          #+#    #+#             */
/*   Updated: 2019/04/11 14:48:45 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_bresenham2(t_segment *s, t_img *img)
{
	int		i;
	short	color;

	i = 1;
	color = 255;
	s->cumul = s->dy / 2;
	while (i++ <= s->dy)
	{
		s->y1 += s->y_inc;
		s->cumul += s->dx;
		if (s->cumul >= s->dy)
		{
			s->cumul -= s->dy;
			s->x1 += s->x_inc;
		}
		if (s->x1 >= 0 && s->x1 < img->w && s->y1 >= 0 && s->y1 < img->w)
		{
			(img->data)[(s->y1 * img->l) + (s->x1 * 4)] = 0;
			(img->data)[(s->y1 * img->l) + (s->x1 * 4) + 1] = 0;
			(img->data)[(s->y1 * img->l) + (s->x1 * 4) + 2] = color;
			(img->data)[(s->y1 * img->l) + (s->x1 * 4) + 3] = 0;
		}
	}
}

void	ft_bresenham1b(t_segment *s, t_img *img)
{
	int		i;
	short	color;

	i = -1;
	color = 255;
	s->cumul = s->dx / 2;
	while (i++ <= s->dx)
	{
		s->x1 += s->x_inc;
		s->cumul += s->dy;
		if (s->cumul >= s->dx)
		{
			s->cumul -= s->dx;
			s->y1 += s->y_inc;
		}
		if (s->x1 >= 0 && s->x1 < img->w && s->y1 >= 0 && s->y1 < img->w)
		{
			(img->data)[(s->y1 * img->l) + (s->x1 * 4)] = 0;
			(img->data)[(s->y1 * img->l) + (s->x1 * 4) + 1] = 0;
			(img->data)[(s->y1 * img->l) + (s->x1 * 4) + 2] = color;
			(img->data)[(s->y1 * img->l) + (s->x1 * 4) + 3] = 0;
		}
	}
}

void	ft_bresenham1(t_segment *s, t_img *img)
{
	short	color;

	color = 255;
	if (s->x1 >= 0 && s->x1 < img->w && s->y1 >= 0 && s->y1 < img->w)
	{
		(img->data)[(s->y1 * img->l) + (s->x1 * 4)] = 0;
		(img->data)[(s->y1 * img->l) + (s->x1 * 4) + 1] = 0;
		(img->data)[(s->y1 * img->l) + (s->x1 * 4) + 2] = color;
		(img->data)[(s->y1 * img->l) + (s->x1 * 4) + 3] = 0;
	}
	if (s->dx > s->dy)
		ft_bresenham1b(s, img);
	else
		ft_bresenham2(s, img);
}

void	ft_print_segment(t_segment *s, t_img *img)
{
	s->dx = s->x2 - s->x1;
	s->dy = s->y2 - s->y1;
	s->x_inc = (s->dx > 0) ? 1 : -1;
	s->y_inc = (s->dy > 0) ? 1 : -1;
	s->dx = labs(s->dx);
	s->dy = labs(s->dy);
	ft_bresenham1(s, img);
}
