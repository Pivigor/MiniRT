/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_manager_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarlic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:24:44 by jgarlic           #+#    #+#             */
/*   Updated: 2022/02/16 10:24:45 by jgarlic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_minirt.h"

void	my_fill_lights(t_list *parse_list, t_light **lights)
{
	t_parse	*parse;
	int		i;

	i = 0;
	while (parse_list != NULL)
	{
		parse = parse_list->content;
		if (parse->type == Light)
		{
			lights[i] = parse->object;
			i++;
		}
		parse_list = parse_list->next;
	}
}

t_light	*my_lightmanager_prev(t_data *img)
{
	if (img->lightmanager.current - 1 < 0)
		img->lightmanager.current = img->lightmanager.count - 1;
	else
		img->lightmanager.current--;
	return (img->lightmanager.lights[img->lightmanager.current]);
}

t_light	*my_lightmanager_next(t_data *img)
{
	if (img->lightmanager.current + 1 == img->lightmanager.count)
		img->lightmanager.current = 0;
	else
		img->lightmanager.current++;
	return (img->lightmanager.lights[img->lightmanager.current]);
}

t_light	*my_lightmanager_current(t_data *img)
{
	return (img->lightmanager.lights[img->lightmanager.current]);
}

t_light	*my_lightmanager_init(t_data *img)
{
	img->lightmanager.lights = NULL;
	img->lightmanager.current = -1;
	img->lightmanager.count = my_count_types(img->parse_list, Light);
	if (img->lightmanager.count == 0)
		return (my_default_light(img));
	else
	{
		img->lightmanager.lights = malloc(sizeof(t_light *)
				* img->lightmanager.count);
		my_fill_lights(img->parse_list, img->lightmanager.lights);
		return (my_lightmanager_next(img));
	}
}
