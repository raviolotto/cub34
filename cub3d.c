/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <jcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:18:50 by jcardina          #+#    #+#             */
/*   Updated: 2024/03/13 16:11:19 by jcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

void	init(t_data *data)
{
	data->info_list = NULL;
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
		return(0);
	}
}
