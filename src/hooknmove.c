/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooknmove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacopo <jacopo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:23:32 by mcamilli          #+#    #+#             */
/*   Updated: 2024/05/18 11:26:01 by jacopo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_a(t_data *data)
{
	double	x;
	double	y;
	double	perp_angle;

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

int	ft_w(t_data *data)
{
	double	x;
	double	y;
	double	perp_angle;

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

int	ft_s(t_data *data)
{
	double	x;
	double	y;
	double	perp_angle;

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

int	ft_d(t_data *data)
{
	double	x;
	double	y;
	double	perp_angle;

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
