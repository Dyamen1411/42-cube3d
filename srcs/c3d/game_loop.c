/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:25:44 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/06 10:45:18 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"
#include "mlx_ctx.h"
#include "key_map.h"
#include "renderer.h"

#include <mlx.h>

int	c3d_game_loop(t_c3d_ctx	*ctx)
{
	key_map_process(&ctx->key_map);
	render_world(ctx->world, &ctx->player, ctx);
	c3d_update_window(ctx);
	return (0);
}
