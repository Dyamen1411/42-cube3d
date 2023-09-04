/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 22:25:34 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/04 12:40:48 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>

#include "c3d.h"
#include "mlx_ctx.h"

int	c3d_ctx_init(t_c3d_ctx *ctx)
{
	if (mlx_ctx_init(&ctx->mlx))
	{
		c3d_ctx_destroy(ctx);
		return (1);
	}
	if (key_map_init(&ctx->key_map, ctx))
	{
		c3d_ctx_destroy(ctx);
		return (1);
	}
	if (player_init(&ctx->player, &ctx->key_map))
	{
		c3d_ctx_destroy(ctx);
		return (1);
	}
	if (c3d_init_key_map(ctx))
	{
		c3d_ctx_destroy(ctx);
		return (1);
	}
	return (0);
}

void	c3d_ctx_destroy(t_c3d_ctx *ctx)
{
	mlx_ctx_destroy(&ctx->mlx);
}
