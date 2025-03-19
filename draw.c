/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 02:52:09 by iait-bou          #+#    #+#             */
/*   Updated: 2024/08/01 18:47:16 by iait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	my_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + y * img->len + (img->bpp / 8) * x;
	*(unsigned int *)dst = color;
}

void	chek_fractal(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strcmp(fractal->name, "julia"))
	{
		c->real = fractal->julia_real;
		c->img = fractal->julia_img;
	}
	else
	{
		c->real = z->real;
		c->img = z->img;
	}
}

void	draw_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.real = ft_scaling(x) * fractal->zoom + fractal->shift_x;
	z.img = ft_scaling(y) * fractal->zoom + fractal->shift_y;
	chek_fractal(&z, &c, fractal);
	while (i < fractal->iteration)
	{
		z = sum_complex(square_complex(z), c);
		if (vabs(z) > 4)
		{
			color = ft_color(i, fractal->iteration);
			my_pixel_put(&fractal->img, x, y, color);
			return ;
		}
		i++;
	}
	my_pixel_put(&fractal->img, x, y, 0);
}

void	draw_fractal(t_fractal *fractal)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < X_MAX)
	{
		y = 0;
		while (y < Y_MAX)
		{
			draw_pixel(x, y, fractal);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->mlx_cnx, fractal->mlx_window,
		fractal->img.img, 0, 0);
}

int	ft_color(int i, int iteration)
{
	double	perc;
	int		color;

	perc = (double)i / (double)iteration;
	color = (0xFF0000 - 0xFFFFFF) * perc + 0xFFFFFF;
	return (color);
}
