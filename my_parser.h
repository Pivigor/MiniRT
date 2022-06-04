/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarlic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:52:10 by jgarlic           #+#    #+#             */
/*   Updated: 2022/02/16 10:52:11 by jgarlic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_PARSER_H
# define MY_PARSER_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "libs/my_global_libs.h"
# include "my_vector.h"

typedef struct s_ambient
{
	double		ratio;
	t_vector3d	rgb;
}				t_ambient;
typedef struct s_camera
{
	t_vector3d_d	coord;
	t_vector3d_d	orient;
	int				fov;
}				t_camera;
typedef struct s_light
{
	t_vector3d_d	coord;
	double			ratio;
	t_vector3d		rgb;
}				t_light;
typedef struct s_sphere
{
	t_vector3d_d	coord;
	t_vector3d_d	hit1;
	t_vector3d_d	hit2;
	double			diameter;
	t_vector3d		rgb;
}				t_sphere;
typedef struct s_plane
{
	t_vector3d_d	coord;
	t_vector3d_d	orient;
	t_vector3d_d	hit1;
	t_vector3d		rgb;
}				t_plane;
typedef struct s_cylinder
{
	t_vector3d_d	coord;
	t_vector3d_d	orient;
	t_vector3d_d	hit1;
	t_vector3d_d	hit2;
	double			diameter;
	double			height;
	t_vector3d		rgb;
}				t_cylinder;

typedef enum e_figure_type
{
	None,
	Ambient,
	Camera,
	Light,
	Sphere,
	Plane,
	Cylinder,
}	t_figure_type;
typedef struct s_parse
{
	t_figure_type	type;
	void			*object;
}				t_parse;

t_list	*my_minirt_parse(char *filename);
void	my_parse_print(t_parse *parse);
void	my_full_print(t_list *list);
void	my_parse_ambient(char **line_split, t_parse *parse);
void	my_parse_camera(char **line_split, t_parse *parse);
void	my_parse_light(char **line_split, t_parse *parse);
void	my_parse_sphere(char **line_split, t_parse *parse);
void	my_parse_plane(char **line_split, t_parse *parse);
void	my_parse_cylinder(char **line_split, t_parse *parse);
double	my_atod(char *str);
int		my_split_size(char **split);
void	my_free_split(char **split);
int		my_count_chars(char *str, char c);

#endif //MINIRT_PARSER_MY_PARSER_H
