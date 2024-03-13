/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <jcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:23:47 by jcardina          #+#    #+#             */
/*   Updated: 2024/03/12 17:46:55 by jcardina         ###   ########.fr       */
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

int src_in_matrix(char **matrix, char *str)
{
	char	*point;
	while(*matrix)
	{
		point = *matrix;
		while(*point == ' ')
			str++;
		if(!ft_strncmp(point, str, ft_strlen(str)))
			return (1);
		matrix++;
	}
	return (0);
}

int	check_info2(char **info)
{
	if (src_in_matrix(info, "EA"))
		return (2);
	else if (src_in_matrix(info, "NO"))
		return (3);
	else if (src_in_matrix(info, "SO"))
		return (4);
	else if (src_in_matrix(info, "WE"))
		return (5);
	else if (src_in_matrix(info, "C"))
		return (6);
	else if (src_in_matrix(info, "F"))
		return (7);
	else
		return (1);
}
