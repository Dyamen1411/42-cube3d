/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:12:25 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/04 12:31:52 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	__set_status_down_key_binding(t_key_binding *key_binding, int keycode,
	void (*f)(t_player *), t_player *arg)
{
	key_binding->keycode = keycode;
	key_binding->key_callback.status[KEY_STATUS__DOWN].f = (void (*)(void *)) f;
	key_binding->key_callback.status[KEY_STATUS__DOWN].arg
		= arg;
}
