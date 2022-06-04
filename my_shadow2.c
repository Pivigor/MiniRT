/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_shadow2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarlic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:27:27 by jgarlic           #+#    #+#             */
/*   Updated: 2022/02/16 10:27:28 by jgarlic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_minirt.h"

t_vector3d_d	cyl1_calc_coeff(t_vector3d_d start, t_cylinder *cylinder,
		t_vector3d_d n)
{
	t_vector3d_d	coeff;
	t_vector3d_d	oc;

	oc = minus_vecvec(start, cylinder->coord);
	coeff.x = scalar_product(n, n)
		- powf(scalar_product(n, cylinder->orient), 2);
	coeff.y = 2 * (scalar_product(n, oc)
			- scalar_product(oc, cylinder->orient)
			* scalar_product(n, cylinder->orient));
	coeff.z = scalar_product(oc, oc)
		- powf(scalar_product(oc, cylinder->orient), 2)
		- powf(cylinder->diameter / 2, 2);
	return (coeff);
}

int	is_hit_cylinder12(t_vector3d_d start, t_cylinder *c,
		t_vector3d_d n, t_vector3d_d d)
{
	if (d.y <= d.z && d.y > 0.01 && d.z > 0.01 && d.y < 1 && d.z < 1)
	{
		c->hit1.x = d.y * n.x + start.x;
		c->hit1.y = d.y * n.y + start.y;
		c->hit1.z = d.y * n.z + start.z;
		c->hit2.x = d.z * n.x + start.x;
		c->hit2.y = d.z * n.y + start.y;
		c->hit2.z = d.z * n.z + start.z;
		if ((d_cyl(c) <= c->height && d_cyl(c) >= 0)
			|| (d_cyl_2(c) <= c->height && d_cyl_2(c) >= 0))
			return (1);
	}
	else if (d.y > d.z && d.y > 0.01 && d.z > 0.01 && d.z < 1 && d.y < 1)
	{
		c->hit1.x = d.z * n.x + start.x;
		c->hit1.y = d.z * n.y + start.y;
		c->hit1.z = d.z * n.z + start.z;
		c->hit2.x = d.y * n.x + start.x;
		c->hit2.y = d.y * n.y + start.y;
		c->hit2.z = d.y * n.z + start.z;
		if ((d_cyl(c) <= c->height && d_cyl(c) >= 0)
			|| (d_cyl_2(c) <= c->height && d_cyl_2(c) >= 0))
			return (1);
	}
	return (0);
}

int	is_hit_cylinder1(t_vector3d_d start, t_cylinder *cylinder, t_vector3d_d n)
{
	t_vector3d_d	coeff;
	t_vector3d_d	d;

	coeff = cyl1_calc_coeff(start, cylinder, n);
	d.x = coeff.y * coeff.y - 4 * coeff.x * coeff.z;
	if (d.x >= 0)
	{
		d.y = (-coeff.y + sqrt(d.x)) / (2 * coeff.x);
		d.z = (-coeff.y - sqrt(d.x)) / (2 * coeff.x);
		return (is_hit_cylinder12(start, cylinder, n, d));
	}
	else
		return (0);
}

int	is_hit_sphere112(t_vector3d_d start, t_sphere *sphere, t_vector3d_d n,
		t_vector3d_d d)
{
	if (d.y <= d.z && d.y > 0.01 && d.z > 0.01 && d.y < 0.99 && d.z < 0.99)
	{
		sphere->hit1.x = d.y * n.x + start.x;
		sphere->hit1.y = d.y * n.y + start.y;
		sphere->hit1.z = d.y * n.z + start.z;
		sphere->hit2.x = d.z * n.x + start.x;
		sphere->hit2.y = d.z * n.y + start.y;
		sphere->hit2.z = d.z * n.z + start.z;
		return (1);
	}
	if (d.y > d.z && d.y > 0.001 && d.z > 0.001 && d.y < 0.99 && d.z < 0.99)
	{
		sphere->hit1.x = d.z * n.x + start.x;
		sphere->hit1.y = d.z * n.y + start.y;
		sphere->hit1.z = d.z * n.z + start.z;
		sphere->hit2.x = d.y * n.x + start.x;
		sphere->hit2.y = d.y * n.y + start.y;
		sphere->hit2.z = d.y * n.z + start.z;
		return (1);
	}
	return (0);
}
