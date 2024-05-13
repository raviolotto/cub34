/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:14:40 by mcamilli          #+#    #+#             */
/*   Updated: 2024/05/13 19:59:56 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void fake_assests_init(t_data *data)
{
	int x;
	int y;

	data->prova_E = mlx_xpm_file_to_image(data->mini.mlx, "../assets/east_texture.xpm", &x, &y);
	data->prova_N = mlx_xpm_file_to_image(data->mini.mlx, "../assets/north_texture.xpm", &x, &y);
	data->prova_W = mlx_xpm_file_to_image(data->mini.mlx, "../assets/west_texture.xpm", &x, &y);
	data->prova_S = mlx_xpm_file_to_image(data->mini.mlx, "../assets/south_texture.xpm", &x, &y);
}

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

/*
void ft_fakeray(t_data *data, int i)
{
	int p;

	p = (623.25 / fabs(data->ray_lenght) / 2.0);
	if (p > 225)
		p = 225;
	ft_floor_n_ceil(data, i);
	while (p > 0)
	{
			my_mlx_pixel_put(data, i, (225 - p), create_trgb(0, 020, 100, 100));
			my_mlx_pixel_put(data, i, (225 + p), create_trgb(0, 020, 100, 100));
		p--;
	}
	my_mlx_pixel_put(data, i, 225, create_trgb(0, 020, 100, 100));
	// printf("===================================retta n%d, ray lenght %f, ray_x %f, ray_y %f, mov_ang %f\n", i, data->ray_lenght, data->ray_x, data->ray_y, data->player.mov_ang);
}
*/

void ft_fakeray(t_data *data, int i)
{
	int p;
	double point;
	int index;

	p = (623.25 / fabs(data->ray_lenght) / 2.0);
	if (p > 225)
		p = 225;
	ft_floor_n_ceil(data, i);
	int bpp; // Bits per pixel
	int size_line; // Lunghezza della riga in byte
	int endian; // Controllo endian
	if (data->player.AB_12 == 1)
		point = data->player.dir_y - floor(data->player.dir_y);
	else
		point = data->player.dir_x - floor(data->player.dir_x);
	int x = (int)round(point / 0.015625);
	mlx_get_data_addr(data->prova_E, &bpp, &size_line, &endian);
	char *image_data = mlx_get_data_addr(data->prova_E, &bpp, &size_line, &endian);
	double image_part = (p * 0.1) / 32;
	while (p > 0)
	{
		index = (x * (bpp / 8)) + ((int)round(32 - ((p * 0.1) / image_part)) * size_line);
		my_mlx_pixel_put(data, i, (225 - p), create_trgb(0, image_data[index], image_data[index + 1], image_data[index + 2]));
		index = (x * (bpp / 8)) + ((int)round(32 + ((p * 0.1) / image_part)) * size_line);
		my_mlx_pixel_put(data, i, (225 + p), create_trgb(0, image_data[index], image_data[index + 1], image_data[index + 2]));
		p--;
	}
	index = ((x * (bpp / 8)) + (32 * size_line));
	my_mlx_pixel_put(data, i, 225, create_trgb(0, image_data[index], image_data[index + 1], image_data[index + 2]));
	// printf("===================================retta n%d, ray lenght %f, ray_x %f, ray_y %f, mov_ang %f\n", i, data->ray_lenght, data->ray_x, data->ray_y, data->player.mov_ang);
}
*/
