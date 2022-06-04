/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_manager_render_pl.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarlic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:25:25 by jgarlic           #+#    #+#             */
/*   Updated: 2022/02/16 10:25:27 by jgarlic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_minirt.h"

t_vector3d_d	ft_reflect_ray(t_vector3d_d R, t_vector3d_d N)
{
	t_vector3d_d	res;

	res = mult_vecdouble(N, 2 * scalar_product(N, R));
	res = minus_vecvec(res, R);
	return (res);
}

int	is_hit_plane(t_camera *camera, t_plane *plane, t_vector3d_d n)
{
	double			decision;
	t_vector3d_d	coeff;
	t_vector3d_d	oc;

	oc = minus_vecvec(camera->coord, plane->coord);
	coeff.x = scalar_product(oc, plane->orient);
	coeff.y = scalar_product(n, plane->orient);
	coeff.z = 0;
	decision = -coeff.x / coeff.y;
	if (decision > 0)
	{
		plane->hit1.x = decision * n.x + camera->coord.x;
		plane->hit1.y = decision * n.y + camera->coord.y;
		plane->hit1.z = decision * n.z + camera->coord.z;
		return (1);
	}
	else
	{
		plane->hit1.x = 0;
		plane->hit1.y = 0;
		plane->hit1.z = 0;
		return (0);
	}
}

int	my_render_plane(t_data *img, t_plane *plane, t_vector3d_d n)
{
	double		depth;
	t_camera	*camera;

	depth = 0;
	camera = my_cameramanager_current(img);
	if (is_hit_plane(camera, plane, n) == 1)
		depth = d_from_camera(camera, plane->hit1.x, plane->hit1.y,
				plane->hit1.z);
	if (depth > 0 && depth < img->temprendervalue.depth)
	{
		img->temprendervalue.depth = depth;
		img->temprendervalue.color = plane_color_init(img, plane,
				my_lightmanager_current(img), n);
		return (1);
	}
	return (0);
}
