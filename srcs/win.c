/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 17:51:31 by lde-batz          #+#    #+#             */
/*   Updated: 2019/04/11 14:48:56 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_check_spawn(t_win *win, t_cam *cam, t_map *map)
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	while (y < map->h)
	{
		if (map->map[y][x] == '.')
			break ;
		x++;
		if (x >= map->w)
		{
			x = 0;
			y++;
		}
	}
	if (y >= map->h)
		ft_quit("Error: spawn impossible", win, 1);
	cam->x = (x + 0.42);
	cam->y = (y + 0.42);
}

void	ft_init_win(t_win *win, char **argv)
{
	int	fd;

	if (!(ft_strcmp(argv[1], "/dev/zero")))
		ft_quit("Error: invalid map", win, 0);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_quit("Error: map no found", win, 0);
	ft_read_map(fd, &win->map);
	close(fd);
	ft_check_spawn(win, &win->cam, &win->map);
	win->cam.h = WIN_H / 2;
	win->cam.rad = 0;
	if (!(win->mlx = mlx_init()))
		ft_quit("Error: mlx_init fails", win, 1);
	if (!(win->win = mlx_new_window(win->mlx, WIN_W, WIN_H + 176, "WOLF3D")))
		ft_quit("Error: mlx_new_window fails", win, 1);
	ft_new_img(win, &win->img, mlx_new_image(win->mlx, WIN_W, WIN_H), WIN_W);
	win->img.data = mlx_get_data_addr(win->img.img_ptr, &win->img.bpp,
		&win->img.l, &win->img.endian);
	ft_init_mmap(win);
	ft_init_textures(win);
	ft_print_screen(win);
}
