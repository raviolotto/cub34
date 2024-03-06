/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <jcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:54:48 by jcardina          #+#    #+#             */
/*   Updated: 2024/03/06 17:46:35 by jcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*super_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	int		i;
	size_t	j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	size = (ft_strlen(s1)) + (ft_strlen(s2)) + 1;
	str = malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		str[j++] = s1[i];
	i = -1;
	while (s2[++i])
		str[j++] = s2[i];
	str[j] = '\0';
	free((void *)s1);
	return (str);
}

// void	print_matrix(char **matrix)
// {
// 	while(*matrix)
// 	{
// 		printf("%s\n", *matrix);
// 		matrix++;
// 	}
// }

void	print_matrix(char **matrix)
{
	while(*matrix)
	matrix += (printf("%s\n", *matrix) * 0 + 1);
}

