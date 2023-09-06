/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 08:07:43 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/06 08:52:44 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_math.h"

double	v2d_len(const t_vector2d *v)
{
	return (sqrt(v->x * v->x + v->y * v->y));
}

t_vector2d	v2d_add(const t_vector2d *v1, const t_vector2d *v2)
{
	return ((t_vector2d){v1->x + v2->x, v1->y + v2->y});
}

t_vector2d	v2d_sub(const t_vector2d *v1, const t_vector2d *v2)
{
	return ((t_vector2d){v1->x - v2->x, v1->y - v2->y});
}

t_vector2d	v2d_mul(const t_vector2d *v, double m)
{
	return ((t_vector2d){v->x * m, v->y * m});
}
