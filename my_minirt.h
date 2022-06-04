/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_minirt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarlic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:45:55 by jgarlic           #+#    #+#             */
/*   Updated: 2022/02/16 10:45:56 by jgarlic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_MINIRT_H
# define MY_MINIRT_H
# include <fcntl.h>
# include <sys/stat.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# include "my_global_libs.h"
# include "my_parser.h"

# define MY_SCREEN_X 900
# define MY_SCREEN_Y 400

typedef struct s_shader
{
	t_vector3d	rgb_ambient;
	t_vector3d	rgb_diffuse;
	t_vector3d	rgb_specular;
}	t_shader;

typedef struct s_camera_manager
{
	t_camera	**cameras;
	int			count;
	int			current;
}	t_camera_manager;

typedef struct s_light_manager
{
	t_light	**lights;
	int		count;
	int		current;
}	t_light_manager;

typedef struct s_render_manager
{
	double	depth;
	int		color;
	int		init;
	t_list	*object;
}	t_render_manager;

typedef struct s_data {
	void				*img;
	char				*addr;
	t_list				*parse_list;
	t_camera_manager	cameramanager;
	t_light_manager		lightmanager;
	t_render_manager	temprendervalue;
	t_render_manager	finalrender[MY_SCREEN_X][MY_SCREEN_Y];
	t_vector2d_f		xy[MY_SCREEN_X][MY_SCREEN_Y];
	t_ambient			g_ambient;
	t_light				*light;
	t_list				*selected;
	void				*mlx;
	void				*mlx_win;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}				t_data;

void			ft_set_mlx(t_data *img);
void			my_pixel_put(t_data *img, int x, int y, int color);
void			render_start(t_data *img);
void			my_calc_ambient(t_data *img);
void			my_reset_temp(t_data *img);
void			my_rendermanager_init(t_data *img);

t_vector3d		get_ambient(t_data *img);
void			shader_to_shadow(t_shader *shader);
double			d_cyl(t_cylinder *cylinder);
double			d_cyl_2(t_cylinder *cylinder);
int				cyl_color_init(t_data *img, t_cylinder *cylinder,
					t_light *light);
int				my_render_cyl(t_data *img, t_cylinder *cylinder,
					t_vector3d_d n);
int				plane_color_init(t_data *img, t_plane *plane, t_light *light,
					t_vector3d_d n);
int				my_render_plane(t_data *img, t_plane *plane, t_vector3d_d n);
int				my_sphere_color(t_data *img, t_sphere *sphere, t_light *light);
int				my_render_sphere(t_data *img, t_sphere *sphere, t_vector3d_d n);

t_camera		*my_cameramanager_init(t_data *img);
t_camera		*my_cameramanager_current(t_data *img);
t_camera		*my_cameramanager_next(t_data *img);
t_camera		*my_cameramanager_prev(t_data *img);
t_camera		*my_default_camera(t_data *img);

t_light			*my_lightmanager_init(t_data *img);
t_light			*my_lightmanager_current(t_data *img);
t_light			*my_lightmanager_next(t_data *img);
t_light			*my_default_light(t_data *img);

int				my_count_types(t_list *parse_list, t_figure_type type);
double			d_from_camera(t_camera *camera, double x, double y, double z);
t_vector3d_d	calc_n(t_camera *camera, t_vector2d_f xy);
t_vector3d		my_to_rgb(int hex);
int				my_to_hex(t_vector3d rgb);
int				my_clamp_color(int a);
t_vector3d		my_mix_rgb(t_vector3d rgb1, t_vector3d rgb2);
int				my_sum_hex(int hex1, int hex2);

void			ft_hooks(t_data *img);
int				game_quit(t_data *img);
int				is_key(int key);

void			my_transform_object(t_data *img, int mode,
					t_direction direction);
t_vector3d_d	*get_coord(t_parse *object);
t_vector3d_d	*get_orient(t_parse *object);
double			*get_scale(t_parse *object);

t_vector3d		my_compute_shader(t_shader shader, t_vector3d rgb_texture);
int				compute_shadow(t_data *img, t_plane *plane, t_vector3d_d n);
int				compute_shadow2(t_data *img, t_sphere *sphere, t_vector3d_d n);
int				compute_shadow3(t_data *img, t_cylinder *cylinder,
					t_vector3d_d n);
int				is_hit_cylinder1(t_vector3d_d start, t_cylinder *cylinder,
					t_vector3d_d n);
int				is_hit_sphere112(t_vector3d_d start, t_sphere *sphere,
					t_vector3d_d n, t_vector3d_d d);

t_vector3d_d	ft_reflect_ray(t_vector3d_d R, t_vector3d_d N);

void			my_rotate_vector_by_direction(t_vector3d_d *orient,
					int angle, t_direction direction);

#endif
