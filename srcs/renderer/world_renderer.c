/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_renderer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:05:45 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/14 19:32:57 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

#include "c3d_math.h"

#include <math.h>

#define MAX_ITR_COUNT 128

void	fill_col(t_mlx_ctx *mlx_ctx, int x, int height, int *texture)
{
	long	y;
	int		*buffer;
	long	wall_start;
	long	wall_end;

	height = clamp(height, 0, mlx_ctx->window.height - 1);
	wall_start = (mlx_ctx->window.height - height) / 2;
	wall_end = (mlx_ctx->window.height + height) / 2;
	wall_start = clamp(wall_start, 0, mlx_ctx->window.height - 1);
	wall_end = clamp(wall_end, 0, mlx_ctx->window.height - 1);
	buffer = mlx_ctx->window.back_buffer + x;
	y = 0;
	while (y < mlx_ctx->window.height)
	{
		if (wall_start <= y && y < wall_end)
			*buffer = texture[(long)((TEXTURE_HEIGHT - 1)
					* ((double)(y - wall_start)
						/ (double)(wall_end - wall_start - 1)))];
		else
			*buffer = 0;
		buffer += mlx_ctx->window.width;
		++y;
	}
}

void	prepare_render(t_player *player,
	t_oriented_vector2d *plane, t_oriented_vector2d *p)
{
	*plane = (t_oriented_vector2d){
	{cos(player->r), sin(player->r)},
	{-sin(player->r), cos(player->r)}
	};
	plane->dir = v2d_mul(&plane->dir, tan(player->fov / 2.));
	p->pos = (t_vector2d){player->x, player->y};
}

int	*compute_texture_offset(t_world *world, t_player *player,
	t_vector2d_hit *hit)
{
	int		*buf;
	double	wallx;
	long	texx;

	wallx = (&player->x)[1 - hit->side]
		+ hit->distance * (&hit->ray.dir.x)[1 - hit->side];
	wallx -= floor(wallx);
	texx = (long)(wallx * TEXTURE_WIDTH);
	if ((hit->side || hit->ray.dir.x <= 0)
		&& (!hit->side || hit->ray.dir.y >= 0))
		texx = TEXTURE_WIDTH - texx - 1;
	buf = world->textures.list[(*((char *) hit->what)) - 1].data[texx];
	return (buf);
}

void	render_world(t_world *world, t_player *player_ptr, t_c3d_ctx *ctx)
{
	t_field2d			field;
	t_vector2d_hit		hit;
	t_oriented_vector2d	player;
	t_oriented_vector2d	plane;
	unsigned long		col;

	prepare_render(player_ptr, &plane, &player);
	field = world_as_field(world);
	col = 0;
	while (col < ctx->mlx.window.width)
	{
		player.dir = v2d_mul(&plane.dir,
				2. * col / (double)ctx->mlx.window.width - 1.);
		player.dir = v2d_add(&player.dir, &plane.pos);
		hit = v2d_hit(&player, &field, MAX_ITR_COUNT);
		if (hit.has_hit)
			fill_col(&ctx->mlx, col,
				ctx->mlx.window.height / hit.distance,
				compute_texture_offset(world, player_ptr, &hit));
		++col;
	}
}
