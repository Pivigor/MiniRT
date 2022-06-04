/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_parser3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarlic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:26:51 by jgarlic           #+#    #+#             */
/*   Updated: 2022/02/16 10:26:52 by jgarlic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_parser.h"

void	my_parse_ambient(char **line_split, t_parse *parse)
{
	t_ambient	*ambient;
	char		**split;

	if (my_split_size(line_split) < 3 || my_count_chars(line_split[2], ',') < 2)
		return ;
	ambient = malloc(sizeof(t_ambient));
	ambient->ratio = my_atod(line_split[1]);
	split = ft_split(line_split[2], ',');
	ambient->rgb.x = ft_atoi(split[0]);
	ambient->rgb.y = ft_atoi(split[1]);
	ambient->rgb.z = ft_atoi(split[2]);
	my_free_split(split);
	parse->type = Ambient;
	parse->object = ambient;
}

void	my_parse_camera(char **line_split, t_parse *parse)
{
	t_camera	*camera;
	char		**split;

	if (my_split_size(line_split) < 4 || my_count_chars(line_split[1], ',') < 2
		|| my_count_chars(line_split[2], ',') < 2)
		return ;
	camera = malloc(sizeof(t_camera));
	split = ft_split(line_split[1], ',');
	camera->coord.x = my_atod(split[0]);
	camera->coord.y = my_atod(split[1]);
	camera->coord.z = my_atod(split[2]);
	my_free_split(split);
	split = ft_split(line_split[2], ',');
	camera->orient.x = my_atod(split[0]);
	camera->orient.y = my_atod(split[1]);
	camera->orient.z = my_atod(split[2]);
	my_free_split(split);
	camera->fov = ft_atoi(line_split[3]);
	parse->type = Camera;
	parse->object = camera;
}

void	my_parse_light(char **line_split, t_parse *parse)
{
	t_light	*light;
	char	**split;

	if (my_split_size(line_split) < 4 || my_count_chars(line_split[1], ',') < 2
		|| my_count_chars(line_split[3], ',') < 2)
		return ;
	light = malloc(sizeof(t_light));
	split = ft_split(line_split[1], ',');
	light->coord.x = my_atod(split[0]);
	light->coord.y = my_atod(split[1]);
	light->coord.z = my_atod(split[2]);
	my_free_split(split);
	light->ratio = my_atod(line_split[2]);
	split = ft_split(line_split[3], ',');
	light->rgb.x = ft_atoi(split[0]);
	light->rgb.y = ft_atoi(split[1]);
	light->rgb.z = ft_atoi(split[2]);
	my_free_split(split);
	parse->type = Light;
	parse->object = light;
}

void	my_parse_sphere(char **line_split, t_parse *parse)
{
	t_sphere	*sphere;
	char		**split;

	if (my_split_size(line_split) < 4 || my_count_chars(line_split[1], ',') < 2
		|| my_count_chars(line_split[3], ',') < 2)
		return ;
	sphere = malloc(sizeof(t_sphere));
	split = ft_split(line_split[1], ',');
	sphere->coord.x = my_atod(split[0]);
	sphere->coord.y = my_atod(split[1]);
	sphere->coord.z = my_atod(split[2]);
	my_free_split(split);
	sphere->diameter = my_atod(line_split[2]);
	split = ft_split(line_split[3], ',');
	sphere->rgb.x = ft_atoi(split[0]);
	sphere->rgb.y = ft_atoi(split[1]);
	sphere->rgb.z = ft_atoi(split[2]);
	my_free_split(split);
	parse->type = Sphere;
	parse->object = sphere;
}

void	my_parse_plane(char **line_split, t_parse *parse)
{
	t_plane	*plane;
	char	**split;

	if (my_split_size(line_split) < 4 || my_count_chars(line_split[1], ',') < 2
		|| my_count_chars(line_split[2], ',') < 2
		|| my_count_chars(line_split[3], ',') < 2)
		return ;
	plane = malloc(sizeof(t_plane));
	split = ft_split(line_split[1], ',');
	plane->coord.x = my_atod(split[0]);
	plane->coord.y = my_atod(split[1]);
	plane->coord.z = my_atod(split[2]);
	my_free_split(split);
	split = ft_split(line_split[2], ',');
	plane->orient.x = my_atod(split[0]);
	plane->orient.y = my_atod(split[1]);
	plane->orient.z = my_atod(split[2]);
	my_free_split(split);
	split = ft_split(line_split[3], ',');
	plane->rgb.x = ft_atoi(split[0]);
	plane->rgb.y = ft_atoi(split[1]);
	plane->rgb.z = ft_atoi(split[2]);
	my_free_split(split);
	parse->type = Plane;
	parse->object = plane;
}
