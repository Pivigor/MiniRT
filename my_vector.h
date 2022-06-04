/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarlic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:54:11 by jgarlic           #+#    #+#             */
/*   Updated: 2022/02/16 10:54:13 by jgarlic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_VECTOR_H
# define MY_VECTOR_H
# include <math.h>

typedef enum e_direction
{
	Left,
	Right,
	Up,
	Down,
	Forward,
	Backward,
}	t_direction;
typedef struct s_vector2d
{
	int				x;
	int				y;
}				t_vector2d;
typedef struct s_vector2d_float
{
	float			x;
	float			y;
}				t_vector2d_f;
typedef struct s_vector3d
{
	int				x;
	int				y;
	int				z;
}				t_vector3d;
typedef struct s_vector3d_double
{
	double			x;
	double			y;
	double			z;
}				t_vector3d_d;

t_vector3d_d	sum_vecvec(t_vector3d_d a, t_vector3d_d b);
t_vector3d_d	minus_vecvec(t_vector3d_d a, t_vector3d_d b);
t_vector3d_d	mult_vecdouble(t_vector3d_d vec, double num);
double			vector_length(t_vector3d_d vector);
t_vector3d_d	norm_vector(t_vector3d_d vector);

t_vector3d_d	cross_product(t_vector3d_d a, t_vector3d_d b);
double			dot_product(t_vector3d_d a, t_vector3d_d b);
double			scalar_product(t_vector3d_d vector1, t_vector3d_d vector2);

t_vector3d_d	my_get_direction_vector(t_direction direction);
t_vector3d_d	my_rotate_vector_by_axis(t_vector3d_d vector,
					t_vector3d_d axis, double angle);
t_vector3d_d	my_convert_direction_to_rotation(t_vector3d_d orient);
double			my_angle_between_vectors(t_vector3d_d a, t_vector3d_d b);
#endif //MINIRT_MY_VECTOR_H
