/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 19:17:35 by iait-bou          #+#    #+#             */
/*   Updated: 2024/08/01 20:21:53 by iait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	init(t_fractal *mlx)
{
	mlx->mlx_cnx = mlx_init();
	mlx->mlx_window = mlx_new_window(mlx->mlx_cnx, X_MAX, Y_MAX, mlx->name);
	if (!(mlx->mlx_window))
	{
		ft_free(mlx);
	}
	mlx->img.img = mlx_new_image(mlx->mlx_cnx, X_MAX, Y_MAX);
	if (!(mlx->img.img))
	{
		ft_free(mlx);
	}
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bpp,
			&mlx->img.len, &mlx->img.endian);
	if (!(mlx->img.addr))
	{
		ft_free(mlx);
	}
	data_init(mlx);
	event(mlx);
}

void	event(t_fractal *fractal)
{
	mlx_key_hook(fractal->mlx_window, key_code, fractal);
	mlx_mouse_hook(fractal->mlx_window, mouse_handel, fractal);
	mlx_hook(fractal->mlx_window, 17, 0, ft_close, fractal);
}

void	data_init(t_fractal *fractal)
{
	fractal->iteration = 50;
	fractal->zoom = 1;
	fractal->shift_x = 0;
	fractal->shift_y = 0;
}
