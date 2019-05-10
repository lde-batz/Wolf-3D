/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 17:49:24 by lde-batz          #+#    #+#             */
/*   Updated: 2019/04/11 14:39:12 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	main(int argc, char **argv)
{
	t_win	win;

	if (argc != 2)
		ft_quit("Usage : ./wolf3d map", &win, 0);
	ft_init_win(&win, argv);
	mlx_hook(win.win, 2, 0, ft_key_press, &win);
	mlx_hook(win.win, 3, 0, ft_key_release, &win);
	mlx_hook(win.win, 17, 0, ft_close, &win);
	mlx_loop_hook(win.mlx, ft_move, &win);
	mlx_loop(win.mlx);
	ft_quit("End", &win, 3);
	return (0);
}
