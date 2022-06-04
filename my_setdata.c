/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_setdata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarlic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:27:11 by jgarlic           #+#    #+#             */
/*   Updated: 2022/02/16 10:27:12 by jgarlic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_minirt.h"

void	ft_set_mlx(t_data *img)
{
	img->selected = NULL;
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, \
	MY_SCREEN_X, MY_SCREEN_Y, "miniRT");
	img->img = mlx_new_image(img->mlx, MY_SCREEN_X, MY_SCREEN_Y);
	img->addr = mlx_get_data_addr(img->img, \
	&img->bits_per_pixel, &img->line_length, &img->endian);
}
