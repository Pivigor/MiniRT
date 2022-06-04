/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_vector3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarlic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:28:12 by jgarlic           #+#    #+#             */
/*   Updated: 2022/02/16 10:28:13 by jgarlic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_vector.h"

//  Normalized direction vector
t_vector3d_d	my_get_direction_vector(t_direction direction)
{
	t_vector3d_d	vdirection;

	vdirection.x = 0.f;
	vdirection.y = 0.f;
	vdirection.z = 0.f;
	if (direction == Left)
		vdirection.x = -1.f;
	if (direction == Right)
		vdirection.x = 1.f;
	if (direction == Up)
		vdirection.y = 1.f;
	if (direction == Down)
		vdirection.y = -1.f;
	if (direction == Forward)
		vdirection.z = 1.f;
	if (direction == Backward)
		vdirection.z = -1.f;
	return (vdirection);
}

//  Rotate in any direction on angle in degrees
// ORIGINAL FORMULA
//t_vector3d_d rotated = (vector * cos_theta) + (cross_product(axis, vector)
// * sin_theta) + (axis * dot_product(axis, vector)) * (1 - cos_theta);
t_vector3d_d	my_rotate_vector_by_axis(t_vector3d_d vector,
		t_vector3d_d axis, double angle)
{
	double	theta;
	double	cos_theta;
	double	sin_theta;

	theta = 0.017453292519943 * angle;
	cos_theta = cos(theta);
	sin_theta = sin(theta);
	return (sum_vecvec(sum_vecvec(mult_vecdouble(vector, cos_theta),
				mult_vecdouble(cross_product(axis, vector), sin_theta)),
			mult_vecdouble(mult_vecdouble(axis, dot_product(axis, vector)),
				1 - cos_theta)));
}

//  Convert direction vector to rotator
t_vector3d_d	my_convert_direction_to_rotation(t_vector3d_d orient)
{
	t_vector3d_d	rotation;

	rotation.x = atan2(orient.y, orient.z) * (180.f / M_PI);
	rotation.y = atan2(orient.x,
			sqrt(orient.z * orient.z + orient.y * orient.y)) * (180.f / M_PI);
	rotation.z = 0;
	return (rotation);
}

//  Not tested
double	my_angle_between_vectors(t_vector3d_d a, t_vector3d_d b)
{
	double	dot;
	double	lensq1;
	double	lensq2;

	dot = a.x * b.x + a.y * b.y + a.z * b.z;
	lensq1 = a.x * a.x + a.y * a.y + a.z * a.z;
	lensq2 = b.x * b.x + b.y * b.y + b.z * b.z;
	return (acos(dot / sqrt(lensq1 * lensq2)));
}
