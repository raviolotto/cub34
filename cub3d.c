/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <jcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:18:50 by jcardina          #+#    #+#             */
/*   Updated: 2024/03/08 14:51:16 by jcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

int main(int ac, char **av)
{
	t_data data;
	if(parser(ac, av, &data) == 1)
	{
		printf(":(\n");
		free_all(&data);
		return(0);
	}
}
