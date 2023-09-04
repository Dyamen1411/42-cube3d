/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:35:04 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/04 12:40:50 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_H
# define C3D_H

# include "mlx_ctx.h"
# include "key_map.h"
# include "player.h"
# include "utils.h"

typedef struct s_c3d_ctx {
	t_mlx_ctx	mlx;
	t_key_map	key_map;
	t_player	player;
}	t_c3d_ctx;

// c3d_ctx_init: Allocates ressources to ctx then initializes ctx.
//   If everything went well, 0 is returned.
//   Else, all the allocated ressources are freed and 1 is returned.
int		c3d_ctx_init(t_c3d_ctx *ctx);

int		c3d_init_key_map(t_c3d_ctx *ctx);

// c3d_ctx_destroy: Liberates all the ressources allocated to ctx.
void	c3d_ctx_destroy(t_c3d_ctx *ctx);

int		c3d_game_loop(t_c3d_ctx	*ctx);

int		c3d_hook__key_pressed(int keycode, t_c3d_ctx *ctx);
int		c3d_hook__key_released(int keycode, t_c3d_ctx *ctx);

#endif