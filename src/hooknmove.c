/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooknmove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:23:32 by mcamilli          #+#    #+#             */
/*   Updated: 2024/05/17 17:19:13 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// int ft_a(t_data *data)
// {
// 	double m;
// 	double q;
// 	double x;
// 	double y;

// 	data->rad_p = (data->player.mov_ang * CONST_RAD + (CONST_RAD / 2.0)) - 1.0471975511;
// 	if (data->rad_p < 0)
// 		data->rad_p = data->rad_p + (2 * PI);
// 	printf("data->rad_p %f, pl rad %f\n", data->rad_p, data->player.mov_ang * CONST_RAD + (CONST_RAD / 2.0));
// 	m = -(1/tan(data->rad_p));
// 	q = data->player.pos_y - (m * data->player.pos_x);
// 	if(data->rad_p <= PI && data->rad_p >= 0)
// 		x = ((0.211/ sqrt(1 + (m * m)))) + data->player.pos_x;
// 	else
// 		x = (-(0.211/ sqrt(1 + (m * m)))) + data->player.pos_x;
// 	// x = data->player.pos_x - 0.211 * cos(data->player.mov_ang * CONST_RAD);

// 	y = fma(m, x, q);
// 	if (data->map[ft_floor(y)][ft_floor(x)] == '1')
// 		return (ft_printf("ccord x = %d, coord y = %d, char map %c, \n", ft_floor(x), ft_floor(y),data->map[ft_floor(y)][ft_floor(x)]));
// 	data->player.pos_x = x;
// 	data->player.pos_y = y;
// 	ft_raycast1(data);
// 	return (0);
// }

int ft_a(t_data *data)
{
	double x;
	double y;
	double perp_angle;

	perp_angle = data->player.mov_ang * CONST_RAD - (PI / 2) - (PI / 6);
	x = data->player.pos_x + 0.211 * cos(perp_angle);
	y = data->player.pos_y + 0.211 * sin(perp_angle);
	if (data->map[ft_floor(y)][ft_floor(x)] == '1')
		return (0);
	data->player.pos_x = x;
	data->player.pos_y = y;
	ft_raycast1(data);

	return (0);
}

int ft_w(t_data *data)
{
	double x;
	double y;
	double perp_angle;

	perp_angle = data->player.mov_ang * CONST_RAD - (PI / 6);
	x = data->player.pos_x + 0.211 * cos(perp_angle);
	y = data->player.pos_y + 0.211 * sin(perp_angle);
	if (data->map[ft_floor(y)][ft_floor(x)] == '1')
		return (0);
	data->player.pos_x = x;
	data->player.pos_y = y;
	ft_raycast1(data);

    return (0);
}

int ft_s(t_data *data)
{
	double x;
	double y;
	double perp_angle;

	perp_angle = data->player.mov_ang * CONST_RAD - (PI / 6);
	x = data->player.pos_x - 0.211 * cos(perp_angle);
	y = data->player.pos_y - 0.211 * sin(perp_angle);
	if (data->map[ft_floor(y)][ft_floor(x)] == '1')
		return (0);
	data->player.pos_x = x;
	data->player.pos_y = y;
	ft_raycast1(data);

	return (0);
}

int ft_d(t_data *data)
{
	double x;
	double y;
	double perp_angle;

	perp_angle = data->player.mov_ang * CONST_RAD - (PI / 2) - (PI / 6);
	x = data->player.pos_x - 0.211 * cos(perp_angle);
	y = data->player.pos_y - 0.211 * sin(perp_angle);
	if (data->map[ft_floor(y)][ft_floor(x)] == '1')
		return (0);
	data->player.pos_x = x;
	data->player.pos_y = y;
	ft_raycast1(data);

	return (0);
}


int	controls_working(int command, t_data *data)
{
	if (command == 65307)
		exit_point(data);
	if (command == 97)
		ft_a(data);
	if (command == 100)
		ft_d(data);
	if (command == 115)
		ft_s(data);
	if (command == 119)
		ft_w(data);
	if (command == 65361)
	{
		data->player.last_mov_ang -= 8;
		if (data->player.last_mov_ang <= 0)
			data->player.last_mov_ang = 4320;
		ft_raycast1(data);
	}
	if (command == 65363)
	{
		data->player.last_mov_ang += 8;
		if (data->player.last_mov_ang >= 4320)
			data->player.last_mov_ang = 0;
		ft_raycast1(data);
	}
	return (1);
}

int	exit_point(t_data *data)
{
	mlx_destroy_image(data->mini.mlx, data->mini.img);
	mlx_destroy_window(data->mini.mlx, data->mini.mlx_win);
	free_all(data);
	printf("ciaoooo");
	exit(0);
}
