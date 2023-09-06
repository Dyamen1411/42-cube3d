/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook__key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 05:16:42 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/07 00:24:48 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

#include "key_map.h"

#include <mlx.h>

int	c3d_hook__key_pressed(int keycode, t_c3d_ctx *ctx)
{
	key_map__key_pressed(&ctx->key_map, keycode);
	return (0);
}

int	c3d_hook__key_released(int keycode, t_c3d_ctx *ctx)
{
	key_map__key_released(&ctx->key_map, keycode);
	return (0);
}
