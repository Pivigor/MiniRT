/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_manager_render_cyl3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarlic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:25:15 by jgarlic           #+#    #+#             */
/*   Updated: 2022/02/16 10:25:16 by jgarlic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_minirt.h"

double	d_cyl(t_cylinder *cylinder)
{
	t_vector3d_d	dir;
	t_vector3d_d	d;
	double			radius;
	double			p;

	d.x = cylinder->hit1.x - cylinder->coord.x;
	d.y = cylinder->hit1.y - cylinder->coord.y;
	d.z = cylinder->hit1.z - cylinder->coord.z;
	radius = cylinder->diameter / 2;
	dir = minus_vecvec(cylinder->hit1, cylinder->coord);
	p = sqrt(d.x * d.x + d.y * d.y + d.z * d.z - radius * radius);
	if (scalar_product(dir, cylinder->orient) < 0)
		p *= -1;
	return (p);
}

double	d_cyl_2(t_cylinder *cylinder)
{
	t_vector3d_d	dir;
	t_vector3d_d	d;
	double			radius;
	double			p;

	d.x = cylinder->hit2.x - cylinder->coord.x;
	d.y = cylinder->hit2.y - cylinder->coord.y;
	d.z = cylinder->hit2.z - cylinder->coord.z;
	radius = cylinder->diameter / 2;
	dir = minus_vecvec(cylinder->hit2, cylinder->coord);
	p = sqrt(d.x * d.x + d.y * d.y + d.z * d.z - radius * radius);
	if (scalar_product(dir, cylinder->orient) < 0)
		p *= -1;
	return (p);
}
