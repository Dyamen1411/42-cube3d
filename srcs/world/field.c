/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:14:29 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/14 17:19:23 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

int	world_is_wall(char *wall_ptr)
{
	return (*wall_ptr != 0);
}

t_field2d	world_as_field(t_world *world)
{
	return ((t_field2d){
		world->map.layout,
		sizeof(*world->map.layout),
		world->map.width,
		world->map.height,
		(int (*)(void *)) world_is_wall
	});
}
