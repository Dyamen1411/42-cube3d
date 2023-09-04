/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx_c3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 22:25:34 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/04 05:25:28 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>

#include "c3d.h"
#include "c3d_mlx.h"

int	ctx_c3d_init(t_c3d_ctx *ctx)
{
	if (mlx_ctx_init(&ctx->mlx))
	{
		ctx_c3d_destroy(ctx);
		return (1);
	}
	return (0);
}

void	ctx_c3d_destroy(t_c3d_ctx *ctx)
{
	mlx_ctx_destroy(&ctx->mlx);
}
