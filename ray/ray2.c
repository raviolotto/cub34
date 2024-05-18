/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:14:40 by mcamilli          #+#    #+#             */
/*   Updated: 2024/05/18 18:25:58 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	assests_init(t_data *data)
{
	int	x;
	int	y;

	data->e.img = mlx_xpm_file_to_image(data->mini.mlx,
			(find_in_list(data->info_list, 2))->str[1], &x, &y);
	data->e.addr = mlx_get_data_addr(data->e.img, &(data->e.bits),
			&(data->e.line), &(data->e.endian));
	data->n.img = mlx_xpm_file_to_image(data->mini.mlx,
			(find_in_list(data->info_list, 3))->str[1], &x, &y);
	data->n.addr = mlx_get_data_addr(data->n.img, &(data->n.bits),
			&(data->n.line), &(data->n.endian));
	data->s.img = mlx_xpm_file_to_image(data->mini.mlx,
			(find_in_list(data->info_list, 4))->str[1], &x, &y);
	data->s.addr = mlx_get_data_addr(data->s.img, &(data->s.bits),
			&(data->s.line), &(data->s.endian));
	data->w.img = mlx_xpm_file_to_image(data->mini.mlx,
			(find_in_list(data->info_list, 5))->str[1], &x, &y);
	data->w.addr = mlx_get_data_addr(data->w.img, &(data->w.bits),
			&(data->w.line), &(data->w.endian));
}

t_infos	*find_in_list(t_infos *infos, int what)
{
	t_infos	*tmp;

	tmp = infos;
	while (tmp->what != what)
		tmp = tmp->next;
	return (tmp);
}

void	ft_floor_n_ceil(t_data *data, int col)
{
	int		i;
	t_infos	*floor;
	t_infos	*ceil;

	i = 0;
	floor = find_in_list(data->info_list, 7);
	ceil = find_in_list(data->info_list, 6);
	while (i < 225)
	{
		my_mlx_pixel_put(data, col, i, create_trgb(0, (ft_atoi(ceil->color[0])),
				(ft_atoi(ceil->color[1])), (ft_atoi(ceil->color[2]))));
		i++;
	}
	while (i < 450)
	{
		my_mlx_pixel_put(data, col, i, create_trgb(0,
				(ft_atoi(floor->color[0])), (ft_atoi(floor->color[1])),
				(ft_atoi(floor->color[2]))));
		i++;
	}
}

int	get_pixel(t_data *data, int x, int y)
{
	int	*dst;

	if (data->player.nsew == 4)
		dst = (void *)data->w.addr
			+ (y * data->w.line + x * (data->w.bits / 8));
	else if (data->player.nsew == 2)
		dst = (void *)data->s.addr
			+ (y * data->s.line + x * (data->s.bits / 8));
	else if (data->player.nsew == 1)
		dst = (void *)data->n.addr
			+ (y * data->n.line + x * (data->n.bits / 8));
	else
		dst = (void *)data->e.addr
			+ (y * data->e.line + x * (data->e.bits / 8));
	return (*(int *)dst);
}

void	ft_fakeray(t_data *data, int i)
{
	int		p;
	int		x;
	int		color;
	double	point;
	double	image_part;

	p = (623.25 / data->ray_lenght);
	ft_floor_n_ceil(data, i);
	point = data->ray_x - floor(data->ray_x);
	if (data->player.ab_12 == 1)
		point = data->ray_y - floor(data->ray_y);
	x = (int)(point / 0.015625);
	image_part = (p * 1.0) / 64;
	if (p > 450)
		p = 450;
	p = p / 2;
	color = get_pixel(data, x, 63);
	my_mlx_pixel_put(data, i, 225 + p, color);
	while (--p >= 0)
	{
		color = get_pixel(data, x, (int)round(32 + (int)(p / image_part)));
		my_mlx_pixel_put(data, i, 225 + p, color);
		color = get_pixel(data, x, (int)round(32 - (int)(p / image_part)));
		my_mlx_pixel_put(data, i, 225 - p, color);
	}
}
