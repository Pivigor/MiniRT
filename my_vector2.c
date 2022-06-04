/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_vector2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarlic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:28:04 by jgarlic           #+#    #+#             */
/*   Updated: 2022/02/16 10:28:05 by jgarlic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_vector.h"

t_vector3d_d	cross_product(t_vector3d_d a, t_vector3d_d b)
{
	t_vector3d_d	cross;

	cross.x = a.y * b.z - a.z * b.y;
	cross.y = a.z * b.x - a.x * b.z;
	cross.z = a.x * b.y - a.y * b.x;
	return (cross);
}

double	dot_product(t_vector3d_d a, t_vector3d_d b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

double	scalar_product(t_vector3d_d vector1, t_vector3d_d vector2)
{
	return (vector1.x * vector2.x + vector1.y * vector2.y
		+ vector1.z * vector2.z);
}
