/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 18:35:39 by mcamilli          #+#    #+#             */
/*   Updated: 2024/05/18 18:36:14 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
colacola la distanza tra il punto del muro e il PIANO dl giocatore,
quindievita il fisheye effect.
Hypo = la distanza effettiva tra punto e giocatore,
quindi il ray trovato prima.
*/
double	ft_ray_on_plane(t_data *data, double hypo_lenght)
{
	double	rad_hyp;

	rad_hyp = data->rad_ray - data->rad_p;
	if (rad_hyp > PI / 2)
		rad_hyp = data->rad_p + PI - data->rad_ray;
	return (sin(rad_hyp) * hypo_lenght);
}

/*
setta il ray nel caso in cui la retta sia direzionata
sul primo quadrante
*/
void	ft_set_ray_min_1079(t_data *data, double q, double m, int i)
{
	data->ray_lenght = ft_ray_on_plane(data,
			ft_ray_lenght_min_1079(data, q, m));
	if (data->player.ab_12 == 1)
		data->player.nsew = 3;
	else
		data->player.nsew = 1;
	ft_fakeray(data, i);
}

/*
setta il ray nel caso in cui la retta sia direzionata
sul secondo quadrante
*/
void	ft_set_ray_min_2160(t_data *data, double q, double m, int i)
{
	data->ray_lenght = ft_ray_on_plane(data,
			ft_ray_lenght_min_2160(data, q, m));
	if (data->player.ab_12 == 1)
		data->player.nsew = 4;
	else
		data->player.nsew = 1;
	ft_fakeray(data, i);
}

/*
setta il ray nel caso in cui la retta sia direzionata
sul terzo quadrante
*/
void	ft_set_ray_min_3239(t_data *data, double q, double m, int i)
{
	data->ray_lenght = ft_ray_on_plane(data,
			ft_ray_lenght_min_3239(data, q, m));
	if (data->player.ab_12 == 1)
		data->player.nsew = 4;
	else
		data->player.nsew = 2;
	ft_fakeray(data, i);
}

/*
setta il ray nel caso in cui la retta sia direzionata
sul quarto quadrante
*/
void	ft_set_ray_mag_3239(t_data *data, double q, double m, int i)
{
	data->ray_lenght = ft_ray_on_plane(data,
			ft_ray_lenght_mag_3239(data, q, m));
	if (data->player.ab_12 == 1)
		data->player.nsew = 3;
	else
		data->player.nsew = 2;
	ft_fakeray(data, i);
}
