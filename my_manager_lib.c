/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_manager_lib.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarlic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:24:27 by jgarlic           #+#    #+#             */
/*   Updated: 2022/02/16 10:24:28 by jgarlic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_minirt.h"

int	my_count_types(t_list *parse_list, t_figure_type type)
{
	t_parse	*parse;
	int		count;

	count = 0;
	while (parse_list != NULL)
	{
		parse = parse_list->content;
		if (parse->type == type)
			count++;
		parse_list = parse_list->next;
	}
	return (count);
}

t_vector3d_d	calc_n(t_camera *camera, t_vector2d_f xy)
{
	t_vector3d_d	n;
	t_vector3d_d	rotator;

	n.x = xy.x / sqrt(xy.x * xy.x + xy.y * xy.y);
	n.y = xy.y / sqrt(xy.x * xy.x + xy.y * xy.y);
	n.z = 1 / sqrt(xy.x * xy.x + xy.y * xy.y);
	rotator = my_convert_direction_to_rotation(camera->orient);
	n = my_rotate_vector_by_axis(n, my_get_direction_vector(Up), -rotator.x);
	n = my_rotate_vector_by_axis(n, my_get_direction_vector(Right), -rotator.y);
	return (n);
}

t_vector3d	get_ambient(t_data *img)
{
	t_vector3d	rgb_ambient;

	rgb_ambient.x = (int)((float) img->g_ambient.rgb.x * img->g_ambient.ratio);
	rgb_ambient.y = (int)((float) img->g_ambient.rgb.y * img->g_ambient.ratio);
	rgb_ambient.z = (int)((float) img->g_ambient.rgb.z * img->g_ambient.ratio);
	return (rgb_ambient);
}

void	shader_to_shadow(t_shader *shader)
{
	shader->rgb_diffuse.x = 0;
	shader->rgb_specular.x = 0;
	shader->rgb_diffuse.y = 0;
	shader->rgb_specular.y = 0;
	shader->rgb_diffuse.z = 0;
	shader->rgb_specular.z = 0;
}

t_vector3d	my_compute_shader(t_shader shader, t_vector3d rgb_texture)
{
	t_vector3d		final_rgb;
	t_vector3d_d	light_mult;

	light_mult.x = (double)(shader.rgb_diffuse.x + shader.rgb_specular.x
			+ shader.rgb_ambient.x) / 255;
	light_mult.y = (double)(shader.rgb_diffuse.y + shader.rgb_specular.y
			+ shader.rgb_ambient.y) / 255;
	light_mult.z = (double)(shader.rgb_diffuse.z + shader.rgb_specular.z
			+ shader.rgb_ambient.z) / 255;
	final_rgb.x = my_clamp_color((int)(light_mult.x * rgb_texture.x));
	final_rgb.y = my_clamp_color((int)(light_mult.y * rgb_texture.y));
	final_rgb.z = my_clamp_color((int)(light_mult.z * rgb_texture.z));
	return (final_rgb);
}
