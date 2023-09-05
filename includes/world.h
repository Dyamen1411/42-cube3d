/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:53:07 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/05 15:45:53 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

typedef struct s_world {
	struct s_walls {
		unsigned long	color_count;
		int				*colors;
	}	walls;
	struct s_map {
		unsigned long	width;
		unsigned long	height;
		char			*layout;
	} map;
	char	*global_buffer;
}	t_world;

t_world	*world_load(int fd);
void	world_delete(t_world **world);

#endif