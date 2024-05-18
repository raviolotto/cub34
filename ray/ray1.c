/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:45:02 by mcamilli          #+#    #+#             */
/*   Updated: 2024/05/18 18:37:33 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
trova m e q di un ray, smista il ray in base alla sua direzione ed
esegue una funzione a parte, ne esiste una per ogni direzione.
i numeri sono in ordine di quadrante, ho divido il piano in 4320 rette
(720 è la risoluzione, 720 * (360 / 60) = 4320)
cosi è come se ogni direzione avesse un radiante "pre-assegnato"
*/
void	ft_ray_in_plane(t_data *data, int i)
{
	double	m;
	double	q;

	m = tan(data->rad_ray);
	q = data->player.pos_y - (m * data->player.pos_x);
	if (data->player.mov_ang <= 1079)
		ft_set_ray_min_1079(data, q, m, i);
	else if (data->player.mov_ang <= 2159)
		ft_set_ray_min_2160(data, q, m, i);
	else if (data->player.mov_ang <= 3239)
		ft_set_ray_min_3239(data, q, m, i);
	else
		ft_set_ray_mag_3239(data, q, m, i);
}

/*
dovrebbe essere la funzione stampa tutto
*/
void	ft_raycast1(t_data *data)
{
	int	i;

	i = -1;
	data->player.mov_ang = data->player.last_mov_ang;
	data->rad_p = (data->player.mov_ang * CONST_RAD
			+ (CONST_RAD / 2.0)) - 1.0471975511;
	while (++i < 720)
	{
		data->player.nsew = 0;
		data->rad_ray = data->player.mov_ang * CONST_RAD + (CONST_RAD / 2.0);
		if (data->player.mov_ang == 4320)
			data->player.mov_ang = 0;
		ft_ray_in_plane(data, i);
		data->player.mov_ang++;
	}
	mlx_put_image_to_window(data->mini.mlx, data->mini.mlx_win,
		data->mini.img, 0, 0);
}
