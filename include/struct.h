/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <jcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:25:48 by jcardina          #+#    #+#             */
/*   Updated: 2024/03/27 17:39:37 by jcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "./cub3d.h"
# include "../lib/libft/libft.h"

typedef struct s_infos
{
	int	what; //  2= EA  3=NO 4=SO 5=WE 6=C 7=F
	char **str;
	char **color;
	struct s_infos *next;
}t_infos;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	int		dir;
}t_player;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits;
	int		line;
	int		endian;
	int		height;
	int		width;
}	t_img;

typedef struct s_mini
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
}t_mini;


typedef struct s_data
{
	int			fd;
	int			map_h;
	int			map_l;
	char		**map;
	char		**info;
	t_infos		*info_list;
	t_mini		mini;
	t_player	player;
}t_data;

#endif
