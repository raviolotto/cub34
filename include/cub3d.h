/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacopo <jacopo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:20:02 by jcardina          #+#    #+#             */
/*   Updated: 2024/05/19 10:20:40 by jacopo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "struct.h"
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/gnl/get_next_line.h"
# include "../mlx_linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define SCREEN_W 720
# define SCREEN_H 450
# define RED	"\033[31m"
# define RESET	"\033[0m"
# define CONST_RAD 0.001454441043329
# define PI 3.141592653589793

void	ft_set_ray_mag_3239(t_data *data, double q, double m, int i);
void	ft_set_ray_min_3239(t_data *data, double q, double m, int i);
void	ft_set_ray_min_2160(t_data *data, double q, double m, int i);
void	ft_set_ray_min_1079(t_data *data, double q, double m, int i);
double	ft_ray_on_plane(t_data *data, double hypo_lenght);
double	ft_ray_lenght_mag_3239(t_data *data, double q, double m);
double	ft_ray_lenght_min_3239(t_data *data, double q, double m);
double	ft_ray_lenght_min_2160(t_data *data, double q, double m);
double	ft_ray_lenght_min_1079(t_data *data, double q, double m);
void	ray_loop_b(t_data *data, double q, double m, int dir);
void	ray_loop_a(t_data *data, double q, double m, int dir);
int		control_b(t_data *data, int dir);
int		control_a(t_data *data, int dir);
int		ft_floor(double i);
int		iswhite(char c);
int		parser(int ac, char **av, t_data *data);
int		lister(t_data *data);
int		check_info(char *str);
int		check_info2(char **info);
int		check_info3(char **info);
int		check_assets(t_data *data);
int		check_map(t_data *map);
int		color_control(t_infos *infos);
int		start(t_data *data);
char	*super_strjoin(char const *s1, char const *s2);
char	**matrix_newline(char **matrix, char *str);
void	print_matrix(char **matrix);
void	free_all(t_data *data);
void	print_list(t_infos *node);
void	map_size(t_data *data);
int		player_pos(t_data *data);
int		exit_point(t_data *data);
int		controls_working(int command, t_data *data);
void	ft_raycast1(t_data *data);
void	ft_fakeray(t_data *data, int i);
void	ft_raycast2(t_data *data);
int		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
void	assests_init(t_data *data);
t_infos	*find_in_list(t_infos *infos, int what);
void	matrix_adderal(t_data *data, char *str);

#endif
