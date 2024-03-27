/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <jcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:58:24 by jcardina          #+#    #+#             */
/*   Updated: 2024/03/25 19:06:28 by jcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	start(t_data *data)
{
	data->mini.mlx = mlx_init();
	if(!data->mini.mlx)
		return(1);
	data->mini.mlx_win = mlx_new_window(data->mini.mlx ,SCREEN_W, SCREEN_H, "cubitron");
	data->mini.img.img = mlx_new_image(data->mini.mlx, SCREEN_W, SCREEN_H);
	data->mini.img.addr = mlx_get_data_addr(data->mini.img.img, &data->mini.img.bits, &data->mini.img.line, &data->mini.img.endian);
	
	mlx_loop(data->mini.mlx);
	return(0);
}
