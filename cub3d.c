/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <jcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:18:50 by jcardina          #+#    #+#             */
/*   Updated: 2024/03/27 17:44:15 by jcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

void	init(t_data *data)
{
	data->info_list = NULL;
	data->map = NULL;
	data->player.pos_x = 0;
	data->player.pos_y = 0;
	if(data->info_list == NULL)
		ft_putstr_fd("amooore\n", 2);

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
	print_list(data.info_list);
	printf(" pos x player%f\n", data.player.pos_x);
	printf(" pos y player%f\n", data.player.pos_y);
	//fine debug info
	if(start(&data) == 1)
	{
		printf(":(\n");
		free_all(&data);
		return(1);
	}
	return (0);
}
