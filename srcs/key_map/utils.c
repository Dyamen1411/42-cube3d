/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 08:23:23 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/04 08:28:16 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_map.h"

#include "utils.h"

t_key_binding	*__get_binding(t_key_map *key_map_ptr, int keycode)
{
	int	i;

	i = 0;
	while (i < KEY_BINDING_COUNT)
		if (key_map_ptr->bindings[i++].keycode == keycode)
			return (&key_map_ptr->bindings[i - 1]);
	return (NULL);
}
