/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 14:44:12 by mfischer          #+#    #+#             */
/*   Updated: 2019/04/11 15:05:47 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>

# include "libft.h"
# include "map.h"
# include "image.h"
# include "raycasting.h"
# include "mini_map.h"

# define WIN_W 1280
# define WIN_H 720
# define BLOCK_SIZE 64
# define ROTA M_PI / 80
# define SPEED 10
# define COL 0.2

typedef struct	s_cam
{
	double	x;
	double	y;
	int		h;
	double	rad;
}				t_cam;

typedef struct	s_key
{
	char	w;
	char	a;
	char	s;
	char	d;
	char	up;
	char	down;
	char	left;
	char	right;
}				t_key;

typedef struct	s_win
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_img		mmap_back;
	t_img		mmap_player;
	t_img		tex[8];
	t_map		map;
	t_cam		cam;
	t_key		key;
}				t_win;

void			ft_init_win(t_win *win, char **argv);
void			ft_init_mmap(t_win *win);
void			ft_new_img(t_win *win, t_img *img, void *img_ptr, int w);
void			ft_clear_img(t_win *win, t_img *img);
void			ft_clear_mmap(t_win *win, int c);
void			ft_init_textures(t_win *win);
void			ft_print_screen(t_win *win);
void			ft_detec_hor(t_detec *d, t_cam *c, t_map *m);
void			ft_detec_ver(t_detec *d, t_cam *c, t_map *m);
void			ft_mmap_wall(t_win *win, t_img *img, t_detec *d);
void			ft_mmap_player(t_win *win, t_detec *d);
int				ft_key_press(int touch, void *param);
int				ft_key_release(int touch, void *param);
int				ft_move(void *param);
int				ft_close(void *param);
void			ft_move_w(t_cam *cam, t_map *map);
void			ft_move_s(t_cam *cam, t_map *map);
void			ft_move_a(t_cam *cam, t_map *map);
void			ft_move_d(t_cam *cam, t_map *map);
void			ft_rota_right(t_win *win);
void			ft_quit(const char *message, t_win *win, int exit);

#endif
