/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:47:45 by lde-batz          #+#    #+#             */
/*   Updated: 2019/04/11 14:48:08 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		ft_key_press(int touch, void *param)
{
	t_win *win;

	win = param;
	if (touch == 53)
		ft_quit("Esc", win, 2);
	if (touch == 13)
		win->key.w = 1;
	if (touch == 0)
		win->key.a = 1;
	if (touch == 1)
		win->key.s = 1;
	if (touch == 2)
		win->key.d = 1;
	if (touch == 126)
		win->key.up = 1;
	if (touch == 125)
		win->key.down = 1;
	if (touch == 123)
		win->key.left = 1;
	if (touch == 124)
		win->key.right = 1;
	return (0);
}

int		ft_key_release(int touch, void *param)
{
	t_win *win;

	win = param;
	if (touch == 13)
		win->key.w = 0;
	if (touch == 0)
		win->key.a = 0;
	if (touch == 1)
		win->key.s = 0;
	if (touch == 2)
		win->key.d = 0;
	if (touch == 126)
		win->key.up = 0;
	if (touch == 125)
		win->key.down = 0;
	if (touch == 123)
		win->key.left = 0;
	if (touch == 124)
		win->key.right = 0;
	return (0);
}

int		ft_move(void *param)
{
	t_win	*win;

	win = param;
	if (win->key.w == 1 && win->key.s == 0)
		ft_move_w(&win->cam, &win->map);
	if (win->key.s == 1 && win->key.w == 0)
		ft_move_s(&win->cam, &win->map);
	if (win->key.a == 1 && win->key.d == 0)
		ft_move_a(&win->cam, &win->map);
	if (win->key.d == 1 && win->key.a == 0)
		ft_move_d(&win->cam, &win->map);
	if (win->key.left == 1 && win->key.right == 0)
		win->cam.rad = fabs(fmod((win->cam.rad + ROTA), PI_X_2));
	if (win->key.right == 1 && win->key.left == 0)
		ft_rota_right(win);
	if (win->key.up == 1 && win->key.down == 0 && win->cam.h < WIN_H)
		win->cam.h += WIN_H / 48;
	if (win->key.down == 1 && win->key.up == 0 && win->cam.h > 0)
		win->cam.h -= WIN_H / 48;
	ft_print_screen(win);
	return (0);
}

int		ft_close(void *param)
{
	t_win	*win;

	win = param;
	ft_quit("Red button", win, 2);
	return (0);
}
