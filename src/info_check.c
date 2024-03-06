/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <jcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:23:47 by jcardina          #+#    #+#             */
/*   Updated: 2024/03/06 17:04:13 by jcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_info(char *str)
{
	while(*str == ' ')
		str++;
	if ((!ft_strncmp(str, "EA", 2) || !ft_strncmp(str, "NO", 2)
			|| !ft_strncmp(str, "SO", 2) || !ft_strncmp(str, "WE", 2))
		|| (!ft_strncmp(str, "F", 1) || !ft_strncmp(str, "C", 1)))
		return (1);
	return(0);
}
