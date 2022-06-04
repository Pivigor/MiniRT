/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarlic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:27:38 by jgarlic           #+#    #+#             */
/*   Updated: 2022/02/16 10:27:39 by jgarlic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_minirt.h"

void	my_rotate_vector_by_direction(t_vector3d_d *orient, int angle,
		t_direction direction)
{
	t_vector3d_d	temp;

	if (orient == NULL || direction == Forward || direction == Backward)
	{
		printf("Impossible operation\n");
		return ;
	}
	*orient = my_rotate_vector_by_axis(*orient,
			my_get_direction_vector(direction), angle);
	printf("New orient\n%f\n%f\n%f\n\n", orient->x, orient->y, orient->z);
	temp = my_convert_direction_to_rotation(*orient);
	printf("New angles\n%f\n%f\n%f\n\n", temp.x, temp.y, temp.z);
}

void	my_scale(double *scale, double percent, t_direction direction)
{
	if (scale == NULL)
	{
		printf("Impossible operation\n");
		return ;
	}
	if (direction == Up)
	{
		*scale += *scale * percent;
		printf("New scale: %f", *scale);
	}
	else if (direction == Down)
	{
		*scale -= *scale * percent;
		printf("New scale: %f", *scale);
	}
	else
		printf("Scaling can't go in this direction!\n");
}

void	my_move_vector(t_vector3d_d *coord, t_direction direction)
{
	if (coord == NULL)
	{
		printf("Impossible operation\n");
		return ;
	}
	if (direction == Left)
		coord->x -= 1;
	else if (direction == Right)
		coord->x += 1;
	else if (direction == Up)
		coord->y += 1;
	else if (direction == Down)
		coord->y -= 1;
	else if (direction == Forward)
		coord->z += 1;
	else if (direction == Backward)
		coord->z -= 1;
	printf("New coord\nx=%f\ny=%f\nz=%f\n", coord->x, coord->y, coord->z);
}

void	my_transform_object(t_data *img, int mode, t_direction direction)
{
	if (img->selected == NULL)
	{
		printf("Nothing selected!\n");
		return ;
	}
	if (mode == 0)
		my_move_vector(get_coord(img->selected->content), direction);
	else if (mode == 1)
		my_rotate_vector_by_direction(get_orient(img->selected->content),
			10, direction);
	else
		my_scale(get_scale(img->selected->content), 0.1f, direction);
}
