/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 22:25:34 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/05 16:03:35 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>

#include "c3d.h"
#include "mlx_ctx.h"

int	load_world(t_world **world_ptr)
{
	*world_ptr = world_load(0);
	return (*world_ptr == NULL);
}

int	c3d_ctx_init(t_c3d_ctx *ctx)
{
	if (mlx_ctx_init(&ctx->mlx)
		|| key_map_init(&ctx->key_map)
		|| player_init(&ctx->player, &ctx->key_map)
		|| c3d_init_key_map(ctx)
		|| load_world(&ctx->world))
	{
		c3d_ctx_destroy(ctx);
		return (1);
	}
	return (0);
}

void	c3d_ctx_destroy(t_c3d_ctx *ctx)
{
	world_delete(&ctx->world);
	mlx_ctx_destroy(&ctx->mlx);
}
