/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray0.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:45:02 by mcamilli          #+#    #+#             */
/*   Updated: 2024/05/18 18:28:04 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_floor(double i)
{
	double	d;

	d = i;
	return ((int)floor(d));
}

/*
serve per sostituire i controlli troppo lunghi,
e setta ray x e y con le coord. di a;
dir è un modificatore che può cambiere il risultato dei controlli,
il suo valore dipende dalla direzione della semiretta:
*/
int	control_a(t_data *data, int dir)
{
	if ((data->map[ft_floor(data->newya)][data->newx1a - dir] == '1'))
	{
		data->ray_x = (double)data->newx1a;
		data->ray_y = data->newya;
		data->player.ab_12 = 1;
		return (1);
	}
	else
		return (0);
}

/*
serve per sostituire i controlli troppo lunghi,
e setta ray x e y con le coord. di b;
dir è un modificatore che può cambiere il risultato dei controlli,
il suo valore dipende dalla direzione della semiretta:
*/
int	control_b(t_data *data, int dir)
{
	if (((data->map[data->newy1b - dir][ft_floor(data->newxb)] == '1')))
	{
		data->ray_x = data->newxb;
		data->ray_y = (double)data->newy1b;
		data->player.ab_12 = 2;
		return (1);
	}
	else
		return (0);
}

void	ray_loop_a(t_data *data, double q, double m, int dir)
{
	while (1)
	{
		data->newya = fma(m, data->newx1a, q);
		if ((data->newya <= 0.0) || (data->newx1a <= 0)
			|| (ft_floor(data->newya) > data->map_h) || (data->newx1a
				> ((int)ft_strlen(data->map[ft_floor(data->newya)]) - 1)))
		{
			data->hypotena = -1;
			return ;
		}
		if (control_a(data, dir))
		{
			data->hypotena = hypot(fabs(data->player.pos_x - data->newx1a),
					fabs(data->player.pos_y - data->newya));
			return ;
		}
		if (dir == 0)
			data->newx1a++;
		else
			data->newx1a--;
	}
}

void	ray_loop_b(t_data *data, double q, double m, int dir)
{
	while (1)
	{
		data->newxb = ((double)data->newy1b / m) - (q / m);
		if (data->newy1b <= 0 || data->newxb <= 0
			|| data->newy1b > data->map_h || ft_floor(data->newxb)
			> (int)(ft_strlen(data->map[data->newy1b]) - 1))
		{
			data->hypotenb = -1;
			break ;
		}
		if (control_b(data, dir))
		{
			data->hypotenb = hypot(fabs(data->player.pos_x - data->newxb),
					fabs(data->player.pos_y - data->newy1b));
			break ;
		}
		if (dir == 0)
			data->newy1b++;
		else
			data->newy1b--;
	}
}
