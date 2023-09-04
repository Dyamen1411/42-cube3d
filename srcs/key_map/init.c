/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 08:22:19 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/04 12:28:47 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_map.h"

#include "utils.h"

int	key_map_init(t_key_map *key_map_ptr, void *arg)
{
	int				i;
	t_key_binding	*binding_ptr;

	i = 0;
	key_map_ptr->arg = arg;
	binding_ptr = key_map_ptr->bindings;
	while (i < KEY_BINDING_COUNT)
	{
		binding_ptr->keycode = '\0';
		binding_ptr->key_status = KEY_STATUS__UP;
		binding_ptr->key_action = KEY_ACTION__NONE;
		binding_ptr->key_callback.action[KEY_ACTION__RELEASED].f = NULL;
		binding_ptr->key_callback.action[KEY_ACTION__RELEASED].arg = NULL;
		binding_ptr->key_callback.action[KEY_ACTION__PRESSED].f = NULL;
		binding_ptr->key_callback.action[KEY_ACTION__PRESSED].arg = NULL;
		binding_ptr->key_callback.status[KEY_STATUS__UP].f = NULL;
		binding_ptr->key_callback.status[KEY_STATUS__UP].arg = NULL;
		binding_ptr->key_callback.status[KEY_STATUS__DOWN].f = NULL;
		binding_ptr->key_callback.status[KEY_STATUS__DOWN].arg = NULL;
		++binding_ptr;
		++i;
	}
	return (0);
}
