/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:45:02 by mcamilli          #+#    #+#             */
/*   Updated: 2024/05/01 03:19:34 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

data->player.mov_ang = 1600;// supponiamo di stare a nord
double ft_ray_lenght_min_2400(t_data *data,double  q, double m)
{
	int newx1a;
	double newya;
	int newy1b;
	double newxb;
	
	newx1a = ceil(data->player.pos_x);
	newy1b = ceil(data->player.pos_y);
	while (1)
	{
		newya = fma(m, newx1a, q);
		newxb = 1/m * (newy1b - q);
		if ((floor(newya) <= data->map_h && 
			data->map[(int)floor(newya)][newx1a] == '1') && 
			(floor(newxb) <= data->map_l && data->map[newy1b][(int)floor(newxb)] == '1'))
			return(fmin(hypot(fabs(data->player.pos_x - newxb), fabs(data->player.pos_y - newy1b)), 
			hypot(fabs(data->player.pos_x - newx1a), fabs(data->player.pos_y - newya))));
		if (floor(newya) <= data->map_h && data->map[(int)floor(newya)][newx1a] == '1')
			return (hypot(fabs(data->player.pos_x - newx1a), fabs(data->player.pos_y - newya)));
		if (floor(newxb) <= data->map_l && data->map[newy1b][(int)floor(newxb)] == '1')
			return (hypot(fabs(data->player.pos_x - newxb), fabs(data->player.pos_y - newy1b)));
		newx1a++;
		newy1b++;
	}
	
}

double ft_ray_lenght_min_4800(t_data *data,double  q, double m)
{
	int newx1a;
	double newya;
	int newy1b;
	double newxb;
	
	newx1a = floor(data->player.pos_x);
	newy1b = ceil(data->player.pos_y);
	while (1)
	{
		newya = fma(m, newx1a, q);
		newxb = 1/m * (newy1b - q);
		if ((floor(newya) <= data->map_h && 
			data->map[(int)floor(newya)][newx1a - 1] == '1') && 
			(floor(newxb) >= 0 && data->map[newy1b][(int)floor(newxb)] == '1'))
			return(fmin(hypot(fabs(data->player.pos_x - newxb), fabs(data->player.pos_y - newy1b)), 
			hypot(fabs(data->player.pos_x - newx1a), fabs(data->player.pos_y - newya))));
		if (floor(newya) <= data->map_h && data->map[(int)floor(newya)][newx1a - 1] == '1')
			return (hypot(fabs(data->player.pos_x - newx1a), fabs(data->player.pos_y - newya)));
		if (floor(newxb) >= 0 && data->map[newy1b][(int)floor(newxb)] == '1')
			return (hypot(fabs(data->player.pos_x - newxb), fabs(data->player.pos_y - newy1b)));
		newx1a--;
		newy1b++;
	}
}
double ft_ray_lenght_min_7200(t_data *data,double  q, double m)
{
	int newx1a;
	double newya;
	int newy1b;
	double newxb;
	
	newx1a = floor(data->player.pos_x);
	newy1b = floor(data->player.pos_y);
	while (1)
	{
		newya = fma(m, newx1a, q);
		newxb = 1/m * (newy1b - q);
		if ((floor(newya) >= 0 && 
			data->map[(int)floor(newya)][newx1a - 1] == '1') && 
			(floor(newxb) >= 0 && data->map[newy1b - 1][(int)floor(newxb)] == '1'))
			return(fmin(hypot(fabs(data->player.pos_x - newxb), fabs(data->player.pos_y - newy1b)), 
			hypot(fabs(data->player.pos_x - newx1a), fabs(data->player.pos_y - newya))));
		if (floor(newya) >= 0 && data->map[(int)floor(newya)][newx1a - 1] == '1')
			return (hypot(fabs(data->player.pos_x - newx1a), fabs(data->player.pos_y - newya)));
		if (floor(newxb) >= 0 && data->map[newy1b - 1][(int)floor(newxb)] == '1')
			return (hypot(fabs(data->player.pos_x - newxb), fabs(data->player.pos_y - newy1b)));
		newx1a--;
		newy1b--;
	}
}

double ft_ray_lenght_mag_7200(t_data *data,double  q, double m)
{
	int newx1a;
	double newya;
	int newy1b;
	double newxb;
	
	newx1a = ceil(data->player.pos_x);
	newy1b = floor(data->player.pos_y);
	while (1)
	{
		newya = fma(m, newx1a, q);
		newxb = 1/m * (newy1b - q);
		if ((floor(newya) >= 0 && 
			data->map[(int)floor(newya)][newx1a] == '1') && 
			(floor(newxb) <= data->map_l && data->map[newy1b - 1][(int)floor(newxb)] == '1'))
			return(fmin(hypot(fabs(data->player.pos_x - newxb), fabs(data->player.pos_y - newy1b)), 
			hypot(fabs(data->player.pos_x - newx1a), fabs(data->player.pos_y - newya))));
		if (floor(newya) >= 0 && data->map[(int)floor(newya)][newx1a] == '1')
			return (hypot(fabs(data->player.pos_x - newx1a), fabs(data->player.pos_y - newya)));
		if (floor(newxb) <= data->map_l && data->map[newy1b - 1][(int)floor(newxb)] == '1')
			return (hypot(fabs(data->player.pos_x - newxb), fabs(data->player.pos_y - newy1b)));
		newx1a--;
		newy1b--;
	}
}
void ft_set_ray_min_2400(t_data *data, double q, double m)
{
	data->ray_lenght = ft_ray_lenght_min_2400(data, q, m);
	data->ray_x = cos(data->player.pos_x + data->ray_lenght);
	data->ray_Y = fma(m, data->ray_x, q);
}

void ft_set_ray_min_4800(t_data *data, double q, double m)
{
	data->ray_lenght = ft_ray_lenght_min_4800(data, q, m);
	data->ray_x = cos(data->player.pos_x - data->ray_lenght);
	data->ray_Y = fma(m, data->ray_x, q);
}

void ft_set_ray_min_7200(t_data *data, double q, double m)
{
	data->ray_lenght = ft_ray_lenght_min_7200(data, q, m);
	data->ray_x = cos(data->player.pos_x - data->ray_lenght);
	data->ray_Y = fma(m, data->ray_x, q);
}

void ft_set_ray_mag_7200(t_data *data, double q, double m)
{
	data->ray_lenght = ft_ray_lenght_mag_7200(data, q, m);
	data->ray_x = cos(data->player.pos_x + data->ray_lenght);
	data->ray_Y = fma(m, data->ray_x, q);
}
void ft_ray_in_plane(t_data *data)
{
	//2400 = ancora primo quadrante
	// 4800 ancora secondo quad
	// 7200 ancora terzo quad
	double m;
	double q;
	m = tan(CONST_RAD * data->player.mov_ang);
	q = fma(-data->player.pos_x, m,data->player.pos_y);
	if (data->player.mov_ang <= 2400)
		data->ray_lenght = ft_ray_lenght_min_2400(data, q, m);
		ft_set_ray_min_2400(data, q, m);
	else if (data->player.mov_ang <= 4800)
		data->ray_lenght = ft_ray_lenght_min_4800(data, q, m);
	else if (data->player.mov_ang <= 7200)
		data->ray_lenght = ft_ray_lenght_min_7200(data, q, m);
	else
		data->ray_lenght = ft_ray_lenght_mag_7200(data, q, m);
	data->ray_x = cos(data->player.pos_x + data->ray_lenght);
	data->ray_Y = fma(m, data->ray_x, q)
}
void ft_raycast1(t_data *data)
{
	int i;


	i = 1600;
	while(i--)
	{
		ft_ray_in_plane(data);
		if (data->player.mov_ang == 9600)
			data->player.mov_ang = 0;
	}

}


void ft_ray_in_plane(t_data *data)
{
	//2400 = ancora primo quadrante
	// 4800 ancora secondo quad
	// 7200 ancora terzo quad
	double m;
	double q;
	int newx1a;
	double newya;
	int newy1b;
	double newxb;
	m = tan(CONST_RAD * data->player.mov_ang);
	q = fma(-data->player.pos_x, m,data->player.pos_y);
	if (data->player.mov_ang <= 2400)
	{
		while (1)
		{
			
		newx1a = ceil(data->player.pos_x);
		if (data->map[floor(fma(m, newx1a, q))][newx1a] == '1')
		{
			break
		}
			newx1a++;
		newya = fma(m, newx1a, q);
		newy1b = ceil(data->player.pos_y);
		while (data->map[floor(1/m * (newy1b - q))][newy1b] != '1')
			newy1b++;
		newxb = 1/m * (newy1b - q);
		}
		
	}
}

