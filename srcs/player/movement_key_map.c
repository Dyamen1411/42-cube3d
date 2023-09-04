/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_key_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:14:24 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/04 13:38:02 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

#include "key_map.h"

void	player_callback_move_forward(t_player *player_ptr)
{
	player_move(player_ptr, PLAYER_MOVEMENT_DIRECTION__FORWARD);
}

void	player_callback_move_left(t_player *player_ptr)
{
	player_move(player_ptr, PLAYER_MOVEMENT_DIRECTION__LEFT);
}

void	player_callback_move_backward(t_player *player_ptr)
{
	player_move(player_ptr, PLAYER_MOVEMENT_DIRECTION__BACKWARD);
}

void	player_callback_move_right(t_player *player_ptr)
{
	player_move(player_ptr, PLAYER_MOVEMENT_DIRECTION__RIGHT);
}

int	player_init_movement_key_map(t_player *player_ptr, t_key_map *key_map_ptr)
{
	t_key_binding	*key_binding;

	key_binding = &key_map_ptr->bindings[KEY_BINDING__PLAYER_MOVE__FORWARD];
	__set_status_down_key_binding(key_binding, 'w',
		player_callback_move_forward, player_ptr);
	key_binding = &key_map_ptr->bindings[KEY_BINDING__PLAYER_MOVE__LEFT];
	__set_status_down_key_binding(key_binding, 'a',
		player_callback_move_left, player_ptr);
	key_binding = &key_map_ptr->bindings[KEY_BINDING__PLAYER_MOVE__BACKWARD];
	__set_status_down_key_binding(key_binding, 's',
		player_callback_move_backward, player_ptr);
	key_binding = &key_map_ptr->bindings[KEY_BINDING__PLAYER_MOVE__RIGHT];
	__set_status_down_key_binding(key_binding, 'd',
		player_callback_move_right, player_ptr);
	return (0);
}
