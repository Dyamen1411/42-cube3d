/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:25:44 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/05 19:35:29 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"
#include "mlx_ctx.h"
#include "key_map.h"

#include <mlx.h>

int	c3d_game_loop(t_c3d_ctx	*ctx)
{
	unsigned int	x;
	unsigned int	y;

	x = (int) ctx->player.x + ctx->mlx.window.width / 2;
	y = (int) ctx->player.y + ctx->mlx.window.height / 2;
	key_map_process(&ctx->key_map);
	ctx->mlx.window.back_buffer[x + ctx->mlx.window.width * y]
		= 0xFFFFFF;
	c3d_update_window(ctx);
	return (0);
}
