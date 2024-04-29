/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:21:43 by jcardina          #+#    #+#             */
/*   Updated: 2024/04/26 16:52:36 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_list(t_infos *node)
{
	t_infos	*tmp;

	tmp = node;
	while(tmp)
	{
		ft_printf("%d\n", tmp->what);
		print_matrix(tmp->str);
		if(tmp->what == 6 || tmp->what == 7)
			print_matrix(tmp->color);
		tmp = tmp->next;
		ft_printf("---------------\n");
	}
}

t_infos *newnode(char *str)
{
	t_infos *node;

	node = malloc(sizeof(t_infos));
	node->str = ft_split(str, ' ');
	node->next = NULL;
	node->what = check_info2(node->str);
		if(node->what == 6 || node->what == 7)
			node->color = ft_split(node->str[1], ',');
	return(node);
}

void	node_adderal(t_data *data, t_infos *node)
{
	t_infos	*tmp;

	tmp = data->info_list;
	while(tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = node;
}

int	lister(t_data *data)
{
	char	**matrix;
	t_infos	*tmp;

	matrix = data->info;
	while(*matrix)
	{
		if(data->info_list == NULL)
		{
			tmp = newnode(*matrix);
			data->info_list = tmp;
		}
		else
		{
			tmp = newnode(*matrix);
			node_adderal(data, tmp);
		}
		matrix ++;
	}
	if (!color_control(data->info_list))
		return (1);
	return (0);
}

void	map_size(t_data *data)
{
	int	y;
	int	x;
	int	mem;

	mem = 0;
	y = -1;
	while(data->map[++y])
	{
		x = 0;
		while(data->map[y][x])
			x++;
		if(mem < x)
			mem = x;
	}
	data->map_h = y;
	data->map_l = mem;
}

