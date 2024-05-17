/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:45:02 by mcamilli          #+#    #+#             */
/*   Updated: 2024/05/17 16:54:14 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int ft_floor(double i)
{
	double d;

	d = i;
	return ((int)floor(d));
}
/*
serve per sostituire i controlli troppo lunghi, e setta ray x e y con le coord. di a;
dir è un modificatore che può cambiere il risultato dei controlli, il suo valore dipende
dalla direzione della semiretta:
*/
int control_a(t_data *data, int newx1a, double newya, int dir)
{
	//printf("\n--------------------------------------contr_a = x = %d, y = %f\n\n", newx1a, newya);
	if ((data->map[ft_floor(newya)][newx1a - dir] == '1'))
	{
		data->ray_x = (double)newx1a;
		data->ray_y = newya;
		data->player.AB_12 = 1;
		return (1);
	}
	else
		return (0);
}

/*
serve per sostituire i controlli troppo lunghi, e setta ray x e y con le coord. di b;
dir è un modificatore che può cambiere il risultato dei controlli, il suo valore dipende
dalla direzione della semiretta:
*/
int control_b(t_data *data, double newxb, int newy1b, int dir)
{
	// printf("controlb\n");
	// if (newxb <= 0 || newxb >= data->map_l || newy1b < 0 || newy1b >= data->map_h) {
	//     //printf("Tentativo di accesso fuori dai limiti: x=%f, y=%d, ray n = %f\n", newxb, newy1b, data->player.mov_ang);
	//     return (0);  // Gestisci l'errore come preferisci, qui stoppo il controllo
	// }
	//printf("\ncontr_b = x = %f, y = %d\n\n", newxb, newy1b);
	if (((data->map[newy1b - dir][ft_floor(newxb)] == '1')))
	{
		data->ray_x = newxb;
		data->ray_y = (double)newy1b;
		data->player.AB_12 = 2;
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
	int ia;
	int ib;

	ia = hypot(fabs(data->player.pos_x - newx1a), fabs(data->player.pos_y - newya));
	ib = hypot(fabs(data->player.pos_x - data->ray_x), fabs(data->player.pos_y - data->ray_y));
	if (ib <= ia)
		return (ib);
	else
	{
		//printf("-------------------contr_ab = x = %d, y = %f\n", newx1a, newya);
		data->ray_x = (double)newx1a;
		data->ray_y = newya;
		return (ia);
	}
}

/*
ritorna la lunghezza del ray sul primo quadrante, setta coord ray x e y.
ovvero del punto di collisione tra ray e muro
*/
double ft_ray_lenght_min_1079(t_data *data, double q, double m)
{
	int newx1a;
	double newya;
	int newy1b;
	double newxb;
	double hypotena;
	double hypotenb;

	hypotena = -1;
	hypotenb = -1;
	newx1a = (int)ceil(data->player.pos_x);
	newy1b = (int)ceil(data->player.pos_y);
	//printf("data->player.pos_x = %f\n", data->player.pos_x);
	while (1)
	{
		newya = (m * (double)newx1a) + q;
		// printf("newya 113 = %f\n", newya);
		// printf("newya 113 = %d\n", data->map_h);
		if ((newya <= 0.0) || (newx1a <= 0) || (ft_floor(newya) > data->map_h) || (newx1a > ((int)ft_strlen(data->map[ft_floor(newya)]) - 1)))
		{
		//	printf("controllato e uscito da a\n");
			hypotena = -1;
			break;
		}
		//printf("------------------------------------newya 113 = %f\n", newya);
		if (control_a(data, newx1a, newya, 0))
		{
		//	printf("trovato a!\n");
			hypotena = hypot(fabs(data->player.pos_x - newx1a), fabs(data->player.pos_y - newya));
			break;
		}
		newx1a++;
	}
	while (1)
	{
		newxb = ((double)newy1b / m) - (q / m);
		//printf("newxb = %f\n, newy1b = %d\n, mov %f\n", newxb, newy1b, data->player.mov_ang);
		if (newy1b <= 0 || newxb <= 0 || newy1b > data->map_h || ft_floor(newxb) > (int)(ft_strlen(data->map[newy1b]) - 1))
		{
			hypotenb = -1;
		//	printf("controllato e uscito da b\n, break");
			break;
		}
		if (control_b(data, newxb, newy1b, 0))
		{
		//	printf("trovato b!\n");
			hypotenb = hypot(fabs(data->player.pos_x - newxb), fabs(data->player.pos_y - newy1b));
			break;
		}
		newy1b++;
	}
	//printf("newxb = %f, newy1b = %d\n newx1a = %d newya = %f\n m = %f, q = %f\n", newxb, newy1b, newx1a, newya, m, q);
	if ((hypotena + hypotenb) == -2)
		return ((double)printf("\n----------------------------errore, finito senza muro A(%d, %f) B(%f, %d)\n \n", newx1a, newya, newxb, newy1b));
	if ((hypotenb <= hypotena || hypotena < 0) && hypotenb >= 0)
	{
		return (hypotenb);
	}
	// if (printf("rdata->map_h4  ") && control_a(data, newx1a, newya, 0))
	if (control_a(data, newx1a, newya, 0))
	{
		return (hypotena);
	}
	return (0);
}

/*
ritorna la lunghezza del ray sul secondo quadrante, setta coord ray x e y.
ovvero del punto di collisione tra ray e muro
*/
double ft_ray_lenght_min_2160(t_data *data, double q, double m)
{
	int newx1a;
	double newya;
	int newy1b;
	double newxb;
	double hypotena;
	double hypotenb;

	hypotena = -1;
	hypotenb = -1;
	newx1a = floor(data->player.pos_x);
	newy1b = ceil(data->player.pos_y);
	while (1)
	{
		newya = (m * (double)newx1a) + q;
		if (newya <= 0.0 || newx1a <= 0 || ft_floor(newya) > data->map_h || newx1a > (int)ft_strlen(data->map[ft_floor(newya)]) - 1)
		{
			hypotena = -1;
			break;
		}
		if (control_a(data, newx1a, newya, 1))
		{
			hypotena = hypot(fabs(data->player.pos_x - newx1a), fabs(data->player.pos_y - newya));
			break;
		}
		newx1a--;
	}
	while (1)
	{
		newxb = ((double)newy1b / m) - (q / m);
		if (newy1b <= 0 || newxb <= 0 || newy1b > data->map_h || newxb > ft_strlen(data->map[ft_floor(newy1b)]) - 1)
		{
			hypotenb = -1;
			break;
		}
		if (control_b(data, newxb, newy1b, 0))
		{
			hypotenb = hypot(fabs(data->player.pos_x - newxb), fabs(data->player.pos_y - newy1b));
			break;
		}
		newy1b++;
	}
	//printf("newxb = %f, newy1b = %d\n newx1a = %d newya = %f\n m = %f, q = %f\n", newxb, newy1b, newx1a, newxb, m, q);
	if (hypotena + hypotenb == -2)
		return ((double)printf("\n----------------------------errore, finito senza muro A(%d, %f) B(%f, %d)\n \n", newx1a, newya, newxb, newy1b));
	if ((hypotenb <= hypotena || hypotena < 0) && hypotenb >= 0)
		return (hypotenb);
	if (control_a(data, newx1a, newya, 1))
		return (hypotena);
	return (0);
}


/*
ritorna la lunghezza del ray sul terzo quadrante, setta coord ray x e y.
ovvero del punto di collisione tra ray e muro
*/
double ft_ray_lenght_min_3239(t_data *data, double q, double m)
{
	int newx1a;
	double newya;
	int newy1b;
	double newxb;
	double hypotena;
	double hypotenb;

	hypotena = -1;
	hypotenb = -1;
	newx1a = ft_floor(data->player.pos_x);
	newy1b = ft_floor(data->player.pos_y);
	while (1)
	{
		newya = (m * (double)newx1a) + q;
		if (newya <= 0.0 || newx1a <= 0 || ft_floor(newya) > data->map_h || newx1a > (int)ft_strlen(data->map[ft_floor(newya)]) - 1)
		{
			hypotena = -1;
			break;
		}
		if (control_a(data, newx1a, newya, 1))
		{
			hypotena = hypot(fabs(data->player.pos_x - newx1a), fabs(data->player.pos_y - newya));
			break;
		}
		newx1a--;
	}
	while (1)
	{
		newxb = ((double)newy1b / m) - (q / m);
		if (newy1b <= 0 || newxb <= 0 || newy1b > data->map_h || newxb > ft_strlen(data->map[ft_floor(newy1b)]) - 1)
		{
			hypotenb = -1;
			break;
		}
		if (control_b(data, newxb, newy1b, 1))
		{
			hypotenb = hypot(fabs(data->player.pos_x - newxb), fabs(data->player.pos_y - newy1b));
			break;
		}
		newy1b--;
	}
	//printf("newxb = %f, newy1b = %d\n newx1a = %d newya = %f\n m = %f, q = %f\n", newxb, newy1b, newx1a, newxb, m, q);
	if (hypotena + hypotenb == -2)
		return ((double)printf("\n----------------------------errore, finito senza muro A(%d, %f) B(%f, %d)\n \n", newx1a, newya, newxb, newy1b));
	if ((hypotenb <= hypotena || hypotena < 0) && hypotenb >= 0)
		return (hypotenb);
	if (control_a(data, newx1a, newya, 1))
		return (hypotena);
	return (0);
}

/*
ritorna la lunghezza del ray sul quarto quadrante, setta coord ray x e y.
ovvero del punto di collisione tra ray e muro
*/
double ft_ray_lenght_mag_3239(t_data *data, double q, double m)
{
	int newx1a;
	double newya;
	int newy1b;
	double newxb;
	double hypotena;
	double hypotenb;

	hypotena = -1;
	hypotenb = -1;
	newx1a = ceil(data->player.pos_x);
	newy1b = floor(data->player.pos_y);
	while (1)
	{
		newya = (m * (double)newx1a) + q;
		if (newya <= 0.0 || newx1a <= 0 || ft_floor(newya) > data->map_h || newx1a > (int)ft_strlen(data->map[ft_floor(newya)]) - 1)
		{
			hypotena = -1;
			break;
		}
		if (control_a(data, newx1a, newya, 0))
		{
			hypotena = hypot(fabs(data->player.pos_x - newx1a), fabs(data->player.pos_y - newya));
			break;
		}
		newx1a++;
	}
	while (1)
	{
		newxb = ((double)newy1b / m) - (q / m);
		if (newy1b <= 0 || newxb <= 0.0 || newy1b > data->map_h || newxb > (ft_strlen(data->map[newy1b]) - 1))
		{
			hypotenb = -1;
			break;
		}
		if (control_b(data, newxb, newy1b, 1))
		{
			hypotenb = hypot(fabs(data->player.pos_x - newxb), fabs(data->player.pos_y - newy1b));
			break;
		}
		newy1b--;
	}
	//printf("newxb = %f, newy1b = %d\n newx1a = %d newya = %f\n m = %f, q = %f\n", newxb, newy1b, newx1a, newxb, m, q);
	if (hypotena + hypotenb == -2)
		return ((double)printf("\n----------------------------errore, finito senza muro A(%d, %f) B(%f, %d)\n \n", newx1a, newya, newxb, newy1b));
	if ((hypotenb <= hypotena || hypotena < 0) && hypotenb >= 0)
		return (hypotenb);
	else if (control_a(data, newx1a, newya, 0))
		return (hypotena);
	return (0);
}

/*
colacola la distanza tra il punto del muro e il PIANO dl giocatore,
quindievita il fisheye effect.
Hypo = la distanza effettiva tra punto e giocatore,
quindi il ray trovato prima.
*/
double ft_ray_on_plane(t_data *data, double hypo_lenght)
{
	double rad_hyp;

	rad_hyp = data->rad_ray - data->rad_p;
	if (rad_hyp > PI / 2)
		rad_hyp = data->rad_p + PI - data->rad_ray;
	return (sin(rad_hyp) * hypo_lenght);
}

/*
setta il ray nel caso in cui la retta sia direzionata
sul primo quadrante
*/
void ft_set_ray_min_1079(t_data *data, double q, double m, int i)
{
	data->ray_lenght = ft_ray_on_plane(data, ft_ray_lenght_min_1079(data, q, m));
		if(data->player.AB_12 == 1)
		data->player.NSEW = 3;
	else
		data->player.NSEW = 1;
	ft_fakeray(data, i);
	// mlx_pixel_put(data->mini.mlx, data->mini.mlx_win, )
}

/*
setta il ray nel caso in cui la retta sia direzionata
sul secondo quadrante
*/
void ft_set_ray_min_2160(t_data *data, double q, double m, int i)
{
	data->ray_lenght = ft_ray_on_plane(data, ft_ray_lenght_min_2160(data, q, m));
	if(data->player.AB_12 == 1)
		data->player.NSEW = 4;
	else
		data->player.NSEW = 1;
	ft_fakeray(data, i);
}

/*
setta il ray nel caso in cui la retta sia direzionata
sul terzo quadrante
*/
void ft_set_ray_min_3239(t_data *data, double q, double m, int i)
{
	data->ray_lenght = ft_ray_on_plane(data, ft_ray_lenght_min_3239(data, q, m));
	if(data->player.AB_12 == 1)
		data->player.NSEW = 4;
	else
		data->player.NSEW = 2;
	ft_fakeray(data, i);
}

/*
setta il ray nel caso in cui la retta sia direzionata
sul quarto quadrante
*/
void ft_set_ray_mag_3239(t_data *data, double q, double m, int i)
{
	data->ray_lenght = ft_ray_on_plane(data, ft_ray_lenght_mag_3239(data, q, m));
	if(data->player.AB_12 == 1)
		data->player.NSEW = 3;
	else
		data->player.NSEW = 2;
	ft_fakeray(data, i);
}
/*
trova m e q di un ray, smista il ray in base alla sua direzione ed
esegue una funzione a parte, ne esiste una per ogni direzione.
i numeri sono in ordine di quadrante, ho divido il piano in 4320 rette
(720 è la risoluzione, 720 * (360 / 60) = 4320)
cosi è come se ogni direzione avesse un radiante "pre-assegnato"
*/
void ft_ray_in_plane(t_data *data, int i)
{
	double m;
	double q;

	m = tan(data->rad_ray);
	q = data->player.pos_y - (m * data->player.pos_x);
	if (data->player.mov_ang <= 1079)
		ft_set_ray_min_1079(data, q, m, i);
	else if (data->player.mov_ang <= 2159)
		ft_set_ray_min_2160(data, q, m, i);
	else if (data->player.mov_ang <= 3239)
		ft_set_ray_min_3239(data, q, m, i);
	else
		ft_set_ray_mag_3239(data, q, m, i);
}

/*
dovrebbe essere la funzione stampa tutto
*/
void ft_raycast1(t_data *data)
{
	int i;

	i = -1;
	data->player.mov_ang = data->player.last_mov_ang;
	data->rad_p = (data->player.mov_ang * CONST_RAD + (CONST_RAD / 2.0)) - 1.0471975511;
	while (++i < 720)
	{
		data->player.NSEW = 0;
		data->rad_ray = data->player.mov_ang * CONST_RAD + (CONST_RAD / 2.0);
		if (data->player.mov_ang == 4320)
			data->player.mov_ang = 0;
		ft_ray_in_plane(data, i);
		//printf("mov ang %f\n", data->player.mov_ang);
		data->player.mov_ang++;
	}
	mlx_put_image_to_window(data->mini.mlx, data->mini.mlx_win, data->mini.img, 0, 0);
	//printf("===================================retta n%d, ray lenght %f, ray_x %f, ray_y %f, mov_ang %f\n", i, data->ray_lenght, data->ray_x, data->ray_y, data->player.mov_ang);
}


