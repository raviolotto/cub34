/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacopo <jacopo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:14:40 by mcamilli          #+#    #+#             */
/*   Updated: 2024/05/18 11:55:37 by jacopo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void assests_init(t_data *data)
{
	int x;
	int y;

	data->E.img = mlx_xpm_file_to_image(data->mini.mlx,
		(find_in_list(data->info_list, 2))->str[1], &x, &y);
	data->E.addr = mlx_get_data_addr(data->E.img, &(data->E.bits),
		&(data->E.line), &(data->E.endian));
	data->N.img = mlx_xpm_file_to_image(data->mini.mlx,
		(find_in_list(data->info_list, 3))->str[1], &x, &y);
	data->N.addr = mlx_get_data_addr(data->N.img, &(data->N.bits),
		&(data->N.line), &(data->N.endian));
	data->S.img = mlx_xpm_file_to_image(data->mini.mlx,
		(find_in_list(data->info_list, 4))->str[1], &x, &y);
	data->S.addr = mlx_get_data_addr(data->S.img, &(data->S.bits),
		&(data->S.line), &(data->S.endian));
	data->W.img = mlx_xpm_file_to_image(data->mini.mlx,
		(find_in_list(data->info_list, 5))->str[1], &x, &y);
	data->W.addr = mlx_get_data_addr(data->W.img, &(data->W.bits),
		&(data->W.line), &(data->W.endian));
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

int get_pixel(t_data *data, int x, int y)
{
	int *dst;

	if(data->player.NSEW == 4)
		dst = (void *)data->W.addr + (y * data->W.line + x * (data->W.bits / 8));
	else if(data->player.NSEW == 2)
		dst = (void *)data->S.addr + (y * data->S.line + x * (data->S.bits / 8));
	else if(data->player.NSEW == 1)
		dst = (void *)data->N.addr + (y * data->N.line + x * (data->N.bits / 8));
	else
		dst = (void *)data->E.addr + (y * data->E.line + x * (data->E.bits / 8));
	return(*(int *)dst);
}

// void get_rgb_from_pixel(int pixel, int *rosso, int *verde, int *blu) {
//     // Maschere per estrarre i singoli canali
//     int rosso_mask = 0xFF0000;
//     int verde_mask = 0x00FF00;
//     int blu_mask = 0x0000FF;

//     // Estrai i valori dei singoli canali
//     *rosso = (pixel & rosso_mask) >> 16;
//     *verde = (pixel & verde_mask) >> 8;
//     *blu = pixel & blu_mask;
// }

/*
void ft_fakeray(t_data *data, int i)
{
	int p;
	double point;
	int index;

	p = (623.25 / fabs(data->ray_lenght) / 2.0);
	if (p > 225)
		p = 225;
	ft_floor_n_ceil(data, i);
	if (data->player.AB_12 == 1)
		point = data->ray_y - floor(data->player.dir_y);
	else
		point = data->ray_x - floor(data->player.dir_x);
	int x = (int)round(point / 0.015625);
	double image_part = (p * 1.0) / 32;
	//printf("point = %f\n", point);
	//double ptwo = 623.25 / fabs(data->ray_lenght);
	int pzero = 225 - p;
	while (p > 0)
	{
		//printf("y = %d\n", (int)round(ptwo * ((225 - p) - pzero) / 64));
		//printf("y = %f\n", (((225 + p) - pzero) / image_part));
		index = get_pixel(data, x, (int)round(((225 - p) - pzero) / image_part));
		my_mlx_pixel_put(data, i, (225 - p), index);
		index = get_pixel(data, x, (int)round(((225 + p) - pzero) / image_part));
		my_mlx_pixel_put(data, i, (225 + p), index);
		p--;
	}
	index = get_pixel(data, x, 32);
	my_mlx_pixel_put(data, i, 225, index);
	// printf("===================================retta n%d, ray lenght %f, ray_x %f, ray_y %f, mov_ang %f\n", i, data->ray_lenght, data->ray_x, data->ray_y, data->player.mov_ang);
}
*/

void ft_fakeray(t_data *data, int i)
{
	int p;
	int x;
	int color;
	double point;
	double image_part;

	p = (623.25 / data->ray_lenght);
	ft_floor_n_ceil(data, i);
	if (data->player.AB_12 == 1)
		point = data->ray_y - floor(data->ray_y);
	else
		point = data->ray_x - floor(data->ray_x);
	x = (int)round(point / 0.015625);
	image_part = (p * 1.0) / 64;
	 if (p > 450)
	 	p = 450;
	p = p / 2;
	while (p >= 0)
	{
		color = get_pixel(data, x - 64, (int)round(32 + (p / image_part)));
		my_mlx_pixel_put(data, i, 225 + p, color);
		color = get_pixel(data, x, (int)round(32 - (p / image_part)));
		my_mlx_pixel_put(data, i, 225 - p, color);
		p--;
	}
}

// void ft_fakeray(t_data *data, int i)
// {
// 	int p;

// 	p = (623.25 / fabs(data->ray_lenght) / 2.0);
// 	if (p > 225)
// 		p = 225;
// 	ft_floor_n_ceil(data, i);
// 	while (p >= 0)
// 	{
// 			my_mlx_pixel_put(data, i, (225 - p), create_trgb(0, 020, 100, 100));
// 			my_mlx_pixel_put(data, i, (225 + p), create_trgb(0, 020, 100, 100));
// 		p--;
// 	}
// 	my_mlx_pixel_put(data, i, 225, create_trgb(0, 020, 100, 100));
// 	// printf("===================================retta n%d, ray lenght %f, ray_x %f, ray_y %f, mov_ang %f\n", i, data->ray_lenght, data->ray_x, data->ray_y, data->player.mov_ang);
// }
