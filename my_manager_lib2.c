/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_manager_lib2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarlic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:24:35 by jgarlic           #+#    #+#             */
/*   Updated: 2022/02/16 10:24:36 by jgarlic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_minirt.h"

// TODO: Set default values
t_camera	*my_default_camera(t_data *img)
{
	static t_camera	default_camera;

	img->cameramanager.count = 1;
	img->cameramanager.cameras = malloc(sizeof(t_camera *));
	img->cameramanager.cameras[0] = &default_camera;
	return (img->cameramanager.cameras[0]);
}

// TODO: Set default values
t_light	*my_default_light(t_data *img)
{
	static t_light	default_light;

	img->lightmanager.count = 1;
	img->lightmanager.lights = malloc(sizeof(t_light *));
	img->lightmanager.lights[0] = &default_light;
	return (img->lightmanager.lights[0]);
}
