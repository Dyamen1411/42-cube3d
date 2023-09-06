/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 20:59:03 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/07 00:24:39 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <X11/Xlib.h>

#include "c3d.h"

int	main(void)
{
	t_c3d_ctx	*ctx;

	ctx = (t_c3d_ctx *) malloc(sizeof(t_c3d_ctx));
	if (!ctx)
		return (EXIT_FAILURE);
	_memset(ctx, 0, sizeof(t_c3d_ctx));
	if (c3d_ctx_init(ctx))
	{
		free (ctx);
		return (EXIT_FAILURE);
	}
	mlx_hook(ctx->mlx.window.handle, KeyPress, KeyPressMask,
		c3d_hook__key_pressed, ctx);
	mlx_hook(ctx->mlx.window.handle, KeyRelease, KeyReleaseMask,
		c3d_hook__key_released, ctx);
	mlx_loop_hook(ctx->mlx.ctx, c3d_game_loop, ctx);
	mlx_loop(ctx->mlx.ctx);
	c3d_ctx_destroy(ctx);
	free(ctx);
	return (EXIT_SUCCESS);
}
