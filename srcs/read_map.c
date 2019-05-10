/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 11:15:16 by lde-batz          #+#    #+#             */
/*   Updated: 2019/04/11 14:48:38 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_first_map	*ft_new_line(t_first_map *save, unsigned char *line, t_map *map)
{
	t_first_map *new;
	t_first_map	*last;

	map->h++;
	if (!(new = (t_first_map*)malloc(sizeof(t_first_map))))
		ft_quit_read_map("Error: srcs/read_map.c:22 don't malloc", save, line);
	last = save;
	new->line = line;
	new->next = NULL;
	if (save)
	{
		while (last->next)
			last = last->next;
		last->next = new;
	}
	return (new);
}

void		ft_check_line(char *line, t_map *map, t_first_map *save)
{
	int	i;
	int	len;

	len = ft_strlen(line);
	if (len != map->w)
		ft_quit_read_map("Error : map isn't a rectangle", save, NULL);
	i = -1;
	while (++i < len)
		if (line[i] != '.' && line[i] != '#')
			ft_quit_read_map("Error : map must consist of '#' and '.'", save,
				NULL);
}

void		ft_put_in_map(t_map *map, t_first_map *m)
{
	int			i;
	t_first_map *last;

	i = 0;
	while (m)
	{
		last = m;
		map->map[i] = m->line;
		m = m->next;
		free(last);
		i++;
	}
}

void		ft_read_map(int fd, t_map *map)
{
	char		*line;
	t_first_map *new;
	t_first_map *save;

	save = NULL;
	map->h = 0;
	while (get_next_line(fd, &line))
	{
		if (!line[0])
			break ;
		new = ft_new_line(save, (unsigned char*)line, map);
		if (!save)
		{
			map->w = ft_strlen(line);
			save = new;
		}
		ft_check_line(line, map, save);
	}
	if (!(map->map = (unsigned char**)malloc(sizeof(unsigned char*) * map->h)))
		ft_quit_read_map("Error: srcs/read_map.c:88 don't malloc", save, NULL);
	ft_put_in_map(map, save);
}
