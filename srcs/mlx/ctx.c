/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 04:47:52 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/05 18:46:33 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_ctx.h"

#include <mlx.h>

int	init_back_buffer(t_mlx_ctx *mlx)
{
	int	_;

	mlx->window.back_buffer = NULL;
	mlx->__img = mlx_new_image(mlx->ctx, mlx->window.width, mlx->window.height);
	if (!mlx->__img)
		return (1);
	mlx->window.back_buffer = (int *) mlx_get_data_addr(mlx->__img, &_, &_, &_);
	return (0);
}

int	mlx_ctx_init(t_mlx_ctx *mlx)
{
	_memset(mlx, 0, sizeof(t_mlx_ctx));
	mlx->ctx = mlx_init();
	if (!mlx->ctx)
	{
		mlx_ctx_destroy(mlx);
		return (1);
	}
	mlx->window.handle = mlx_new_window(mlx->ctx,
			WINDOW_DEFAULT_WIDTH, WINDOW_DEFAULT_HEIGHT,
			WINDOW_DEFAULT_TITLE);
	if (!mlx->window.handle)
	{
		mlx_ctx_destroy(mlx);
		return (1);
	}
	mlx->window.width = WINDOW_DEFAULT_WIDTH;
	mlx->window.height = WINDOW_DEFAULT_HEIGHT;
	if (init_back_buffer(mlx))
	{
		mlx_ctx_destroy(mlx);
		return (1);
	}
	return (0);
}

void	mlx_ctx_destroy(t_mlx_ctx *mlx)
{
	if (mlx->__img)
		mlx_destroy_image(mlx->ctx, mlx->__img);
	if (mlx->window.handle)
		mlx_destroy_window(mlx->ctx, mlx->window.handle);
	if (mlx->ctx)
	{
		mlx_destroy_display(mlx->ctx);
		free(mlx->ctx);
	}
	_memset(mlx, 0, sizeof(t_mlx_ctx));
}
