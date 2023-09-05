/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 20:59:03 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/05 16:03:05 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <X11/Xlib.h>

#include "c3d.h"

void	test1(void *ptr)
{
	mlx_loop_end(((t_c3d_ctx *) ptr)->mlx.ctx);
}

void	test2(void *ptr)
{
	(void) ptr;
	printf("caca");
	fflush(stdout);
}

void	test3(void *ptr)
{
	(void) ptr;
	printf("\n");
}

void	test4(void *ptr)
{
	(void) ptr;
	printf("!");
	fflush(stdout);
}

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
	mlx_loop_hook(ctx->mlx.ctx, c3d_game_loop, ctx);
	mlx_hook(ctx->mlx.window, KeyPress, KeyPressMask,
		c3d_hook__key_pressed, ctx);
	mlx_hook(ctx->mlx.window, KeyRelease, KeyReleaseMask,
		c3d_hook__key_released, ctx);
	mlx_loop(ctx->mlx.ctx);
	c3d_ctx_destroy(ctx);
	free(ctx);
	return (EXIT_SUCCESS);
}
