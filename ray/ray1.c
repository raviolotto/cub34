/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:45:02 by mcamilli          #+#    #+#             */
/*   Updated: 2024/05/01 19:07:51 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
serve per sostituire i controlli troppo lunghi, e setta ray x e y con le coord. di a;
dir è un modificatore che può cambiere il risultato dei controlli, il suo valore dipende
dalla direzione della semiretta:
	1079: dir = 1
	2160: dir = 3
	3239: dir = 2
mag 3239: dir = 0
*/
int	control_a(t_data *data, int newx1a, double newya, int dir)
{
	if (((dir == 1 || dir == 3) && (floor(newya) <= data->map_h && data->map[(int)
				floor(newya)][newx1a - (dir / 2)] == '1'))
				|| ((dir == 2 || dir == 0) && (floor(newya) >= 0 && data->map[(int)
				floor(newya)][newx1a - (dir / 2)] == '1')))
	{
		data->ray_x = (double)newx1a;
		data->ray_y = newya;
		return (1);
	}
	else
		return (0);
}

/*
serve per sostituire i controlli troppo lunghi, e setta ray x e y con le coord. di b;
dir è un modificatore che può cambiere il risultato dei controlli, il suo valore dipende
dalla direzione della semiretta:
	1079: dir = 1
	2160: dir = 0
	3239: dir = 2
mag 3239: dir = 3
*/
int	control_b(t_data *data, double newxb, int newy1b, int dir)
{
	if (((dir == 1 || dir == 3) && (floor(newxb) <= data->map_l
				&& data->map[newy1b - (dir/2)][(int)floor(newxb)] == '1'))
				|| ((dir == 0 || dir == 2) && floor(newxb) >= 0
				&& data->map[newy1b - (dir/2)][(int)floor(newxb)] == '1'))
	{
		data->ray_x = newxb;
		data->ray_y = (double)newy1b;
		return (1);
	}
	else
		return (0);
}

/*
compara la distanza dei due punti a e b dal player
e prende quella minore, risettando correttamente
ray x e y.
siccome l'ultimo controllo prima di questa funzione è su b, b sta in ray x e y
*/
double control_ab(t_data *data, int newx1a, double newya)
{
	double ia;
	double ib;

	ia = hypot(fabs(data->player.pos_x - newx1a),fabs(data->player.pos_y - newya));
	ib = hypot(fabs(data->player.pos_x - data->ray_x), fabs(data->player.pos_y - data->ray_y));
	if (ib <= ia)
		return (ib);
	else
	{
		data->ray_x = (double)newx1a;
		data->ray_y = newya;
		return (ia);
	}
}

/*
ritorna la lunghezza del ray sul primo quadrante, setta ray x e y.
*/
double	ft_ray_lenght_min_1079(t_data *data,double  q, double m)
{
	int		newx1a;
	double	newya;
	int		newy1b;
	double	newxb;

	newx1a = ceil(data->player.pos_x);
	newy1b = ceil(data->player.pos_y);
	while (1)
	{
		newya = fma(m, newx1a, q);
		newxb = (1 / m * newy1b) - q ;
		if (control_a(data,newx1a,newya, 1) && control_b(data,newx1a,newya, 0))
			return (control_ab(data, newx1a, newya));
		if (control_a(data,newx1a,newya, 1))
			return (hypot(fabs(data->player.pos_x - newx1a)
					, fabs(data->player.pos_y - newya)));
		if (control_b(data,newx1a,newya, 1))
			return (hypot(fabs(data->player.pos_x - newxb), fabs(data->player.pos_y - newy1b)));
		newx1a++;
		newy1b++;
	}
}

/*
ritorna la lunghezza del ray sul secondo quadrante, setta ray x e y.
*/
double ft_ray_lenght_min_2160(t_data *data,double  q, double m)
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
		if (control_a(data,newx1a,newya, 3) && control_b(data,newx1a,newya, 0))
			return (control_ab(data, newx1a, newya));
		if (control_a(data,newx1a,newya, 3))
			return (hypot(fabs(data->player.pos_x - newx1a)
					, fabs(data->player.pos_y - newya)));
		if (control_b(data, newx1a, newya, 0))
			return (hypot(fabs(data->player.pos_x - newxb), fabs(data->player.pos_y - newy1b)));
		newx1a--;
		newy1b++;
	}
}

/*
ritorna la lunghezza del ray sul terzo quadrante, setta ray x e y.
*/
double ft_ray_lenght_min_3239(t_data *data,double  q, double m)
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
		if (control_a(data,newx1a,newya, 2) && control_b(data,newx1a,newya, 2))
			return (control_ab(data, newx1a, newya));
		if (control_a(data,newx1a,newya, 2))
			return (hypot(fabs(data->player.pos_x - newx1a)
					, fabs(data->player.pos_y - newya)));
		if (control_b(data,newx1a,newya, 2))
			return (hypot(fabs(data->player.pos_x - newxb), fabs(data->player.pos_y - newy1b)));
		newx1a--;
		newy1b--;
	}
}

/*
ritorna la lunghezza del ray sul quarto quadrante, setta ray x e y.
*/
double ft_ray_lenght_mag_3239(t_data *data,double  q, double m)
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
		if (control_a(data,newx1a,newya, 0) && control_b(data,newx1a,newya, 3))
			return (control_ab(data, newx1a, newya));
		if (control_a(data,newx1a,newya, 0))
			return (hypot(fabs(data->player.pos_x - newx1a)
					, fabs(data->player.pos_y - newya)));
		if (control_b(data,newx1a,newya, 3))
			return (hypot(fabs(data->player.pos_x - newxb), fabs(data->player.pos_y - newy1b)));
		newx1a--;
		newy1b--;
	}
}
void ft_set_ray_min_1079(t_data *data, double q, double m, double rad_p)
{
	//qui dovrei calcolre l distanza dal piano di cristo
	data->ray_lenght = sin(CONST_RAD * data->player.mov_ang) * ft_ray_lenght_min_1079(data, q, m);
	data->ray_y = fma(m, data->ray_x, q);
}

void ft_set_ray_min_2160(t_data *data, double q, double m)
{
	data->ray_lenght = ft_ray_lenght_min_2160(data, q, m);
	data->ray_x = cos(data->player.pos_x - data->ray_lenght);
	data->ray_Y = fma(m, data->ray_x, q);
}

void ft_set_ray_min_3239(t_data *data, double q, double m)
{
	data->ray_lenght = ft_ray_lenght_min_3239(data, q, m);
	data->ray_x = cos(data->player.pos_x - data->ray_lenght);
	data->ray_Y = fma(m, data->ray_x, q);
}

void ft_set_ray_mag_3239(t_data *data, double q, double m)
{
	data->ray_lenght = ft_ray_lenght_mag_3239(data, q, m);
	data->ray_x = cos(data->player.pos_x + data->ray_lenght);
	data->ray_Y = fma(m, data->ray_x, q);
}
/*
trova m e q di un ray, smista il ray in base alla sua direzione ed
esegue una funzione a parte per ognuna di esse cosi da capire quanto trova il muro
completata solo la funzione del primo quadrante (1079);
*/
void ft_ray_in_plane(t_data *data, double rad_p)
{
	//2400 = ancora primo quadrante
	// 4800 ancora secondo quad
	// 7200 ancora terzo quad
	double m;
	double q;
	m = tan(CONST_RAD * data->player.mov_ang);
	q = fma(-data->player.pos_x, m,data->player.pos_y);
	if (data->player.mov_ang <= 1079)
		ft_set_ray_min_1079(data, q, m, rad_p);
	else if (data->player.mov_ang <= 2160)
		data->ray_lenght = ft_ray_lenght_min_2160(data, q, m);
	else if (data->player.mov_ang <= 3239)
		data->ray_lenght = ft_ray_lenght_min_3239(data, q, m);
	else
		data->ray_lenght = ft_ray_lenght_mag_3239(data, q, m);
	data->ray_x = cos(data->player.pos_x + data->ray_lenght);
	data->ray_y = fma(m, data->ray_x, q);
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
void ft_raycast1(t_data *data)
{
	int i;
	double rad_p;

	i = 720;
	rad_p = (data->player.mov_ang * CONST_RAD) - 1.0471975511;
	while(i--)
	{
		if (data->player.mov_ang == 4320)
			data->player.mov_ang = 0;
		ft_ray_in_plane(data, rad_p);
		data->player.mov_ang++;

	}

}
