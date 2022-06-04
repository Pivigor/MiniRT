/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_minirt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarlic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:26:22 by jgarlic           #+#    #+#             */
/*   Updated: 2022/02/16 10:26:23 by jgarlic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_minirt.h"

void	show_menu(void)
{
	printf("w/s : shift by z axis\n"
		"a/d : shift by x axis\n"
		"f/c : shift by y axis\n"
		"e   : figure\n"
		"g   : event\n"
		"b/v : switch camera\n"
		"Press Q or Esc to quit.\n");
}

int	my_check_parselist(t_list *parse_list)
{
	t_parse	*parse;
	int		camera;
	int		light;

	camera = 0;
	light = 0;
	while (parse_list != NULL)
	{
		parse = parse_list->content;
		if (parse->type == Camera)
			camera = 1;
		if (parse->type == Light)
			light = 1;
		parse_list = parse_list->next;
	}
	return (camera && light);
}

int	main(int argc, char **argv)
{
	t_data	*img;
	t_list	*parse_list;

	if (argc != 2)
	{
		printf("Bad args!\n");
		exit(0);
	}
	parse_list = my_minirt_parse(argv[1]);
	if (parse_list == NULL || my_check_parselist(parse_list) == 0)
	{
		printf("Parsing ERROR\n");
		exit(0);
	}
	printf("Parsing OK\n");
	img = malloc(sizeof(t_data));
	ft_set_mlx(img);
	img->parse_list = parse_list;
	my_cameramanager_init(img);
	my_lightmanager_init(img);
	render_start(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	show_menu();
	ft_hooks(img);
	exit(0);
}
