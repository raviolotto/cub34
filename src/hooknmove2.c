/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooknmove2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:23:32 by mcamilli          #+#    #+#             */
/*   Updated: 2024/05/15 11:47:05 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void ft_w(t_data *data)
{
	double m;
	double q;
	double x;
	double y;
	data->rad_p = (data->player.mov_ang * CONST_RAD + (CONST_RAD / 2.0)) - 1.0471975511;
	m = -(1/tan(data->rad_p));
	q = data->player.pos_y - (m * data->player.pos_x);
	x = ((0.211/ sqrt(1 + (m * m)))) + data->player.pos_x;
	y = fma(m, x, q);
	if (data->map[ft_floor(y)][ft_floor(x)] != '0')
		return ;
	data->player.pos_x = x;
	data->player.pos_y = y;
	ft_raycast1(data);
}
void	ft_s(t_data *data)
{
	double m;
	double q;
	double x;
	double y;
	data->rad_p = (data->player.mov_ang * CONST_RAD + (CONST_RAD / 2.0)) - 1.0471975511;
	m = -(1/tan(data->rad_p));
	q = data->player.pos_y - (m * data->player.pos_x);
	x = (- (0.211/ sqrt(1 + (m * m)))) + data->player.pos_x;
	y = fma(m, x, q);
	if (data->map[ft_floor(y)][ft_floor(x)] != '0')
		return ;
	data->player.pos_x = x;
	data->player.pos_y = y;
	ft_raycast1(data);
}

void	ft_a(t_data *data)
{
	double m;
	double q;
	double x;
	double y;
	data->rad_p = (data->player.mov_ang * CONST_RAD + (CONST_RAD / 2.0)) - 1.0471975511;
	m = (tan(data->rad_p));
	q = data->player.pos_y - (m * data->player.pos_x);
	x = (- (0.211/ sqrt(1 + (m * m)))) + data->player.pos_x;
	y = fma(m, x, q);
	if (data->map[ft_floor(y)][ft_floor(x)] != '0')
		return ;
	data->player.pos_x = x;
	data->player.pos_y = y;
	ft_raycast1(data);
}

void	ft_d(t_data *data)
{
	double m;
	double q;
	double x;
	double y;
	data->rad_p = (data->player.mov_ang * CONST_RAD + (CONST_RAD / 2.0)) - 1.0471975511;
	m = (tan(data->rad_p));
	q = data->player.pos_y - (m * data->player.pos_x);
	x = ((0.211/ sqrt(1 + (m * m)))) + data->player.pos_x;
	y = fma(m, x, q);
	if (data->map[ft_floor(y)][ft_floor(x)] != '0')
		return ;
	data->player.pos_x = x;
	data->player.pos_y = y;
	ft_raycast1(data);
}

int ft_wasd(int command, t_data *data)
{
	if (command == 119 || command == 65362) // avanti
		ft_w(data);
	if (command == 115 || command == 65364) // indietro
		ft_s(data);
	if (command == 97) //sinistra
		ft_a(data);
	if (command == 100 ) //destra
		ft_d(data);
	return (0);
}
