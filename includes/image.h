/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 14:55:13 by mfischer          #+#    #+#             */
/*   Updated: 2019/04/11 15:05:18 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

typedef struct	s_img
{
	void	*img_ptr;
	char	*data;
	int		bpp;
	int		endian;
	int		w;
	int		l;
}				t_img;

#endif
