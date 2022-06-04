/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_manager_render_sp.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarlic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:25:43 by jgarlic           #+#    #+#             */
/*   Updated: 2022/02/16 10:25:44 by jgarlic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_minirt.h"

void	is_hit_sphere3(t_camera *camera, t_sphere *sphere, t_vector3d_d n,
		t_vector3d_d d)
{
	sphere->hit1.x = d.z * n.x + camera->coord.x;
	sphere->hit1.y = d.z * n.y + camera->coord.y;
	sphere->hit1.z = d.z * n.z + camera->coord.z;
	sphere->hit2.x = d.y * n.x + camera->coord.x;
	sphere->hit2.y = d.y * n.y + camera->coord.y;
	sphere->hit2.z = d.y * n.z + camera->coord.z;
}

void	is_hit_sphere2(t_camera *camera, t_sphere *sphere, t_vector3d_d n,
		t_vector3d_d d)
{
	sphere->hit1.x = d.y * n.x + camera->coord.x;
	sphere->hit1.y = d.y * n.y + camera->coord.y;
	sphere->hit1.z = d.y * n.z + camera->coord.z;
	sphere->hit2.x = d.z * n.x + camera->coord.x;
	sphere->hit2.y = d.z * n.y + camera->coord.y;
	sphere->hit2.z = d.z * n.z + camera->coord.z;
}

t_vector3d_d	sp_calc_coeff(t_sphere *sphere, t_vector3d_d n, t_vector3d_d oc)
{
	t_vector3d_d	coeff;

	coeff.x = scalar_product(n, n);
	coeff.y = 2 * scalar_product(oc, n);
	coeff.z = scalar_product(oc, oc) - (sphere->diameter / 2)
		* (sphere->diameter / 2);
	return (coeff);
}

int	is_hit_sphere(t_camera *camera, t_sphere *sphere, t_vector3d_d n)
{
	t_vector3d_d	coeff;
	t_vector3d_d	d;

	coeff = sp_calc_coeff(sphere, n,
			minus_vecvec(camera->coord, sphere->coord));
	d.x = coeff.y * coeff.y - 4 * coeff.x * coeff.z;
	if (d.x >= 0)
	{
		d.y = (-coeff.y + sqrt(d.x)) / (2 * coeff.x);
		d.z = (-coeff.y - sqrt(d.x)) / (2 * coeff.x);
		if (d.y <= d.z && d.y > 0 && d.z > 0)
			is_hit_sphere2(camera, sphere, n, d);
		else if (d.y > d.z && d.y > 0 && d.z > 0)
			is_hit_sphere3(camera, sphere, n, d);
		else if (d.y < 0 || d.z < 0)
			return (0);
		return (1);
	}
	else
		return (0);
}

int	my_render_sphere(t_data *img, t_sphere *sphere, t_vector3d_d n)
{
	double		depth;
	t_camera	*camera;

	depth = 0;
	camera = my_cameramanager_current(img);
	if (is_hit_sphere(camera, sphere, n) == 1)
		depth = d_from_camera(camera, sphere->hit1.x,
				sphere->hit1.y, sphere->hit1.z);
	if (depth > 0 && depth < img->temprendervalue.depth)
	{
		img->temprendervalue.depth = depth;
		img->temprendervalue.color = my_sphere_color(img, sphere,
				my_lightmanager_current(img));
		img->temprendervalue.init = 1;
		return (1);
	}
	return (0);
}
