/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 04:47:52 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/05 15:09:34 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_ctx.h"

#include <mlx.h>

int	mlx_ctx_init(t_mlx_ctx *mlx)
{
	mlx->ctx = NULL;
	mlx->window = NULL;
	mlx->ctx = mlx_init();
	if (!mlx->ctx)
	{
		mlx_ctx_destroy(mlx);
		return (1);
	}
	mlx->window = mlx_new_window(mlx->ctx,
			WINDOW_DEFAULT_WIDTH, WINDOW_DEFAULT_HEIGHT,
			WINDOW_DEFAULT_TITLE);
	if (!mlx->window)
	{
		mlx_ctx_destroy(mlx);
		return (1);
	}
	return (0);
}

void	mlx_ctx_destroy(t_mlx_ctx *mlx)
{
	if (mlx->window)
		mlx_destroy_window(mlx->ctx, mlx->window);
	if (mlx->ctx)
	{
		mlx_destroy_display(mlx->ctx);
		free(mlx->ctx);
	}
	mlx->window = NULL;
	mlx->ctx = NULL;
}
