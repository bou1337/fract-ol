/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 02:55:23 by iait-bou          #+#    #+#             */
/*   Updated: 2024/08/01 19:26:32 by iait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

double	ft_scaling(double old_var)
{
	double	new_var;
	double	percent_of_old_var;

	percent_of_old_var = (old_var - OLD_MIN) / (OLD_MAX - OLD_MIN);
	new_var = (NEW_MAX - NEW_MIN) * percent_of_old_var + NEW_MIN;
	return (new_var);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.img = z1.img + z2.img;
	result.real = z1.real + z2.real;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.real = z.real * z.real - z.img * z.img;
	result.img = 2 * z.real * z.img;
	return (result);
}

double	vabs(t_complex z)
{
	return (z.real * z.real + z.img * z.img);
}
