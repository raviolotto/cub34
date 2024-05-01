/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:25:48 by jcardina          #+#    #+#             */
/*   Updated: 2024/05/01 17:10:42 by mcamilli         ###   ########.fr       */
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
	char	c;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	mov_ang;
	//double	mov_dir_x;
	//double	mov_dir_y;
	//double	cam_dir;
	//double	rot_angle;
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
	double		ray_lenght;
	double		ray_x;
	double		ray_y;
	t_infos		*info_list;
	t_mini		mini;
	t_player	player;
}t_data;

#endif
