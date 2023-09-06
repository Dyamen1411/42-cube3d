/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_renderer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:05:45 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/07 00:14:07 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

#include "c3d_math.h"

#include <math.h>

#define MAX_ITR_COUNT 128

void	fill_col(t_mlx_ctx *mlx_ctx, int x, int height, int color)
{
	int	y;
	int	*buffer;

	if (height < 0)
		return ;
	if ((unsigned int) height > mlx_ctx->window.height)
		height = mlx_ctx->window.height;
	height = (height + 1) / 2;
	buffer = mlx_ctx->window.back_buffer;
	buffer += x + mlx_ctx->window.width * mlx_ctx->window.height / 2;
	y = 0;
	while (y < height)
	{
		*(buffer + y * mlx_ctx->window.width) = color;
		*(buffer - y * mlx_ctx->window.width) = color;
		++y;
	}
}

// int	compute_column(t_res *res, t_render_settings *s, t_world *world)
// {
// 	s->map_pos.x = (long) s->pos.x;
// 	s->map_pos.y = (long) s->pos.y;
// 	s->d_dist.x = __DBL_MAX__;
// 	s->d_dist.y = __DBL_MAX__;
// 	prepare_column_computation(s);
// 	res->side = 0;
// 	res->wall_type = 0;
// 	while (!res->wall_type)
// 	{
// 		res->side = s->side_dist.x >= s->side_dist.y;
// 		((double *) &s->side_dist)[res->side]
// 			+= ((double *) &s->d_dist)[res->side];
// 		((long *) &s->map_pos)[res->side]
// 			+= ((double *) &s->step)[res->side];
// 		res->wall_type = world->map.layout
// 		[s->map_pos.x + world->map.width * s->map_pos.y];
// 	}
// 	s->perp_dist = res->side * (s->side_dist.y - s->d_dist.y)
// 		+ (!res->side) * (s->side_dist.x - s->d_dist.x);
// 	res->d = s->perp_dist;
// 	return (1);
// }

int	is_wall(void *data)
{
	return (*((char *) data) != 0);
}

void	generate_field(t_world *world, t_field2d *field)
{
	*field = (t_field2d){
		world->map.layout,
		sizeof(char),
		world->map.width,
		world->map.height,
		is_wall
	};
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

void	render_world(t_world *world, t_player *player, t_c3d_ctx *ctx)
{
	t_vector2d_hit		h;
	t_oriented_vector2d	plane;
	t_field2d			field;
	t_oriented_vector2d	p;
	unsigned long		col;

	generate_field(world, &field);
	prepare_render(player, &plane, &p);
	col = 0;
	while (col < ctx->mlx.window.width)
	{
		p.dir = v2d_mul(&plane.dir,
				2. * col / (double)ctx->mlx.window.width - 1.);
		p.dir = v2d_add(&p.dir, &plane.pos);
		h = v2d_hit(&p, &field, MAX_ITR_COUNT);
		fill_col(&ctx->mlx, col, ctx->mlx.window.height, 0);
		if (h.hit)
			fill_col(&ctx->mlx, col,
				ctx->mlx.window.height / h.distance,
				world->walls.colors[(*((char *) h.what)) - 1]);
		++col;
	}
}
