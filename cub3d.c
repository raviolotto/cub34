/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:18:50 by jcardina          #+#    #+#             */
/*   Updated: 2024/05/14 10:03:26 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

void	init(t_data *data)
{
	data->map = NULL;
	data->info_list = NULL;
	data->player.pos_x = 0;
	data->player.pos_y = 0;
	data->player.mov_ang = 0;
	data->ray_x = 0;
	data->ray_y = 0;
	data->rad_p = 0;
	data->rad_ray = 0;
	data->ray_uncasted =0;
}

int	otherexit(void)
{
	exit(0);
}

int main(int ac, char **av)
{
	t_data data;

	init(&data);
	if(parser(ac, av, &data) == 1)
	{
		printf(":(\n");
		free_all(&data);
		return(1);
	}
	//debuginfo
/*	print_list(data.info_list);
	printf(" pos x player%f\n", data.player.pos_x);
	printf(" pos y player%f\n", data.player.pos_y);
	printf(" data.map_h = %d, data map_l = %d\n", data.map_h, data.map_l);
	print_matrix(data.map);*/
	//fine debug info
	if(1)
	{

		data.mini.mlx = mlx_init();
		data.mini.mlx_win = mlx_new_window(data.mini.mlx ,SCREEN_W, SCREEN_H, "cubitron");
		data.mini.img = mlx_new_image(data.mini.mlx, SCREEN_W, SCREEN_H);
		data.mini.addr = mlx_get_data_addr(data.mini.img, &data.mini.bits_per_pixel, &data.mini.line_length, &data.mini.endian);
		fake_assests_init(&data);
		ft_raycast1(&data);
		mlx_hook(data.mini.mlx_win, 17, 0, exit_point, &data);
		mlx_hook(data.mini.mlx_win, 2, 1L<<0, controls_working, &data);
		mlx_key_hook(data.mini.mlx_win, controls_working, &data);
		mlx_loop(data.mini.mlx);
		return(1);
	}
	return (0);
}
