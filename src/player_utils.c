/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacopo <jacopo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:05:21 by jcardina          #+#    #+#             */
/*   Updated: 2024/05/18 12:28:43 by jacopo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	player_dir(t_data *data, char c)
{
	if (c == 'W')
		data->player.last_mov_ang = 1800;
	else if (c == 'E')
		data->player.last_mov_ang = 3960;
	else if (c == 'N')
		data->player.last_mov_ang = 2880;
	else if (c == 'S')
		data->player.last_mov_ang = 720;
}

int	player_pos(t_data *data)
{
	int	y;
	int	x;
	int	flag;

	y = -1;
	flag = 0;
	while (data->map[++y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S'
				|| data->map[y][x] == 'E' || data->map[y][x] == 'W')
			{
				if (flag == 1)
					return (0);
				data->player.pos_x = (float)(x + 0.5);
				data->player.pos_y = y + 0.5;
				player_dir(data, data->map[y][x]);
				flag = 1;
			}
			x++;
		}
	}
	return (flag);
}
