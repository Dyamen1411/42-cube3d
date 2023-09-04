/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 08:24:49 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/04 10:11:54 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_map.h"

void	key_map__key_pressed(t_key_map *key_map_ptr, int keycode)
{
	t_key_binding	*binding_ptr;

	binding_ptr = __get_binding(key_map_ptr, keycode);
	if (!binding_ptr)
		return ;
	binding_ptr->key_action = KEY_ACTION__PRESSED;
}

void	key_map__key_released(t_key_map *key_map_ptr, int keycode)
{
	t_key_binding	*binding_ptr;

	binding_ptr = __get_binding(key_map_ptr, keycode);
	if (!binding_ptr)
		return ;
	binding_ptr->key_action = KEY_ACTION__RELEASED;
}
