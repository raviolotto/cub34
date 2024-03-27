/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <jcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:05:21 by jcardina          #+#    #+#             */
/*   Updated: 2024/03/27 19:42:34 by jcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub3d.h"

void	player_dir(t_data *data)
{
	char	c;

	c = data->player.c;
	if (c == 'W')
	{
		write(1, "a\n", 2);
		data->player.dir_y = 1;
		data->player.plane_x = -0.66;
	}
	else if (c == 'E')
	{
		write(1, "a\n", 2);
		data->player.dir_y = -1;
		data->player.plane_x = 0.66;
	}
	else if (c == 'N')
	{
		write(1, "a\n", 2);
		data->player.dir_x = -1;
		data->player.plane_y = -0.66;
	}
	else (c == 'S')
	{
		write(1, "a\n", 2);
		data->player.dir_x = 1;
		data->player.plane_y = 0.66;
	}
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
