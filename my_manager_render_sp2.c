/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_manager_render_sp2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarlic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:25:50 by jgarlic           #+#    #+#             */
/*   Updated: 2022/02/16 10:25:51 by jgarlic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_minirt.h"

t_vector3d	sp_get_diffuse(t_light *light, double cos)
{
	t_vector3d	rgb_diffuse;

	rgb_diffuse.x = (int)(light->rgb.x * light->ratio * (cos));
	rgb_diffuse.y = (int)(light->rgb.y * light->ratio * (cos));
	rgb_diffuse.z = (int)(light->rgb.z * light->ratio * (cos));
	return (rgb_diffuse);
}

int	my_sphere_color(t_data *img, t_sphere *sphere, t_light *light)
{
	t_shader		shader;
	t_vector3d_d	l_dir;
	t_vector3d_d	n_dir;
	double			cos;

	shader.rgb_ambient = get_ambient(img);
	l_dir = minus_vecvec(light->coord, sphere->hit1);
	n_dir = minus_vecvec(sphere->hit1, sphere->coord);
	cos = scalar_product(l_dir, n_dir) / (vector_length(n_dir)
			* vector_length(l_dir));
	shader.rgb_diffuse = sp_get_diffuse(light, cos);
	if (compute_shadow2(img, sphere,
			minus_vecvec(light->coord, sphere->hit1)) == 1)
		shader_to_shadow(&shader);
	if (shader.rgb_diffuse.x < 0)
		shader.rgb_diffuse.x = 0;
	if (shader.rgb_diffuse.y < 0)
		shader.rgb_diffuse.y = 0;
	if (shader.rgb_diffuse.z < 0)
		shader.rgb_diffuse.z = 0;
	shader.rgb_specular.x = 0;
	shader.rgb_specular.y = 0;
	shader.rgb_specular.z = 0;
	return (my_to_hex(my_compute_shader(shader, sphere->rgb)));
}
