/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 05:07:19 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/05 18:56:16 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "key_map.h"

# define PLAYER_DEFAULT_MOVE_SPEED 0.1
# define PLAYER_DEFAULT_ROTATION_SPEED 0.01

typedef struct s_player
{
	double	x;
	double	y;
	double	r;
	double	move_speed;
	double	rotation_speed;
}	t_player;

typedef enum e_player_movement_direction {
	PLAYER_MOVEMENT_DIRECTION__FORWARD,
	PLAYER_MOVEMENT_DIRECTION__LEFT,
	PLAYER_MOVEMENT_DIRECTION__BACKWARD,
	PLAYER_MOVEMENT_DIRECTION__RIGHT,
}	t_player_movement_direction;

void	__set_status_down_key_binding(t_key_binding *key_binding, int keycode, 
			void (*f)(t_player *), t_player *arg);

int		player_init(t_player *player_ptr, t_key_map *key_map_ptr);
int		player_init_movement_key_map(t_player *player_ptr,
			t_key_map *key_map_ptr);
int		player_init_direction_key_map(t_player *player_ptr,
			t_key_map *key_map_ptr);

void	player_set_speed(t_player *player_ptr, double move_speed);
void	player_move(t_player *player_ptr, t_player_movement_direction d);
void	player_rotate(t_player *player_ptr, double dr);

void	player_destroy(t_player *player_ptr);

#endif