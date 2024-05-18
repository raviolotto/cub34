/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacopo <jacopo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:30:37 by jacopo            #+#    #+#             */
/*   Updated: 2024/05/18 13:04:34 by jacopo           ###   ########.fr       */
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

void	matrix_adderal(t_data *data, char *str)
{
	if (data->map == NULL)
	{
		data->map = ft_calloc(sizeof(char *), 2);
		data->map[0] = ft_strdup(str);
	}
	else
		data->map = matrix_newline(data->map, str);
}

int	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (y >= 450 || y < 0)
		return (0);
	dst = data->mini.addr + (y * data->mini.line_length
			+ x * (data->mini.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return (0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	iswhite(char c)
{
	if (c == ' ' || (c > 8 && c < 14))
		return (1);
	else
		return (0);
}
