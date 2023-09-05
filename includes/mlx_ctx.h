/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ctx.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 04:49:05 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/05 17:19:35 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_CTX_H
# define MLX_CTX_H

# include "utils.h"

# define WINDOW_DEFAULT_WIDTH 1600
# define WINDOW_DEFAULT_HEIGHT 900
# define WINDOW_DEFAULT_TITLE "cube 3d"

typedef struct s_mlx_ctx {
	void	*ctx;
	void	*__img;
	struct s_window {
		unsigned int	width;
		unsigned int	height;
		void			*handle;
		int				*back_buffer;
	}		window;
}	t_mlx_ctx;

// mlx_ctx_init: Allocates ressources to mlx then initializes mlx.
//   If everything went well, 0 is returned.
//   Else, all the allocated ressources are freed and 1 is returned.
int		mlx_ctx_init(t_mlx_ctx *mlx);

int		__mlx_update_back_buffer(t_mlx_ctx *mlx);

// mlx_ctx_destroy: Liberates all the ressources allocated to mlx.
void	mlx_ctx_destroy(t_mlx_ctx *mlx);

#endif