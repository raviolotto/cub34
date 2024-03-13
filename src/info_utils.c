/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <jcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:21:43 by jcardina          #+#    #+#             */
/*   Updated: 2024/03/13 17:55:28 by jcardina         ###   ########.fr       */
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
		tmp = tmp->next;
	}
}

t_infos *newnode(char *str)
{
	t_infos *node;

	node = malloc(sizeof(t_infos));
	node->str = ft_split(str, ' ');
	node->next = NULL;
	node->what = check_info2(node->str);
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

void	lister(t_data *data)
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
				write(1, ";)\n", 3);
}
