/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:45:02 by mcamilli          #+#    #+#             */
/*   Updated: 2024/04/29 16:37:32 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
data->player.mov_ang = 1600;// supponiamo di stare a nord


void ft_raycast1(t_data *data)
{
	int i;


	i = 1600;
	while(i--)
	{
		ft_ray_in_plane(data)
		if (data->player.mov_ang == 9601)
			data->player.mov_ang = 0;
	}

}

void ft_ray_in_plane(t_data *data)
{
	//2400 = ancora primo quadrante
	// 4800 ancora secondo quad
	// 7200 ancora terzo quad
}