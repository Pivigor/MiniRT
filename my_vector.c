/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarlic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:27:54 by jgarlic           #+#    #+#             */
/*   Updated: 2022/02/16 10:27:57 by jgarlic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_vector.h"

//  Sum: vector + vector
t_vector3d_d	sum_vecvec(t_vector3d_d a, t_vector3d_d b)
{
	t_vector3d_d	sum;

	sum.x = a.x + b.x;
	sum.y = a.y + b.y;
	sum.z = a.z + b.z;
	return (sum);
}

//  Subtraction: vector - vector
t_vector3d_d	minus_vecvec(t_vector3d_d a, t_vector3d_d b)
{
	t_vector3d_d	res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	return (res);
}

//  Multiply each coord on value (double): vector * num
t_vector3d_d	mult_vecdouble(t_vector3d_d vec, double num)
{
	t_vector3d_d	res;

	res.x = vec.x * num;
	res.y = vec.y * num;
	res.z = vec.z * num;
	return (res);
}

//  Vector length
double	vector_length(t_vector3d_d vector)
{
	return (sqrt(vector.x * vector.x + vector.y * vector.y
			+ vector.z * vector.z));
}

//  Normalized vector (length = 1)
t_vector3d_d	norm_vector(t_vector3d_d vector)
{
	t_vector3d_d	res;
	float			len_vec;

	len_vec = vector_length(vector);
	res.x = vector.x / len_vec;
	res.y = vector.y / len_vec;
	res.z = vector.z / len_vec;
	return (res);
}
