/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:10:33 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/04 13:36:42 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

#include "key_map.h"

int	player_init(t_player *player_ptr, t_key_map *key_map_ptr)
{
	if (player_init_movement_key_map(player_ptr, key_map_ptr))
	{
		player_destroy(player_ptr);
		return (1);
	}
	if (player_init_direction_key_map(player_ptr, key_map_ptr))
	{
		player_destroy(player_ptr);
		return (1);
	}
	player_ptr->x = 0;
	player_ptr->y = 0;
	player_ptr->r = 0;
	player_ptr->move_speed = PLAYER_DEFAULT_MOVE_SPEED;
	player_ptr->rotation_speed = PLAYER_DEFAULT_ROTATION_SPEED;
	return (0);
}

void	player_destroy(t_player *player_ptr)
{
	(void) player_ptr;
}
