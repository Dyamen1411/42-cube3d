/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_math.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 07:58:58 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/12 18:05:45 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_MATH_H
# define C3D_MATH_H

# include <math.h>
# include <stdlib.h>

typedef struct s_vector2d {
	double	x;
	double	y;
}	t_vector2d;

typedef struct s_lvector2d {
	long	x;
	long	y;
}	t_lvector2d;

typedef struct s_oriented_vector2d {
	t_vector2d	pos;
	t_vector2d	dir;
}	t_oriented_vector2d;

typedef struct s_vector2d_hit {
	int					has_hit;
	void				*what;
	double				distance;
	int					side;
	t_oriented_vector2d	ray;
}	t_vector2d_hit;

typedef struct s_field2d {
	void			*data;
	unsigned long	data_size;
	unsigned long	width;
	unsigned long	height;
	int				(*does_hit)(void *);
}	t_field2d;

t_vector2d		v2d_add(const t_vector2d *v1, const t_vector2d *v2);
t_vector2d		v2d_sub(const t_vector2d *v1, const t_vector2d *v2);
t_vector2d		v2d_mul(const t_vector2d *v, double m);
double			v2d_len(const t_vector2d *v);

t_vector2d_hit	v2d_hit(const t_oriented_vector2d *ov, const t_field2d *field,
					unsigned long max_itr_count);

#endif