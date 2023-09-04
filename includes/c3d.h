/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:35:04 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/04 05:17:28 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_H
# define C3D_H

# include "utils.h"
# include "c3d_mlx.h"
# include "player.h"

typedef struct s_c3d_ctx {
	t_mlx_ctx	mlx;
	t_player	player;
}	t_c3d_ctx;

// ctx_c3d_init: Allocates ressources to ctx then initializes ctx.
//   If everything went well, 0 is returned.
//   Else, all the allocated ressources are freed and 1 is returned.
int		ctx_c3d_init(t_c3d_ctx *ctx);

// ctx_c3d_destroy: Liberates all the ressources allocated to ctx.
void	ctx_c3d_destroy(t_c3d_ctx *ctx);

int		c3d_game_loop(t_c3d_ctx	*ctx);

int		c3d_key_hook(int keycode, t_c3d_ctx	*ctx);

#endif