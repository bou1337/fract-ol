/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 19:16:55 by iait-bou          #+#    #+#             */
/*   Updated: 2024/08/03 19:20:48 by iait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	key_code(int keycode, t_fractal *fractal)

{
	if (keycode == XK_Escape)
	{
		ft_free(fractal);
		exit(0);
	}
	else if (keycode == XK_Left)
		fractal->shift_x += 0.1;
	else if (keycode == XK_Right)
		fractal->shift_x -= 0.1;
	else if (keycode == XK_Up)
		fractal->shift_y -= 0.1;
	else if (keycode == XK_Down)
		fractal->shift_y += 0.1;
	else if (keycode == XK_KP_Add)
		fractal->iteration += 100;
	draw_fractal(fractal);
	return (0);
}

int	mouse_handel(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == Button5)
		fractal->zoom *= 0.9;
	else if (button == Button4)
		fractal->zoom /= 0.9;
	draw_fractal(fractal);
	return (0);
}

int	ft_close(t_fractal *fractal)
{
	ft_free(fractal);
	exit(0);
}
