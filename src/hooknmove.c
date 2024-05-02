/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooknmove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:23:32 by mcamilli          #+#    #+#             */
/*   Updated: 2024/05/02 10:40:54 by mcamilli         ###   ########.fr       */
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
		printf("stai andando a sinistra\n");
	if (command == 100 || command == 65363)
		printf("stai andando a destra\n");
	return (1);
}

int	exit_point(t_data *data)
{
	//int	a;

	// a = -1;
	if (data->mini.mlx_win)
		mlx_destroy_window(data->mini.mlx, data->mini.mlx_win);
	free_all(data);
	// free(game->mlx);
	// while (game->map[++a])
	// 	free(game->map[a]);
	// free(game->map);
	// a = 0;
	// while (a < game->en)
	// 	free(game->n[a++]);
	// free(game->n);
	exit(0);
}
