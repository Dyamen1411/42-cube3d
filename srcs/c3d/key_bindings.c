/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bindings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:36:33 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/05 16:02:52 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

#include <mlx.h>
#include <stdio.h>

void	quit(void *ptr)
{
	mlx_loop_end(((t_c3d_ctx *) ptr)->mlx.ctx);
}

int	c3d_init_key_map(t_c3d_ctx *ctx)
{
	ctx->key_map.bindings[KEY_BINDING__QUIT_GAME].keycode = 'q';
	ctx->key_map.bindings[KEY_BINDING__QUIT_GAME]
		.key_callback.action[KEY_ACTION__PRESSED].f = quit;
	ctx->key_map.bindings[KEY_BINDING__QUIT_GAME]
		.key_callback.action[KEY_ACTION__PRESSED].arg = ctx;
	return (0);
}
