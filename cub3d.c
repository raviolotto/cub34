/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <jcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:18:50 by jcardina          #+#    #+#             */
/*   Updated: 2024/03/05 17:16:30 by jcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

int main(int ac, char **av)
{
	t_data data;
	if(parser(ac, av, &data) == 1)
	{
		printf("error wrong input");
		return(0);
	}
}
