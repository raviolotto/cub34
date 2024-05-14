/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooknmove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:23:32 by mcamilli          #+#    #+#             */
/*   Updated: 2024/05/14 20:04:27 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	controls_working(int command, t_data *data)
{
	if (command == 65307)
		exit_point(data);
	if (command == 119 || command == 65362) //avanti
	{
		// int *x = 1;
		// int *y = 1;

		// data->prova_tex = mlx_xpm_file_to_image(data->mini.mlx, "east_texture.xpm", x, y);
		//ft_raycast1(data);
	}

	if (command == 115 || command == 65364) // indietro
	{
		double m;
		double q;
		data->rad_p = (data->player.mov_ang * CONST_RAD + (CONST_RAD / 2.0)) - 1.0471975511;
		m = -(1/tan(data->rad_p));
		q = data->player.pos_y - (m * data->player.pos_x);
		// data->prova_tex = mlx_xpm_file_to_image(data->mini.mlx, "east_texture.xpm", x, y);
		//mlx_put_image_to_window(data->mini.mlx, data->mini.mlx_win, data->prova_E, 1, 1);
	}

		//printf("stai andando indietro\n");
	if (command == 97 || command == 65361) //sinistra
	{
		data->player.last_mov_ang -= 2;
		if (data->player.last_mov_ang <= 0)
			data->player.last_mov_ang = 4320;
		ft_raycast1(data);
	}
	if (command == 100 || command == 65363) //detra
	{
		data->player.last_mov_ang += 2;
		if (data->player.last_mov_ang >= 4320)
			data->player.last_mov_ang = 0;
		ft_raycast1(data);
	}
	return (1);
}

int	exit_point(t_data *data)
{
	mlx_destroy_image(data->mini.mlx, data->mini.img);
	mlx_destroy_window(data->mini.mlx, data->mini.mlx_win);
	free_all(data);
	printf("ciaoooo");
	exit(0);
}
