/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooknmove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:23:32 by mcamilli          #+#    #+#             */
/*   Updated: 2024/05/15 12:02:36 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	controls_working(int command, t_data *data)
{
	if (command == 65307)
		exit_point(data);
	// if (command == 119 || command == 65362 //avanti
	// 	|| command == 115 || command == 65364//indietro
	// 	|| command == 97 || command == 100 ) //sinistra destra
	// 		ft_wasd(command, data);
	if (command == 65361) //sinistra
	{
		//printf("sinistra");
		data->player.last_mov_ang -= 2;
		if (data->player.last_mov_ang <= 0)
			data->player.last_mov_ang = 4320;
		ft_raycast1(data);
	}
	if (command == 65363) //detra sinistra
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
