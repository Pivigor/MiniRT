/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_parser2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarlic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:26:45 by jgarlic           #+#    #+#             */
/*   Updated: 2022/02/16 10:26:46 by jgarlic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_parser.h"

void	my_parse_print3(t_parse *parse)
{
	t_cylinder	*cylinder;

	if (parse->type == Cylinder)
	{
		cylinder = parse->object;
		printf("Cylinder: Coord=%f|%f|%f Orient=%f|%f|%f Diameter=%f "
			"Height=%f RGB=%d|%d|%d\n",
			cylinder->coord.x, cylinder->coord.y, cylinder->coord.z,
			cylinder->orient.x, cylinder->orient.y, cylinder->orient.z,
			cylinder->diameter, cylinder->height,
			cylinder->rgb.x, cylinder->rgb.y, cylinder->rgb.z);
	}
}

void	my_parse_print2(t_parse *parse)
{
	t_sphere	*sphere;
	t_plane		*plane;

	if (parse->type == Sphere)
	{
		sphere = parse->object;
		printf("Sphere: Coord=%f|%f|%f Diameter=%f RGB=%d|%d|%d\n",
			sphere->coord.x, sphere->coord.y, sphere->coord.z,
			sphere->diameter, sphere->rgb.x, sphere->rgb.y, sphere->rgb.z);
	}
	if (parse->type == Plane)
	{
		plane = parse->object;
		printf("Plane: Coord=%f|%f|%f Orient=%f|%f|%f RGB=%d|%d|%d\n",
			plane->coord.x, plane->coord.y, plane->coord.z,
			plane->orient.x, plane->orient.y, plane->orient.z,
			plane->rgb.x, plane->rgb.y, plane->rgb.z);
	}
	my_parse_print3(parse);
}

void	my_parse_print(t_parse *parse)
{
	t_ambient	*ambient;
	t_camera	*camera;
	t_light		*light;

	if (parse->type == Ambient)
	{
		ambient = parse->object;
		printf("Ambient: Ratio=%f RGB=%d|%d|%d\n",
			ambient->ratio, ambient->rgb.x, ambient->rgb.y, ambient->rgb.z);
	}
	if (parse->type == Camera)
	{
		camera = parse->object;
		printf("Camera: Coord=%f|%f|%f Orient=%f|%f|%f Fov=%d\n",
			camera->coord.x, camera->coord.y, camera->coord.z,
			camera->orient.x, camera->orient.y, camera->orient.z, camera->fov);
	}
	if (parse->type == Light)
	{
		light = parse->object;
		printf("Light: Coord=%f|%f|%f Ratio=%f RGB=%d|%d|%d\n",
			light->coord.x, light->coord.y, light->coord.z,
			light->ratio, light->rgb.x, light->rgb.y, light->rgb.z);
	}
	my_parse_print2(parse);
}

void	my_full_print(t_list *list)
{
	while (list != NULL)
	{
		my_parse_print(list->content);
		list = list->next;
	}
}
