/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_lenght.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 18:29:44 by mcamilli          #+#    #+#             */
/*   Updated: 2024/05/18 18:30:55 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
ritorna la lunghezza del ray sul primo quadrante, setta coord ray x e y.
ovvero del punto di collisione tra ray e muro il suo code é 1
*/
double	ft_ray_lenght_min_1079(t_data *data, double q, double m)
{
	data->hypotena = -1;
	data->hypotenb = -1;
	data->newx1a = (int)ceil(data->player.pos_x);
	data->newy1b = (int)ceil(data->player.pos_y);
	ray_loop_a(data, q, m, 0);
	ray_loop_b(data, q, m, 0);
	if ((data->hypotena + data->hypotenb) == -2)
		return (0);
	if ((data->hypotenb <= data->hypotena
			|| data->hypotena < 0) && data->hypotenb >= 0)
	{
		return (data->hypotenb);
	}
	if (control_a(data, 0))
	{
		return (data->hypotena);
	}
	return (0);
}

/*
ritorna la lunghezza del ray sul secondo quadrante, setta coord ray x e y.
ovvero del punto di collisione tra ray e muro il code é 2
*/
double	ft_ray_lenght_min_2160(t_data *data, double q, double m)
{
	data->hypotena = -1;
	data->hypotenb = -1;
	data->newx1a = floor(data->player.pos_x);
	data->newy1b = ceil(data->player.pos_y);
	ray_loop_a(data, q, m, 1);
	ray_loop_b(data, q, m, 0);
	if (data->hypotena + data->hypotenb == -2)
		return (0);
	if ((data->hypotenb <= data->hypotena
			|| data->hypotena < 0) && data->hypotenb >= 0)
		return (data->hypotenb);
	if (control_a(data, 1))
		return (data->hypotena);
	return (0);
}

/*
ritorna la lunghezza del ray sul terzo quadrante, setta coord ray x e y.
ovvero del punto di collisione tra ray e muro
*/
double	ft_ray_lenght_min_3239(t_data *data, double q, double m)
{
	data->hypotena = -1;
	data->hypotenb = -1;
	data->newx1a = ft_floor(data->player.pos_x);
	data->newy1b = ft_floor(data->player.pos_y);
	ray_loop_a(data, q, m, 1);
	ray_loop_b(data, q, m, 1);
	if (data->hypotena + data->hypotenb == -2)
		return (0);
	if ((data->hypotenb <= data->hypotena
			|| data->hypotena < 0) && data->hypotenb >= 0)
		return (data->hypotenb);
	if (control_a(data, 1))
		return (data->hypotena);
	return (0);
}

/*
ritorna la lunghezza del ray sul quarto quadrante, setta coord ray x e y.
ovvero del punto di collisione tra ray e muro
*/
double	ft_ray_lenght_mag_3239(t_data *data, double q, double m)
{
	data->hypotena = -1;
	data->hypotenb = -1;
	data->newx1a = ceil(data->player.pos_x);
	data->newy1b = floor(data->player.pos_y);
	ray_loop_a(data, q, m, 0);
	ray_loop_b(data, q, m, 1);
	if (data->hypotena + data->hypotenb == -2)
		return (0);
	if ((data->hypotenb <= data->hypotena
			|| data->hypotena < 0) && data->hypotenb >= 0)
		return (data->hypotenb);
	else if (control_a(data, 0))
		return (data->hypotena);
	return (0);
}
