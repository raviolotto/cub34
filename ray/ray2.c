/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <jcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:14:40 by mcamilli          #+#    #+#             */
/*   Updated: 2024/05/10 14:57:18 by jcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_infos *find_in_list(t_infos *infos, int what)
{
	t_infos *tmp;
	tmp = infos;
	while(tmp->what != what)
		tmp = tmp->next;
	return(tmp);
}

void ft_floor_n_ceil(t_data *data, int col)
{
	int i;
	t_infos *floor;
	t_infos *ceil;

	i = 0;
	floor = find_in_list(data->info_list, 7);
	ceil = find_in_list(data->info_list, 6);
	while(i < 225)
	{
		my_mlx_pixel_put(data, col, i, create_trgb(0, (ft_atoi(ceil->color[0])), (ft_atoi(ceil->color[1])), (ft_atoi(ceil->color[2]))));
		i++;
	}
	while(i < 450)
	{
		my_mlx_pixel_put(data, col, i, create_trgb(0, (ft_atoi(floor->color[0])), (ft_atoi(floor->color[1])), (ft_atoi(floor->color[2]))));
		i++;
	}
}

void ft_fakeray(t_data *data, int i)
{
	int p;

	p = (623.25 / fabs(data->ray_lenght) / 2.0);
	if (p > 225)
		p = 225;
	ft_floor_n_ceil(data, i);
	while (p > 0)
	{
			my_mlx_pixel_put(data, i, (225 - p), create_trgb(0, 255, 0, 0));
			my_mlx_pixel_put(data, i, (225 + p), create_trgb(0, 255, 0, 0));
		p--;
	}
	my_mlx_pixel_put(data, i, 225, create_trgb(0, 255, 0, 0));
	// printf("===================================retta n%d, ray lenght %f, ray_x %f, ray_y %f, mov_ang %f\n", i, data->ray_lenght, data->ray_x, data->ray_y, data->player.mov_ang);
}
