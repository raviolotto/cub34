/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <jcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:20:02 by jcardina          #+#    #+#             */
/*   Updated: 2024/03/14 12:45:17 by jcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "struct.h"
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/gnl/get_next_line.h"
# include "../mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

int		parser(int ac, char **av, t_data *data);
int		lister(t_data *data);
int		check_info(char *str);
int		check_info2(char **info);
int		check_map(t_data *map);
int	color_control(t_infos *infos);
char	*super_strjoin(char const *s1, char const *s2);
void	print_matrix(char **matrix);
void	free_all(t_data *data);
void	print_list(t_infos *node);

#endif
