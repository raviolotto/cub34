/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:54:48 by jcardina          #+#    #+#             */
/*   Updated: 2024/05/18 17:39:53 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_matrix(char **matrix)
{
	size_t	i;

	i = 0;
	if (matrix == NULL)
		return ;
	if (*matrix == NULL)
		return ;
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

	while (list)
	{
		tmp = list;
		list = list->next;
		free_matrix(tmp->str);
		if (tmp->what == 6 || tmp->what == 7)
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

// int	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	if (y >= 450 || y < 0)
// 		return (0);
// 	dst = data->mini.addr + (y * data->mini.line_length
// 			+ x * (data->mini.bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// 	return (0);
// }

// int	create_trgb(int t, int r, int g, int b)
// {
// 	return (t << 24 | r << 16 | g << 8 | b);
// }
