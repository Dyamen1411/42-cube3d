/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:53:07 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/14 17:19:39 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "c3d_math.h"

# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64

typedef struct s_texture {
	int	data[TEXTURE_WIDTH][TEXTURE_HEIGHT];
}	t_texture;

typedef struct s_world {
	struct s_textures {
		unsigned long	count;
		t_texture		*list;
	}	textures;
	struct s_map {
		unsigned long	width;
		unsigned long	height;
		char			*layout;
	} map;
	char	*global_buffer;
}	t_world;

t_world		*world_load(int fd);
t_field2d	world_as_field(t_world *world);
int			world_is_wall(char *wall_ptr);
void		world_delete(t_world **world);

#endif