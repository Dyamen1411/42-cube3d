/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_loader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:07:09 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/06 01:47:02 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	load_header(int fd, t_world *world)
{
	return (read_long(fd, &world->map.width)
		|| read_long(fd, &world->map.height)
		|| read_long(fd, &world->walls.color_count)
	);
}

int	initialize_world_buffers(t_world *world)
{
	unsigned long	layout_size;
	unsigned long	colors_size;

	layout_size = world->map.width * world->map.height * sizeof(char);
	colors_size = world->walls.color_count * sizeof(int);
	world->global_buffer = (char *) malloc(layout_size + colors_size);
	if (world->global_buffer == NULL)
		return (1);
	world->map.layout = (char *)(world->global_buffer);
	world->walls.colors = (int *)(world->global_buffer + layout_size);
	return (0);
}

int	load_layout(int fd, t_world *world)
{
	unsigned long	size;

	size = world->map.width * world->map.height * sizeof(char);
	return (read_n_bytes(fd, world->map.layout, size));
}

int	load_colors(int fd, t_world *world)
{
	unsigned long	count;
	int				*colors;

	count = world->walls.color_count;
	colors = world->walls.colors;
	while (count--)
		if (read_int(fd, colors++))
			return (1);
	return (0);
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
		|| load_colors(fd, world))
		world_delete(&world);
	return (world);
}
