/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:15:51 by iait-bou          #+#    #+#             */
/*   Updated: 2024/08/01 20:15:53 by iait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_free(t_fractal *fractal)
{
	if (fractal->img.img != NULL)
	{
		mlx_destroy_image(fractal->mlx_cnx, fractal->img.img);
	}
	if (fractal->mlx_window != NULL)
	{
		mlx_destroy_window(fractal->mlx_cnx, fractal->mlx_window);
	}
	if (fractal->mlx_cnx != NULL)
	{
		mlx_destroy_display(fractal->mlx_cnx);
		free(fractal->mlx_cnx);
	}
}
