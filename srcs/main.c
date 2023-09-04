/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 20:59:03 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/04 05:19:38 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>

#include "c3d.h"

int	main(void)
{
	t_c3d_ctx	ctx;

	if (ctx_c3d_init(&ctx))
		return (EXIT_FAILURE);
	mlx_loop_hook(ctx.mlx.ctx, c3d_game_loop, &ctx);
	mlx_key_hook(ctx.mlx.window, c3d_key_hook, &ctx);
	mlx_loop(ctx.mlx.ctx);
	ctx_c3d_destroy(&ctx);
	return (0);
}
