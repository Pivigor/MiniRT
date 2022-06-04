/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_manager_render.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarlic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:26:05 by jgarlic           #+#    #+#             */
/*   Updated: 2022/02/16 10:26:06 by jgarlic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_minirt.h"

void	my_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x > MY_SCREEN_X || y > MY_SCREEN_Y)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double	d_from_camera(t_camera *camera, double x, double y, double z)
{
	double	rx;
	double	ry;
	double	rz;

	rx = camera->coord.x - x;
	ry = camera->coord.y - y;
	rz = camera->coord.z - z;
	return (sqrt(rx * rx + ry * ry + rz * rz));
}

void	my_render_figures(t_data *img, t_list *list, t_vector3d_d n)
{
	t_parse	*parse;
	int		update;

	while (list != NULL)
	{
		update = 0;
		parse = list->content;
		if (parse->type == Sphere)
			update = my_render_sphere(img, parse->object, n);
		else if (parse->type == Plane)
			update = my_render_plane(img, parse->object, n);
		else if (parse->type == Cylinder)
			update = my_render_cyl(img, parse->object, n);
		if (update)
			img->temprendervalue.object = list;
		list = list->next;
	}
}

void	my_render_light(t_data *img, int x, int y, t_vector3d_d n)
{
	t_light	*begin;
	t_light	*light;

	begin = my_lightmanager_current(img);
	light = my_lightmanager_next(img);
	while (light != begin)
	{
		my_render_figures(img, img->parse_list, n);
		light = my_lightmanager_next(img);
		img->finalrender[x][y].color = my_sum_hex(
				img->finalrender[x][y].color, img->temprendervalue.color);
		if (img->temprendervalue.object != NULL)
			img->finalrender[x][y].object = img->temprendervalue.object;
		my_reset_temp(img);
	}
	my_render_figures(img, img->parse_list, n);
	img->finalrender[x][y].color = my_sum_hex(
			img->finalrender[x][y].color, img->temprendervalue.color);
	if (img->temprendervalue.object != NULL)
		img->finalrender[x][y].object = img->temprendervalue.object;
	my_reset_temp(img);
	my_pixel_put(img, x, y, img->finalrender[x][y].color);
}

void	render_start(t_data *img)
{
	int				i;
	int				j;
	t_vector3d_d	n;

	my_rendermanager_init(img);
	my_calc_ambient(img);
	i = 0;
	while (i < MY_SCREEN_X)
	{
		j = 0;
		while (j < MY_SCREEN_Y)
		{
			n = calc_n(my_cameramanager_current(img), img->xy[i][j]);
			my_render_light(img, i, j, n);
			j++;
		}
		i++;
	}
}
