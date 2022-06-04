/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarlic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:23:55 by jgarlic           #+#    #+#             */
/*   Updated: 2022/02/16 10:23:57 by jgarlic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_minirt.h"

void	do_key2(int key, t_data *img, int toggle)
{
	if (key == 0)
		my_transform_object(img, toggle, Left);
	if (key == 2)
		my_transform_object(img, toggle, Right);
	if (key == 13)
		my_transform_object(img, toggle, Forward);
	if (key == 1)
		my_transform_object(img, toggle, Backward);
	if (key == 3)
		my_transform_object(img, toggle, Up);
	if (key == 8)
		my_transform_object(img, toggle, Down);
	if (key == 14)
	{
		if (img->selected == NULL || img->selected->next == NULL)
			img->selected = img->parse_list;
		else
			img->selected = img->selected->next;
		printf("Selected:\n");
		my_parse_print(img->selected->content);
		printf("\n");
	}
}

void	do_key(int key, t_data *img)
{
	static int	toggle;

	printf("%d\n", key);
	if (key == 5)
	{
		toggle++;
		if (toggle == 1)
			printf("Rotation mode\n");
		else if (toggle == 2)
			printf("Scaling mode\n");
		else if (toggle == 3)
		{
			toggle = 0;
			printf("Moving mode\n");
		}
	}
	if (key == 9)
		my_cameramanager_prev(img);
	if (key == 11)
		my_cameramanager_next(img);
	do_key2(key, img, toggle);
}

int	key_hook(int keycode, t_data *img)
{
	if (is_key(keycode) && (keycode != 12 && keycode != 53))
	{
		do_key(keycode, img);
		if (keycode == 5 || keycode == 14)
			return (0);
		mlx_destroy_image(img->mlx, img->img);
		img->img = mlx_new_image(img->mlx, MY_SCREEN_X, MY_SCREEN_Y);
		img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
				&img->line_length, &img->endian);
		render_start(img);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	}
	if ((is_key(keycode)) && (keycode == 12 || keycode == 53))
	{
		mlx_destroy_image(img->mlx, img->img);
		mlx_destroy_window(img->mlx, img->mlx_win);
		exit(0);
	}
	return (0);
}

int	my_mouse_hook(int button, int x, int y, t_data *img)
{
	t_vector3d	rgb;

	if (img->finalrender[x][y].object != NULL)
	{
		printf("Mouse: %d %d %d\n", button, x, y);
		img->selected = img->finalrender[x][y].object;
		rgb = my_to_rgb(img->finalrender[x][y].color);
		printf("Pixel: %d %d %d\n", rgb.x, rgb.y, rgb.z);
		printf("Selected:\n");
		my_parse_print(img->selected->content);
		printf("\n");
	}
	return (0);
}

void	ft_hooks(t_data *img)
{
	mlx_hook(img->mlx_win, 17, 0, game_quit, img);
	mlx_mouse_hook(img->mlx_win, my_mouse_hook, img);
	mlx_key_hook(img->mlx_win, key_hook, img);
	mlx_loop(img->mlx);
}
