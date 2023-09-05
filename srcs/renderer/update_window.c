/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:48:46 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/05 19:22:50 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

#include <mlx.h>

void	c3d_update_window(t_c3d_ctx *ctx)
{
	mlx_put_image_to_window(
		ctx->mlx.ctx, ctx->mlx.window.handle, ctx->mlx.__img,
		0, 0
		);
}
