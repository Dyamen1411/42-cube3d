/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 06:44:32 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/04 12:30:11 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_map.h"

void	key_map_process(t_key_map *key_map_ptr)
{
	int				i;
	t_key_binding	*binding_ptr;

	i = 0;
	while (i < KEY_BINDING_COUNT)
	{
		binding_ptr = &key_map_ptr->bindings[i++];
		if (binding_ptr->key_action != KEY_ACTION__NONE)
		{
			if (binding_ptr->key_callback.action[binding_ptr->key_action].f)
				binding_ptr->key_callback.action[binding_ptr->key_action].f(
					binding_ptr->key_callback.action[binding_ptr->key_action]
					.arg);
			if (binding_ptr->key_action == KEY_ACTION__RELEASED)
				binding_ptr->key_status = KEY_STATUS__UP;
			if (binding_ptr->key_action == KEY_ACTION__PRESSED)
				binding_ptr->key_status = KEY_STATUS__DOWN;
			binding_ptr->key_action = KEY_ACTION__NONE;
		}
		else if (binding_ptr->key_callback.status[binding_ptr->key_status].f)
			binding_ptr->key_callback.status[binding_ptr->key_status].f(
				binding_ptr->key_callback.status[binding_ptr->key_status].arg);
	}
}
