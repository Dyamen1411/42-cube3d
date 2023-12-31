/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 08:22:19 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/05 15:05:59 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_map.h"

#include "utils.h"

int	key_map_init(t_key_map *key_map_ptr)
{
	int				i;
	t_key_binding	*binding_ptr;

	i = 0;
	binding_ptr = key_map_ptr->bindings;
	while (i < KEY_BINDING_COUNT)
	{
		_memset(&binding_ptr[i], 0,
			sizeof(t_key_binding));
		binding_ptr[i].key_status = KEY_STATUS__UP;
		binding_ptr[i].key_action = KEY_ACTION__NONE;
		++i;
	}
	return (0);
}
