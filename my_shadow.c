/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_shadow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarlic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:27:21 by jgarlic           #+#    #+#             */
/*   Updated: 2022/02/16 10:27:23 by jgarlic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_minirt.h"

int	is_hit_sphere11(t_vector3d_d start, t_sphere *sphere, t_vector3d_d n)
{
	t_vector3d_d	coeff;
	t_vector3d_d	oc;
	t_vector3d_d	d;

	oc = minus_vecvec(start, sphere->coord);
	coeff.x = scalar_product(n, n);
	coeff.y = 2 * scalar_product(oc, n);
	coeff.z = scalar_product(oc, oc) - (sphere->diameter / 2)
		* (sphere->diameter / 2);
	d.x = coeff.y * coeff.y - 4 * coeff.x * coeff.z;
	if (d.x >= 0)
	{
		d.y = (-coeff.y + sqrt(d.x)) / (2 * coeff.x);
		d.z = (-coeff.y - sqrt(d.x)) / (2 * coeff.x);
		return (is_hit_sphere112(start, sphere, n, d));
	}
	else
		return (0);
}

int	is_hit_plane11(t_vector3d_d start, t_plane *plane, t_vector3d_d n)
{
	double			decision;
	t_vector3d_d	coeff;

	coeff.x = scalar_product(minus_vecvec(start, plane->coord), plane->orient);
	coeff.y = scalar_product(n, plane->orient);
	coeff.z = 0;
	decision = -coeff.x / coeff.x;
	if (decision > 0.0001 && decision < 1.000000)
	{
		plane->hit1.x = decision * n.x + start.x;
		plane->hit1.y = decision * n.y + start.y;
		plane->hit1.z = decision * n.z + start.z;
		return (1);
	}
	else
		return (0);
}

int	compute_shadow(t_data *img, t_plane *plane, t_vector3d_d n)
{
	t_parse	*parse;
	t_list	*list;

	list = img->parse_list;
	while (list != NULL)
	{
		parse = list->content;
		if (parse->type == Sphere)
			if (is_hit_sphere11(plane->hit1, parse->object, n))
				return (1);
		if (parse->type == Cylinder)
			if (is_hit_cylinder1(plane->hit1, parse->object, n))
				return (1);
		if (parse->type == Plane)
			if (is_hit_plane11(plane->hit1, parse->object, n))
				return (1);
		list = list->next;
	}
	return (0);
}

int	compute_shadow2(t_data *img, t_sphere *sphere, t_vector3d_d n)
{
	t_parse	*parse;
	t_list	*list;
	int		flag;

	flag = 0;
	list = img->parse_list;
	while (list != NULL)
	{
		parse = list->content;
		if (parse->type == Sphere)
			if (is_hit_sphere11(sphere->hit1, parse->object, n))
				flag = 1;
		if (parse->type == Cylinder)
			if (is_hit_cylinder1(sphere->hit1, parse->object, n))
				flag = 1;
		if (parse->type == Plane)
			if (is_hit_plane11(sphere->hit1, parse->object, n))
				flag = 1;
		list = list->next;
	}
	return (flag);
}

int	compute_shadow3(t_data *img, t_cylinder *cylinder, t_vector3d_d n)
{
	t_parse	*parse;
	t_list	*list;
	int		flag;

	flag = 0;
	list = img->parse_list;
	while (list != NULL)
	{
		parse = list->content;
		if (parse->type == Sphere)
			if (is_hit_sphere11(cylinder->hit1, parse->object, n))
				flag = 1;
		if (parse->type == Cylinder)
			if (is_hit_cylinder1(cylinder->hit1, parse->object, n))
				flag = 1;
		if (parse->type == Plane)
			if (is_hit_plane11(cylinder->hit1, parse->object, n))
				flag = 1;
		list = list->next;
	}
	return (flag);
}
