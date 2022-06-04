/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_transform2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarlic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:27:43 by jgarlic           #+#    #+#             */
/*   Updated: 2022/02/16 10:27:44 by jgarlic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_minirt.h"

t_vector3d_d	*get_coord2(t_parse *object)
{
	t_plane		*plane;
	t_cylinder	*cylinder;

	if (object->type == Plane)
	{
		plane = object->object;
		return (&plane->coord);
	}
	else if (object->type == Cylinder)
	{
		cylinder = object->object;
		return (&cylinder->coord);
	}
	return (NULL);
}

t_vector3d_d	*get_coord(t_parse *object)
{
	t_camera	*camera;
	t_light		*light;
	t_sphere	*sphere;

	if (object->type == Camera)
	{
		camera = object->object;
		return (&camera->coord);
	}
	else if (object->type == Light)
	{
		light = object->object;
		return (&light->coord);
	}
	else if (object->type == Sphere)
	{
		sphere = object->object;
		return (&sphere->coord);
	}
	else
		return (get_coord2(object));
}

t_vector3d_d	*get_orient(t_parse *object)
{
	t_camera	*camera;
	t_plane		*plane;
	t_cylinder	*cylinder;

	if (object->type == Camera)
	{
		camera = object->object;
		return (&camera->orient);
	}
	else if (object->type == Plane)
	{
		plane = object->object;
		return (&plane->orient);
	}
	else if (object->type == Cylinder)
	{
		cylinder = object->object;
		return (&cylinder->orient);
	}
	return (NULL);
}

double	*get_scale2(t_parse *object)
{
	t_cylinder	*cylinder;

	if (object->type == Cylinder)
	{
		cylinder = object->object;
		return (&cylinder->diameter);
	}
	return (NULL);
}

double	*get_scale(t_parse *object)
{
	t_ambient	*ambient;
	t_light		*light;
	t_sphere	*sphere;

	if (object->type == Ambient)
	{
		ambient = object->object;
		return (&ambient->ratio);
	}
	else if (object->type == Light)
	{
		light = object->object;
		return (&light->ratio);
	}
	else if (object->type == Sphere)
	{
		sphere = object->object;
		return (&sphere->diameter);
	}
	else
		return (get_scale2(object));
}
