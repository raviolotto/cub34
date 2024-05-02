/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:54:48 by jcardina          #+#    #+#             */
/*   Updated: 2024/05/02 13:57:05 by mcamilli         ###   ########.fr       */
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

void	print_matrix(char **matrix)
{
	while(*matrix)
	{
		ft_putstr_fd(*matrix, 1);
		write(1, "\n", 1);
		matrix++;
	}
}

void	free_matrix(char **matrix)
{
	size_t	i;

	i = 0;
	if(matrix == NULL)
		return;
	if(*matrix == NULL)
		return;
	while (matrix[i] != NULL)
	{
		free (matrix[i]);
		i++;
	}
	free (matrix);
}

void	free_list(t_infos *list)
{
	t_infos	*tmp;

	while(list)
	{
		tmp = list;
		list = list->next;
		free_matrix(tmp->str);
		if(tmp->what == 6 || tmp->what == 7)
			free_matrix(tmp->color);
		free(tmp);
	}
	ft_putstr_fd("freeeeeato amo!!!\n", 1);
}

void	free_all(t_data *data)
{
	
	free_matrix(data->info);
	free_matrix(data->map);
	free_list(data->info_list);
}

int	matrixlen(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
		i++;
	return (i);
}

char	**matrix_newline(char **matrix, char *str)
{
	int		len;
	char	**newmatrix;

	len = matrixlen(matrix);
	newmatrix = malloc((len + 2) * sizeof(char *));
	if (!newmatrix)
		ft_putstr_fd("amoooo memory error\n", 2);
	len = 0;
	while (matrix[len] != NULL)
	{
		newmatrix[len] = ft_strdup(matrix[len]);
		len ++;
	}
	newmatrix[len] = ft_strdup(str);
	newmatrix[len + 1] = NULL;
	free_matrix(matrix);
	return (newmatrix);
}
