/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_loader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:07:09 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/12 16:10:23 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

#include "utils.h"

#include <stdlib.h>
#include <unistd.h>

int	load_header(int fd, t_world *world)
{
	return (read_long(fd, &world->map.width)
		|| read_long(fd, &world->map.height)
		|| read_long(fd, &world->textures.count)
	);
}

int	initialize_world_buffers(t_world *world)
{
	unsigned long	layout_size;
	unsigned long	texture_size;

	layout_size = world->map.width * world->map.height * sizeof(char);
	texture_size = world->textures.count * sizeof(t_texture);
	world->global_buffer = (char *) malloc(layout_size + texture_size);
	if (world->global_buffer == NULL)
		return (1);
	world->map.layout = (char *)(world->global_buffer);
	world->textures.list = (t_texture *)(world->global_buffer + layout_size);
	return (0);
}

int	load_layout(int fd, t_world *world)
{
	unsigned long	size;

	size = world->map.width * world->map.height * sizeof(char);
	return (read_n_bytes(fd, world->map.layout, size));
}

int	load_textures(int fd, t_world *world)
{
	unsigned long	size;

	size = world->textures.count * sizeof(t_texture);
	return (read_n_bytes(fd, world->textures.list, size));
}

t_world	*world_load(int fd)
{
	t_world	*world;

	world = (t_world *) malloc(sizeof(t_world));
	if (!world)
		return (NULL);
	_memset(world, 0, sizeof(t_world));
	if (load_header(fd, world)
		|| initialize_world_buffers(world)
		|| load_layout(fd, world)
		|| load_textures(fd, world))
		world_delete(&world);
	return (world);
}
