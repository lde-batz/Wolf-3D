/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 14:57:02 by mfischer          #+#    #+#             */
/*   Updated: 2019/04/11 15:05:25 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct	s_move
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
}				t_move;

typedef struct	s_first_map
{
	unsigned char		*line;
	struct s_first_map	*next;
}				t_first_map;

typedef struct	s_map
{
	double			w;
	double			h;
	unsigned char	**map;
}				t_map;

void			ft_read_map(int fd, t_map *map);
void			ft_quit_read_map(const char *message, t_first_map *save,
					unsigned char *line);

#endif
