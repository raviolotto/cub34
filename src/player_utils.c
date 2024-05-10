/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <jcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:05:21 by jcardina          #+#    #+#             */
/*   Updated: 2024/05/10 14:28:38 by jcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub3d.h"
/*
definisce la direzione e salva info sulla direzione del player.
*/
void	player_dir(t_data *data)
{
	char	c;

	c = data->player.c;
	if (c == 'W')
		data->player.last_mov_ang = 1800;
	else if (c == 'E')
		data->player.last_mov_ang = 3960;
	else if (c == 'N')
		data->player.last_mov_ang = 2880;
	else if (c == 'S')
		data->player.last_mov_ang = 720;
}

void	player_pos(t_data *data)
{
	int	y;
	int	x;

	y = -1;
	while(data->map[++y])
	{
		x = 0;
		while(data->map[y][x])
		{
			if(data->map[y][x] == 'N' || data->map[y][x] == 'S'
				|| data->map[y][x] == 'E' || data->map[y][x] == 'W')
				{
					data->player.pos_x = (float)(x + 1);
					data->player.pos_y = y + 1;
					data->player.c = data->map[y][x];
					player_dir(data);
					return ;
				}
			x++;
		}
	}
}
