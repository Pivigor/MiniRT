/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_manager_render_cyl.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarlic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:25:00 by jgarlic           #+#    #+#             */
/*   Updated: 2022/02/16 10:25:01 by jgarlic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_minirt.h"

t_vector3d_d	cyl_calc_coeff(t_camera *camera, t_cylinder *cylinder,
		t_vector3d_d n)
{
	t_vector3d_d	coeff;
	t_vector3d_d	oc;

	oc = minus_vecvec(camera->coord, cylinder->coord);
	coeff.x = scalar_product(n, n) - powf(
			scalar_product(n, cylinder->orient), 2);
	coeff.y = 2 * (scalar_product(n, oc)
			- scalar_product(oc, cylinder->orient)
			* scalar_product(n, cylinder->orient));
	coeff.z = scalar_product(oc, oc)
		- powf(scalar_product(oc, cylinder->orient), 2)
		- powf(cylinder->diameter / 2, 2);
	return (coeff);
}

int	is_hit_cylinder2(t_camera *camera, t_cylinder *c,
		t_vector3d_d d, t_vector3d_d n)
{
	if (d.y < d.z && d.y > 0 && d.z > 0)
	{
		c->hit1.x = d.y * n.x + camera->coord.x;
		c->hit1.y = d.y * n.y + camera->coord.y;
		c->hit1.z = d.y * n.z + camera->coord.z;
		c->hit2.x = d.z * n.x + camera->coord.x;
		c->hit2.y = d.z * n.y + camera->coord.y;
		c->hit2.z = d.z * n.z + camera->coord.z;
		if ((d_cyl(c) <= c->height && d_cyl(c) >= 0)
			|| (d_cyl_2(c) <= c->height && d_cyl_2(c) >= 0))
			return (1);
	}
	else if (d.y > d.z && d.y > 0 && d.z > 0)
	{
		c->hit1.x = d.z * n.x + camera->coord.x;
		c->hit1.y = d.z * n.y + camera->coord.y;
		c->hit1.z = d.z * n.z + camera->coord.z;
		c->hit2.x = d.y * n.x + camera->coord.x;
		c->hit2.y = d.y * n.y + camera->coord.y;
		c->hit2.z = d.y * n.z + camera->coord.z;
		if ((d_cyl(c) <= c->height && d_cyl(c) >= 0)
			|| (d_cyl_2(c) <= c->height && d_cyl_2(c) >= 0))
			return (1);
	}
	return (0);
}

int	is_hit_cylinder3(t_camera *camera, t_cylinder *cylinder, t_vector3d_d n,
		double t)
{
	cylinder->hit1.x = t * n.x + camera->coord.x;
	cylinder->hit1.y = t * n.y + camera->coord.y;
	cylinder->hit1.z = t * n.z + camera->coord.z;
	if (d_cyl(cylinder) <= cylinder->height && d_cyl(cylinder) >= 0)
		return (1);
	else
		return (0);
}

int	is_hit_cylinder(t_camera *camera, t_cylinder *cylinder, t_vector3d_d n)
{
	t_vector3d_d	coeff;
	t_vector3d_d	d;

	coeff = cyl_calc_coeff(camera, cylinder, n);
	d.x = coeff.y * coeff.y - 4 * coeff.x * coeff.z;
	if (d.x > 0)
	{
		d.y = (-coeff.y + sqrt(d.x)) / (2 * coeff.x);
		d.z = (-coeff.y - sqrt(d.x)) / (2 * coeff.x);
		return (is_hit_cylinder2(camera, cylinder, d, n));
	}
	else if (d.x == 0)
		return (is_hit_cylinder3(camera, cylinder, n,
				(-coeff.y + sqrt(d.x)) / (2 * coeff.x)));
	else
		return (0);
}

int	my_render_cyl(t_data *img, t_cylinder *cylinder, t_vector3d_d n)
{
	double		depth;
	t_camera	*camera;

	depth = 0;
	camera = my_cameramanager_current(img);
	if (is_hit_cylinder(camera, cylinder, n) == 1)
	{
		if (d_cyl(cylinder) <= cylinder->height
			|| d_cyl_2(cylinder) <= cylinder->height)
			depth = d_from_camera(camera, cylinder->hit1.x, cylinder->hit1.y,
					cylinder->hit1.z);
	}
	if (depth > 0 && depth < img->temprendervalue.depth)
	{
		img->temprendervalue.depth = depth;
		img->temprendervalue.color = cyl_color_init(img, cylinder,
				my_lightmanager_current(img));
		return (1);
	}
	return (0);
}
