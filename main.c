/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 19:18:32 by iait-bou          #+#    #+#             */
/*   Updated: 2024/08/01 20:19:48 by iait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	init_fractal(int ac, char *av[], t_fractal *fractal)
{
	fractal->name = av[1];
	if (ac == 4 && !ft_strcmp(av[1], "julia"))
	{
		fractal->julia_real = atodoubl(av[2]);
		fractal->julia_img = atodoubl(av[3]);
	}
	init(fractal);
	draw_fractal(fractal);
	mlx_loop(fractal->mlx_cnx);
}

int	validate_args(int ac, char *av[])
{
	if ((ac == 2 && !ft_strcmp(av[1], "mandelbrot")) || (ac == 4
			&& !ft_strcmp(av[1], "julia") && valid(av[2]) && valid(av[3])))
	{
		return (1);
	}
	write(2, "Usage: ./fractol mandelbrot | ./fractol julia [real] [img]\n",
		59);
	return (0);
}

int	main(int ac, char *av[])
{
	t_fractal	fractal;

	if (validate_args(ac, av))
	{
		init_fractal(ac, av, &fractal);
	}
	else
	{
		return (1);
	}
	return (0);
}
