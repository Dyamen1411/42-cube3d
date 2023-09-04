/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:25:44 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/04 05:33:33 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"
#include "c3d_mlx.h"

#include <mlx.h>
#include <stdio.h>

int	c3d_game_loop(t_c3d_ctx	*ctx)
{
	mlx_pixel_put(ctx->mlx.ctx, ctx->mlx.window,
		rand() % WINDOW_DEFAULT_WIDTH, rand() % WINDOW_DEFAULT_HEIGHT,
		rand() & 0xFFFFFF);
	return (0);
}
