/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <jcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:20:02 by jcardina          #+#    #+#             */
/*   Updated: 2024/04/16 17:02:07 by jcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "struct.h"
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/gnl/get_next_line.h"
# include "../mlx_linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define SCREEN_W 1900
# define SCREEN_H 1000
//mi servono ?
# define TILE_SIZE 32
# define ROTATION_SPEED 0.045
# define PLAYER_SPEED 4

int		parser(int ac, char **av, t_data *data);
int		lister(t_data *data);
int		check_info(char *str);
int		check_info2(char **info);
int		check_map(t_data *map);
int		color_control(t_infos *infos);
int		start(t_data *data);
char	*super_strjoin(char const *s1, char const *s2);
char	**matrix_newline(char **matrix, char *str);
void	print_matrix(char **matrix);
void	free_all(t_data *data);
void	print_list(t_infos *node);
void	map_size(t_data *data);
void	player_pos(t_data *data);
void	player_pos(t_data *data);


#endif

//appunti									  __A__
//aggiungere controllo per piú di un player <(" _ ")>
