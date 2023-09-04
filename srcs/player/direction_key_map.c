/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_key_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:44:20 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/04 13:45:03 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

#include <stdio.h>

void	player_callback_rotate_right(t_player *player_ptr)
{
	player_ptr->r -= player_ptr->rotation_speed;
}

void	player_callback_rotate_left(t_player *player_ptr)
{
	player_ptr->r += player_ptr->rotation_speed;
}

int	player_init_direction_key_map(t_player *player_ptr, t_key_map *key_map_ptr)
{
	t_key_binding	*key_binding;

	key_binding = &key_map_ptr->bindings[KEY_BINDING__PLAYER_ROTATE__RIGHT];
	__set_status_down_key_binding(key_binding, KEY_RIGHT,
		player_callback_rotate_right, player_ptr);
	key_binding = &key_map_ptr->bindings[KEY_BINDING__PLAYER_ROTATE__LEFT];
	__set_status_down_key_binding(key_binding, KEY_LEFT,
		player_callback_rotate_left, player_ptr);
	return (0);
}
