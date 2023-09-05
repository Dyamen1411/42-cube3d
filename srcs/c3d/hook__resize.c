/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook__resize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:10:00 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/05 17:33:37 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

int	c3d_hook__resize(XConfigureEvent *e, t_c3d_ctx *ctx)
{
	if (e->width != (int) ctx->mlx.window.width
		|| e->height != (int) ctx->mlx.window.height)
	{
		ctx->mlx.window.width = e->width;
		ctx->mlx.window.height = e->height;
		return (__mlx_update_back_buffer(&ctx->mlx));
	}
	return (0);
}
