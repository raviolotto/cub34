/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_xpm_colour.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:50:39 by mcamilli          #+#    #+#             */
/*   Updated: 2024/05/14 15:13:23 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int*** ft_parse_xpm(char *tex, t_data *data, int *h, int *w)
{
	int		fd;
	char	*str_tex;
	char	**mtrx_tex;
	fd = open(tex, O_RDONLY);
	str_tex = get_next_file(fd);
	close(fd);
	mtrx_tex = ft_split(str_tex, '\n');
	free(str_tex);
	ft_str

}