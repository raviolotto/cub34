/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <jcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:25:48 by jcardina          #+#    #+#             */
/*   Updated: 2024/03/14 17:04:37 by jcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "./cub3d.h"
# include "../lib/libft/libft.h"

typedef struct s_infos
{
	int	what;
	char **str;
	char **color;
	struct s_infos *next;
}t_infos;

typedef struct s_player
{
	int	pos_x;
	int	pos_y;
	int	dir;
}t_player;

typedef struct s_mini
{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
}t_mini;

typedef struct s_data
{
	int			fd;
	int			map_h;
	int			map_l;
	char		**map;
	char		**info;
	t_infos		*info_list;
	t_mini		*mini;
	t_player	*player;
}t_data;

#endif
