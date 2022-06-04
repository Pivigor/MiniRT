/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_manager_render_pl2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarlic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:25:33 by jgarlic           #+#    #+#             */
/*   Updated: 2022/02/16 10:25:34 by jgarlic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_minirt.h"

double	pl_calc_spec(t_camera *camera, t_plane *plane, t_vector3d_d n)
{
	t_vector3d_d	dir;
	t_vector3d_d	refl_ray;
	double			cos1;

	dir.x = plane->hit1.x - camera->coord.x;
	dir.y = plane->hit1.y - camera->coord.y;
	dir.z = plane->hit1.z - camera->coord.z;
	refl_ray = ft_reflect_ray(n, plane->orient);
	cos1 = (dir.x * refl_ray.x + dir.y * refl_ray.y + dir.z * refl_ray.z)
		/ (sqrt(dir.x * dir.x + dir.y * dir.y + dir.z * dir.z)
			* sqrt(refl_ray.x * refl_ray.x + refl_ray.y * refl_ray.y
				+ refl_ray.z * refl_ray.z));
	return (pow(cos1, 32));
}

t_vector3d	pl_get_diffuse(t_light *light, double cos)
{
	t_vector3d	rgb_diffuse;

	rgb_diffuse.x = (int)(light->rgb.x * light->ratio * (1 - cos));
	rgb_diffuse.y = (int)(light->rgb.y * light->ratio * (1 - cos));
	rgb_diffuse.z = (int)(light->rgb.z * light->ratio * (1 - cos));
	return (rgb_diffuse);
}

t_vector3d	pl_get_specular(t_camera *camera, t_plane *plane,
		t_light *light, t_vector3d_d n)
{
	t_vector3d	rgb_specular;
	double		spec;

	spec = pl_calc_spec(camera, plane, n);
	rgb_specular.x = (int)(light->rgb.x * spec);
	rgb_specular.y = (int)(light->rgb.y * spec);
	rgb_specular.z = (int)(light->rgb.z * spec);
	return (rgb_specular);
}

int	plane_color_init(t_data *img, t_plane *plane, t_light *light,
		t_vector3d_d n)
{
	t_shader		shader;
	t_vector3d_d	l_dir;
	t_vector3d_d	n_dir;
	double			cos;

	shader.rgb_ambient = get_ambient(img);
	l_dir = minus_vecvec(light->coord, plane->hit1);
	n_dir = minus_vecvec(mult_vecdouble(plane->orient, -1), plane->hit1);
	cos = scalar_product(l_dir, n_dir) / (vector_length(n_dir)
			* vector_length(l_dir) * 1.03);
	shader.rgb_diffuse = pl_get_diffuse(light, cos);
	shader.rgb_specular = pl_get_specular(my_cameramanager_current(img),
			plane, light, n);
	if (compute_shadow(img, plane,
			minus_vecvec(light->coord, plane->hit1)) == 1)
		shader_to_shadow(&shader);
	return (my_to_hex(my_compute_shader(shader, plane->rgb)));
}
