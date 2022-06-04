/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_manager_camera.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarlic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:24:15 by jgarlic           #+#    #+#             */
/*   Updated: 2022/02/16 10:24:16 by jgarlic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_minirt.h"

void	my_fill_cameras(t_list *parse_list, t_camera **cameras)
{
	t_parse	*parse;
	int		i;

	i = 0;
	while (parse_list != NULL)
	{
		parse = parse_list->content;
		if (parse->type == Camera)
		{
			cameras[i] = parse->object;
			i++;
		}
		parse_list = parse_list->next;
	}
}

t_camera	*my_cameramanager_prev(t_data *img)
{
	if (img->cameramanager.current - 1 < 0)
		img->cameramanager.current = img->cameramanager.count - 1;
	else
		img->cameramanager.current--;
	return (img->cameramanager.cameras[img->cameramanager.current]);
}

t_camera	*my_cameramanager_next(t_data *img)
{
	if (img->cameramanager.current + 1 == img->cameramanager.count)
		img->cameramanager.current = 0;
	else
		img->cameramanager.current++;
	return (img->cameramanager.cameras[img->cameramanager.current]);
}

t_camera	*my_cameramanager_current(t_data *img)
{
	return (img->cameramanager.cameras[img->cameramanager.current]);
}

t_camera	*my_cameramanager_init(t_data *img)
{
	img->cameramanager.cameras = NULL;
	img->cameramanager.current = -1;
	img->cameramanager.count = my_count_types(img->parse_list, Camera);
	if (img->cameramanager.count == 0)
		return (my_default_camera(img));
	else
	{
		img->cameramanager.cameras = malloc(sizeof(t_camera *)
				* img->cameramanager.count);
		my_fill_cameras(img->parse_list, img->cameramanager.cameras);
		return (my_cameramanager_next(img));
	}
}
