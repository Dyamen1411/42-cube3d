/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 06:24:30 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/04 13:35:52 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_MAP_H
# define KEY_MAP_H

# define KEY_LEFT 65361
# define KEY_RIGHT 65363

typedef enum e_key_status {
	KEY_STATUS__UP,
	KEY_STATUS__DOWN,
	KEY_STATUS_COUNT,
}	t_key_status;

typedef enum e_key_action {
	KEY_ACTION__RELEASED,
	KEY_ACTION__PRESSED,
	KEY_ACTION_COUNT,
	KEY_ACTION__NONE,
}	t_key_action;

typedef enum e_key_binding_name {
	KEY_BINDING__QUIT_GAME,
	KEY_BINDING__PLAYER_MOVE__FORWARD,
	KEY_BINDING__PLAYER_MOVE__BACKWARD,
	KEY_BINDING__PLAYER_MOVE__LEFT,
	KEY_BINDING__PLAYER_MOVE__RIGHT,
	KEY_BINDING__PLAYER_ROTATE__RIGHT,
	KEY_BINDING__PLAYER_ROTATE__LEFT,
	KEY_BINDING_COUNT,
}	t_key_binding_name;

typedef struct s_key_callback_fun {
	void	(*f)(void *);
	void	*arg;
}	t_key_callback_fun;

typedef struct s_key_binding {
	int				keycode;
	t_key_status	key_status;
	t_key_action	key_action;
	struct s_key_callback {
		t_key_callback_fun	action[KEY_ACTION_COUNT];
		t_key_callback_fun	status[KEY_STATUS_COUNT];
	}				key_callback;
}	t_key_binding;

typedef struct s_key_map {
	t_key_binding	bindings[KEY_BINDING_COUNT];
	void			*arg;
}	t_key_map;

t_key_binding	*__get_binding(t_key_map *key_map_ptr, int keycode);
int				key_map_init(t_key_map *key_map_ptr, void *arg);
void			key_map_process(t_key_map *key_map_ptr);
void			key_map__key_pressed(t_key_map *key_map_ptr, int keycode);
void			key_map__key_released(t_key_map *key_map_ptr, int keycode);

#endif