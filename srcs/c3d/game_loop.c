/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:25:44 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/05 17:32:25 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"
#include "mlx_ctx.h"
#include "key_map.h"

#include <mlx.h>
#include <stdio.h>

int	c3d_game_loop(t_c3d_ctx	*ctx)
{
	key_map_process(&ctx->key_map);
	mlx_pixel_put(ctx->mlx.ctx, ctx->mlx.window.handle,
		ctx->player.x, ctx->player.y, rand() & 0xFFFFFF);
	return (0);
}
