/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarlic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:23:11 by jgarlic           #+#    #+#             */
/*   Updated: 2022/02/16 10:23:12 by jgarlic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_minirt.h"

//  Convert RGB to HEX
t_vector3d	my_to_rgb(int hex)
{
	t_vector3d	rgb;

	rgb.z = hex % 256;
	hex /= 256;
	rgb.y = hex % 256;
	hex /= 256;
	rgb.x = hex % 256;
	hex /= 256;
	return (rgb);
}

//  Convert HEX to RGB
int	my_to_hex(t_vector3d rgb)
{
	int	hex;

	hex = rgb.x * 256 * 256;
	hex += rgb.y * 256;
	hex += rgb.z;
	return (hex);
}

//  Min to 0, Max to 255
int	my_clamp_color(int a)
{
	if (a < 0)
		return (0);
	else if (a > 255)
		return (255);
	return (a);
}

//  Middle between any RGB colors
t_vector3d	my_mix_rgb(t_vector3d rgb1, t_vector3d rgb2)
{
	t_vector3d	rgb3;

	rgb3.x = (rgb1.x + rgb2.x) / 2;
	rgb3.y = (rgb1.y + rgb2.y) / 2;
	rgb3.z = (rgb1.z + rgb2.z) / 2;
	return (rgb3);
}

//  Sum any HEX colors with clamp
int	my_sum_hex(int hex1, int hex2)
{
	t_vector3d	rgb1;
	t_vector3d	rgb2;
	t_vector3d	rgb3;

	rgb1 = my_to_rgb(hex1);
	rgb2 = my_to_rgb(hex2);
	rgb3.x = my_clamp_color(rgb1.x + rgb2.x);
	rgb3.y = my_clamp_color(rgb1.y + rgb2.y);
	rgb3.z = my_clamp_color(rgb1.z + rgb2.z);
	return (my_to_hex(rgb3));
}
