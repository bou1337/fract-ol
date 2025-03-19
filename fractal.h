/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 19:06:45 by iait-bou          #+#    #+#             */
/*   Updated: 2024/08/01 20:17:25 by iait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define X_MAX 700
# define Y_MAX 700
# define NEW_MIN -2
# define NEW_MAX 2
# define OLD_MAX 700
# define OLD_MIN 0

typedef struct s_complex
{
	double		real;
	double		img;
}				t_complex;

typedef struct s_image
{
	void		*img;
	char		*addr;
	int			bpp;
	int			len;
	int			endian;
}				t_image;

typedef struct t_fractal
{
	void		*mlx_cnx;
	void		*mlx_window;
	char		*name;
	int			iteration;
	double		zoom;
	double		shift_x;
	double		shift_y;
	t_image		img;
	long double	julia_real;
	long double	julia_img;
}				t_fractal;

void			my_pixel_put(t_image *img, int x, int y, int color);
void			init(t_fractal *mlx);
void			data_init(t_fractal *fractal);
double			ft_scaling(double old_var);
t_complex		sum_complex(t_complex z1, t_complex z2);
t_complex		square_complex(t_complex z);
double			vabs(t_complex z);
void			chek_fractal(t_complex *z, t_complex *c, t_fractal *fractal);
void			draw_pixel(int x, int y, t_fractal *fractal);
void			draw_fractal(t_fractal *fractal);
int				ft_strcmp(char *s1, char *s2);
long double		atodoubl(char *s);
int				ft_is_digit(char c);
int				valid(char *st);
void			event(t_fractal *fractal);
int				key_code(int keycode, t_fractal *fractal);
int				mouse_handel(int button, int x, int y, t_fractal *fractal);
int				ft_close(t_fractal *fractal);
int				ft_color(int i, int eteration);
void			ft_free(t_fractal *fractal);

#endif
