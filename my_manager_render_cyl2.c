/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_manager_render_cyl2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarlic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:25:08 by jgarlic           #+#    #+#             */
/*   Updated: 2022/02/16 10:25:09 by jgarlic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_minirt.h"

double	cyl_calc_spec(t_cylinder *cylinder, t_vector3d_d l_dir)
{
	t_vector3d_d	norm;
	double			cos1;
	double			p;
	double			d;
	double			radius;

	radius = cylinder->diameter / 2;
	d = sqrt(pow(cylinder->hit1.x - cylinder->coord.x, 2)
			+ pow(cylinder->hit1.y - cylinder->coord.y, 2)
			+ pow(cylinder->hit1.z - cylinder->coord.z, 2));
	p = d * sqrt(1 - pow(radius / d, 2));
	norm.x = cylinder->hit1.x - cylinder->coord.x + p * cylinder->orient.x;
	norm.y = cylinder->hit1.y - cylinder->coord.y + p * cylinder->orient.y;
	norm.z = cylinder->hit1.z - cylinder->coord.z + p * cylinder->orient.z;
	cos1 = scalar_product(l_dir, norm)
		/ (vector_length(l_dir) * vector_length(norm));
	return (pow(cos1, 32));
}

t_vector3d	cyl_get_diffuse(t_light *light, double cos)
{
	t_vector3d	rgb_diffuse;

	rgb_diffuse.x = (int)(light->rgb.x * light->ratio * -cos);
	rgb_diffuse.y = (int)(light->rgb.y * light->ratio * -cos);
	rgb_diffuse.z = (int)(light->rgb.z * light->ratio * -cos);
	if (cos > 0)
	{
		rgb_diffuse.x = 0;
		rgb_diffuse.y = 0;
		rgb_diffuse.z = 0;
	}
	return (rgb_diffuse);
}

t_vector3d	cyl_get_specular(t_cylinder *cylinder,
			t_light *light, t_vector3d_d l_dir)
{
	t_vector3d	rgb_specular;
	double		spec;

	spec = cyl_calc_spec(cylinder, l_dir);
	rgb_specular.x = (int)(light->rgb.x * light->ratio * spec);
	rgb_specular.y = (int)(light->rgb.y * light->ratio * spec);
	rgb_specular.z = (int)(light->rgb.z * light->ratio * spec);
	return (rgb_specular);
}

int	cyl_color_init(t_data *img, t_cylinder *cylinder, t_light *light)
{
	t_shader		shader;
	t_vector3d_d	l_dir;
	t_vector3d_d	n_dir;
	double			cos;

	shader.rgb_ambient = get_ambient(img);
	l_dir = minus_vecvec(light->coord, cylinder->hit1);
	n_dir = minus_vecvec(cylinder->coord, cylinder->hit1);
	cos = scalar_product(l_dir, n_dir) / (vector_length(n_dir)
			* vector_length(l_dir));
	if (d_cyl(cylinder) > cylinder->height
		&& d_cyl_2(cylinder) <= cylinder->height)
	{
		l_dir = minus_vecvec(light->coord, cylinder->hit2);
		cos = scalar_product(l_dir, mult_vecdouble(n_dir, -1))
			/ (vector_length(n_dir) * vector_length(l_dir));
	}
	shader.rgb_diffuse = cyl_get_diffuse(light, cos);
	shader.rgb_specular = cyl_get_specular(cylinder, light, l_dir);
	if (compute_shadow3(img, cylinder,
			minus_vecvec(light->coord, cylinder->hit1)) == 1)
		shader_to_shadow(&shader);
	return (my_to_hex(my_compute_shader(shader, cylinder->rgb)));
}
