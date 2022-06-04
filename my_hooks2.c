/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_hooks2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarlic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:24:03 by jgarlic           #+#    #+#             */
/*   Updated: 2022/02/16 10:24:04 by jgarlic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_minirt.h"

int	is_key(int key)
{
	if (key == 12 || key == 13 || key == 0
		|| key == 1 || key == 2 || key == 15 || key == 17
		|| key == 3 || key == 5 || key == 9 || key == 11 || key == 14
		|| key == 8 || key == 7 || key == 24 || key == 27 || key == 53)
		return (1);
	else
		return (0);
}

int	game_quit(t_data *img)
{
	(void)img;
	write(1, "game quit\n", 10);
	mlx_destroy_image(img->mlx, img->img);
	mlx_destroy_window(img->mlx, img->mlx_win);
	exit(0);
}
