/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_manager_render2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarlic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:26:12 by jgarlic           #+#    #+#             */
/*   Updated: 2022/02/16 10:26:13 by jgarlic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_minirt.h"
#include "float.h"

void	my_calc_ambient2(t_data *img, t_parse *object, int *init)
{
	t_ambient	*ambient;

	if (object->type == Ambient)
	{
		ambient = object->object;
		if (*init)
		{
			img->g_ambient.ratio = (img->g_ambient.ratio
					+ ambient->ratio) / 2;
			img->g_ambient.rgb = my_mix_rgb(img->g_ambient.rgb,
					ambient->rgb);
		}
		else
		{
			img->g_ambient.ratio = ambient->ratio;
			img->g_ambient.rgb = ambient->rgb;
			*init = 1;
		}
	}
}

void	my_calc_ambient(t_data *img)
{
	t_list		*begin;
	int			init;

	begin = img->parse_list;
	init = 0;
	img->g_ambient.ratio = 0;
	img->g_ambient.rgb.x = 0;
	img->g_ambient.rgb.y = 0;
	img->g_ambient.rgb.z = 0;
	while (begin != NULL)
	{
		my_calc_ambient2(img, begin->content, &init);
		begin = begin->next;
	}
}

void	my_reset_temp(t_data *img)
{
	img->temprendervalue.depth = DBL_MAX;
	img->temprendervalue.color = 0;
	img->temprendervalue.init = 0;
	img->temprendervalue.object = NULL;
}

void	my_rendermanager_init2(t_data *img, float scale, float imageaspectratio)
{
	int	i;
	int	j;

	i = 0;
	while (i < MY_SCREEN_X)
	{
		j = 0;
		while (j < MY_SCREEN_Y)
		{
			img->finalrender[i][j].depth = DBL_MAX;
			img->finalrender[i][j].color = 0;
			img->finalrender[i][j].init = 0;
			img->finalrender[i][j].object = NULL;
			img->xy[i][j].x = (2 * ((float) i + 0.5f)
					/ (float) MY_SCREEN_X - 1) * scale;
			img->xy[i][j].y = (1 - 2 * ((float) j + 0.5f)
					/ (float) MY_SCREEN_Y) * scale * 1 / imageaspectratio;
			j++;
		}
		i++;
	}
}

void	my_rendermanager_init(t_data *img)
{
	t_camera	*camera;
	float		b;
	float		scale;
	float		imageaspectratio;

	camera = my_cameramanager_current(img);
	b = (float)(((float) camera->fov * 0.5f * 180) / M_PI);
	scale = tanf(b);
	imageaspectratio = MY_SCREEN_X / (float) MY_SCREEN_Y;
	my_rendermanager_init2(img, scale, imageaspectratio);
	my_reset_temp(img);
}
