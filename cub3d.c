/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:18:50 by jcardina          #+#    #+#             */
/*   Updated: 2024/05/18 18:14:33 by mcamilli         ###   ########.fr       */
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
	data->ray_uncasted = 0;
}

int	exit_point(t_data *data)
{
	mlx_destroy_image(data->mini.mlx, data->mini.img);
	mlx_destroy_window(data->mini.mlx, data->mini.mlx_win);
	free_all(data);
	printf("mcamilli Il Peruviano vi saluta con dolcezza");
	exit(0);
}

int	main(int ac, char **av)
{
	t_data	data;

	init(&data);
	if (parser(ac, av, &data) == 1)
	{
		printf(":(\n");
		free_all(&data);
		return (1);
	}
	data.mini.mlx = mlx_init();
	data.mini.mlx_win = mlx_new_window(data.mini.mlx,
			SCREEN_W, SCREEN_H, "cubitron");
	data.mini.img = mlx_new_image(data.mini.mlx, SCREEN_W, SCREEN_H);
	data.mini.addr = mlx_get_data_addr(data.mini.img, &data.mini.bits_per_pixel,
			&data.mini.line_length, &data.mini.endian);
	assests_init(&data);
	ft_raycast1(&data);
	mlx_hook(data.mini.mlx_win, 17, 0, exit_point, &data);
	mlx_hook(data.mini.mlx_win, 2, 1L << 0, controls_working, &data);
	mlx_key_hook(data.mini.mlx_win, controls_working, &data);
	mlx_loop(data.mini.mlx);
	return (0);
}
