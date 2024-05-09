/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:14:40 by mcamilli          #+#    #+#             */
/*   Updated: 2024/05/09 12:37:17 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void ft_fakeray(t_data *data, int i)
{	
	int p;
	int i;
	
	p = ((623.25 / data->ray_lenght) / 2.0);
	if (p > 225)
		p = 225;
	while (p > 0)
	{
		mlx_pixel_put(data->mini.mlx, data->mini.mlx_win, i, 225 - p, 0xFF0000 );
		mlx_pixel_put(data->mini.mlx, data->mini.mlx_win, i, 225 + p, 0xFF0000 );
		p--;
	}
	mlx_pixel_put(data->mini.mlx, data->mini.mlx_win, i, 225, 0xFF0000 );
	
	//printf("retta n%d, ray lenght %f, ray_x %f, ray_y %f, mov_ang %f\n", i, data->ray_lenght, data->ray_x, data->ray_y, data->player.mov_ang);
}