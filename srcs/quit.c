/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:27:08 by lde-batz          #+#    #+#             */
/*   Updated: 2019/04/11 14:48:23 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_quit_read_map(const char *message, t_first_map *save,
		unsigned char *line)
{
	t_first_map	*tmp;

	while (save)
	{
		tmp = save;
		save = save->next;
		free(tmp->line);
		free(tmp);
	}
	if (line)
		free(line);
	ft_putendl(message);
	exit(EXIT_FAILURE);
}

void	ft_quit(const char *message, t_win *win, int nb_exit)
{
	int	i;

	if (nb_exit >= 2)
		mlx_destroy_window(win->mlx, win->win);
	if (win->map.map && nb_exit >= 1)
	{
		i = -1;
		while (++i < win->map.h)
			free(win->map.map[i]);
	}
	ft_putendl(message);
	if (nb_exit < 3)
		exit(EXIT_FAILURE);
}
