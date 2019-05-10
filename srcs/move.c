/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:29:57 by lde-batz          #+#    #+#             */
/*   Updated: 2019/05/01 11:53:04 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_move_w(t_cam *cam, t_map *map)
{
	t_move	m;

	if (cos(cam->rad) <= 0)
		m.x1 = floor(cam->x - COL + (cos(cam->rad) / SPEED));
	else
		m.x1 = floor(cam->x + COL + (cos(cam->rad) / SPEED));
	m.y1 = floor(cam->y - (sin(cam->rad) / SPEED));
	m.x2 = floor(cam->x + (cos(cam->rad) / SPEED));
	if (sin(cam->rad) >= 0)
		m.y2 = floor(cam->y - COL - (sin(cam->rad) / SPEED));
	else
		m.y2 = floor(cam->y + COL - (sin(cam->rad) / SPEED));
	if (m.x1 >= 0 && m.x1 < map->w && m.x2 >= 0 && m.x2 < map->w
			&& map->map[(int)cam->y][m.x1] != '#'
			&& map->map[(int)cam->y][m.x2] != '#')
		cam->x += cos(cam->rad) / SPEED;
	if (m.y1 >= 0 && m.y1 < map->h && m.y2 >= 0 && m.y2 < map->h
			&& map->map[m.y1][(int)cam->x] != '#'
			&& map->map[m.y2][(int)cam->x] != '#')
		cam->y -= sin(cam->rad) / SPEED;
}

void	ft_move_s(t_cam *cam, t_map *map)
{
	t_move m;

	if (cos(cam->rad) <= 0)
		m.x1 = floor(cam->x + COL - (cos(cam->rad) / SPEED));
	else
		m.x1 = floor(cam->x - COL - (cos(cam->rad) / SPEED));
	m.y1 = floor(cam->y + (sin(cam->rad) / SPEED));
	m.x2 = floor(cam->x - (cos(cam->rad) / SPEED));
	if (sin(cam->rad) >= 0)
		m.y2 = floor(cam->y + COL + (sin(cam->rad) / SPEED));
	else
		m.y2 = floor(cam->y - COL + (sin(cam->rad) / SPEED));
	if (m.x1 >= 0 && m.x1 < map->w && m.x2 >= 0 && m.x2 < map->w
			&& map->map[(int)cam->y][m.x1] != '#'
			&& map->map[(int)cam->y][m.x2] != '#')
		cam->x -= cos(cam->rad) / SPEED;
	if (m.y1 >= 0 && m.y1 < map->h && m.y2 >= 0 && m.y2 < map->h
			&& map->map[m.y1][(int)cam->x] != '#'
			&& map->map[m.y2][(int)cam->x] != '#')
		cam->y += sin(cam->rad) / SPEED;
}

void	ft_move_a(t_cam *cam, t_map *map)
{
	t_move m;

	if (cos(cam->rad + M_PI_2) <= 0)
		m.x1 = floor(cam->x - COL + (cos(cam->rad + M_PI_2) / SPEED));
	else
		m.x1 = floor(cam->x + COL + (cos(cam->rad + M_PI_2) / SPEED));
	m.y1 = floor(cam->y - (sin(cam->rad + M_PI_2) / SPEED));
	m.x2 = floor(cam->x + (cos(cam->rad + M_PI_2) / SPEED));
	if (sin(cam->rad + M_PI_2) >= 0)
		m.y2 = floor(cam->y - COL - (sin(cam->rad + M_PI_2) / SPEED));
	else
		m.y2 = floor(cam->y + COL - (sin(cam->rad + M_PI_2) / SPEED));
	if (m.x1 >= 0 && m.x1 < map->w && m.x2 >= 0 && m.x2 < map->w
			&& map->map[(int)cam->y][m.x1] != '#'
			&& map->map[(int)cam->y][m.x2] != '#')
		cam->x += cos(cam->rad + M_PI_2) / SPEED;
	if (m.y1 >= 0 && m.y1 < map->h && m.y2 >= 0 && m.y2 < map->h
			&& map->map[m.y1][(int)cam->x] != '#'
			&& map->map[m.y2][(int)cam->x] != '#')
		cam->y -= sin(cam->rad + M_PI_2) / SPEED;
}

void	ft_move_d(t_cam *cam, t_map *map)
{
	t_move	m;

	if (cos(cam->rad - M_PI_2) <= 0)
		m.x1 = floor(cam->x - COL + (cos(cam->rad - M_PI_2) / SPEED));
	else
		m.x1 = floor(cam->x + COL + (cos(cam->rad - M_PI_2) / SPEED));
	m.y1 = floor(cam->y - (sin(cam->rad - M_PI_2) / SPEED));
	m.x2 = floor(cam->x + (cos(cam->rad - M_PI_2) / SPEED));
	if (sin(cam->rad - M_PI_2) >= 0)
		m.y2 = floor(cam->y - COL - (sin(cam->rad - M_PI_2) / SPEED));
	else
		m.y2 = floor(cam->y + COL - (sin(cam->rad - M_PI_2) / SPEED));
	if (m.x1 >= 0 && m.x1 < map->w && m.x2 >= 0 && m.x2 < map->w
			&& map->map[(int)cam->y][m.x1] != '#'
			&& map->map[(int)cam->y][m.x2] != '#')
		cam->x += cos(cam->rad - M_PI_2) / SPEED;
	if (m.y1 >= 0 && m.y1 < map->h && m.y2 >= 0 && m.y2 < map->h
			&& map->map[m.y1][(int)cam->x] != '#'
			&& map->map[m.y2][(int)cam->x] != '#')
		cam->y -= sin(cam->rad - M_PI_2) / SPEED;
}

void	ft_rota_right(t_win *win)
{
	win->cam.rad = fmod((win->cam.rad - ROTA), PI_X_2);
	if (win->cam.rad < 0)
		win->cam.rad += PI_X_2;
}
