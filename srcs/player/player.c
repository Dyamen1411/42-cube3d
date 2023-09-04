/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 06:18:05 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/04 13:42:31 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

#include <math.h>
#include <stdio.h>

void	_player_move(t_player *player_ptr, int dx, int dy)
{
	double	c;
	double	s;

	c = cos(player_ptr->r);
	s = sin(player_ptr->r);
	printf("%lf %lf %lf -> ", player_ptr->x, player_ptr->y, player_ptr->r);
	player_ptr->x += player_ptr->move_speed * (dx * c + dy * s);
	player_ptr->y += player_ptr->move_speed * (dy * c - dx * s);
	printf("%lf %lf\n", player_ptr->x, player_ptr->y);
}

void	player_move(t_player *player_ptr, t_player_movement_direction d)
{
	if (d == PLAYER_MOVEMENT_DIRECTION__FORWARD)
		_player_move(player_ptr, 0, -1);
	else if (d == PLAYER_MOVEMENT_DIRECTION__LEFT)
		_player_move(player_ptr, -1, 0);
	else if (d == PLAYER_MOVEMENT_DIRECTION__BACKWARD)
		_player_move(player_ptr, 0, 1);
	else if (d == PLAYER_MOVEMENT_DIRECTION__RIGHT)
		_player_move(player_ptr, 1, 0);
}

void	player_set_speed(t_player *player_ptr, double move_speed)
{
	player_ptr->move_speed = move_speed;
}

void	player_rotate(t_player *player_ptr, double dr)
{
	player_ptr->r += dr;
}
