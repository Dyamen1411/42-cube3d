/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 05:16:42 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/04 05:34:28 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

#include <mlx.h>
#include <stdio.h>

int	c3d_key_hook(int keycode, t_c3d_ctx	*ctx)
{
	if (keycode == 'q')
		mlx_loop_end(ctx->mlx.ctx);
	else if (keycode == 'c')
		mlx_clear_window(ctx->mlx.ctx, ctx->mlx.window);
	return (0);
}
