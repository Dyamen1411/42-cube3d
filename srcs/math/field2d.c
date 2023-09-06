/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field2d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 08:09:25 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/07 00:16:59 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_math.h"

#define DIM_X 0
#define DIM_Y 1

typedef struct s_v2d_hit_vars {
	t_vector2d		step;
	t_vector2d		side_dist;
	t_vector2d		dir;
	t_vector2d		delta_dist;
	t_lvector2d		map_pos;
	t_vector2d_hit	h;
	int				side;
}	t_v2d_hit_vars;

void	prepare_dim(const t_oriented_vector2d *ov, t_v2d_hit_vars *v,
	int dim)
{
	(&v->delta_dist.x)[dim] = __DBL_MIN__;
	if ((&v->dir.x)[dim] != 0)
		(&v->delta_dist.x)[dim] = fabsl(1. / (&v->dir.x)[dim]);
	(&v->step.x)[dim] = -1;
	(&v->side_dist.x)[dim] = ((&ov->pos.x)[dim] - (long)(&ov->pos.x)[dim])
		* (&v->delta_dist.x)[dim];
	if ((&v->dir.x)[dim] < 0)
		return ;
	(&v->step.x)[dim] = 1;
	(&v->side_dist.x)[dim] = (&v->delta_dist.x)[dim] - (&v->side_dist.x)[dim];
}

void	init(const t_oriented_vector2d *ov, t_v2d_hit_vars *v)
{
	v->h.hit = 0;
	v->map_pos = (t_lvector2d){ov->pos.x, ov->pos.y};
	v->h = (t_vector2d_hit){0, NULL, 0, {ov->pos.x, ov->pos.y}};
	v->dir = ov->dir;
	prepare_dim(ov, v, DIM_X);
	prepare_dim(ov, v, DIM_Y);
}

t_vector2d_hit	v2d_hit(const t_oriented_vector2d *ov, const t_field2d *field,
	unsigned long max_itr_count)
{
	t_v2d_hit_vars	v;

	init(ov, &v);
	while (!v.h.hit && max_itr_count--)
	{
		v.side = v.side_dist.x >= v.side_dist.y;
		if (v.side_dist.x >= v.side_dist.y)
			v.side = 1;
		else
			v.side = 0;
		(&v.side_dist.x)[v.side] += (&v.delta_dist.x)[v.side];
		(&v.map_pos.x)[v.side] += (&v.step.x)[v.side];
		if (v.map_pos.x < 0 || v.map_pos.x > (long) field->width
			|| v.map_pos.y < 0 || v.map_pos.y > (long) field->height)
			continue ;
		v.h.what = ((char *) field->data) + field->data_size
			* (v.map_pos.x + field->width * v.map_pos.y);
		if (!field->does_hit(v.h.what))
			continue ;
		v.h.hit = 1;
		v.h.distance = (&v.side_dist.x)[v.side] - (&v.delta_dist.x)[v.side];
		v.h.pos = v2d_mul(&v.dir, v.h.distance);
		v.h.pos = v2d_add(&v.h.pos, &ov->pos);
	}
	return (v.h);
}
