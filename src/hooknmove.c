/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooknmove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <jcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:23:32 by mcamilli          #+#    #+#             */
/*   Updated: 2024/05/10 16:04:41 by jcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	controls_working(int command, t_data *data)
{
	if (command == 65307)
		exit_point(data);
	if (command == 119 || command == 65362)
		printf("stai andando avanti\n");
	if (command == 115 || command == 65364)
		printf("stai andando indietro\n");
	if (command == 97 || command == 65361)
	{
		data->player.last_mov_ang -= 2;
		if (data->player.last_mov_ang <= 0)
			data->player.last_mov_ang = 4320;
		ft_raycast1(data);
	}
	if (command == 100 || command == 65363)
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
