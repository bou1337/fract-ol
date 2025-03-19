/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:11:53 by iait-bou          #+#    #+#             */
/*   Updated: 2024/08/01 20:14:33 by iait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

long double	atodoubl(char *s)
{
	double	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	pow = 1;
	sign = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		++s;
	if (*s == '+' || *s == '-')
	{
		if (*s++ == '-')
			sign = -1;
	}
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - '0');
	if (*s == '.')
	{
		while (*++s)
			fractional_part += ((*s - '0') * (pow /= 10));
	}
	return ((integer_part + fractional_part) * sign);
}

int	ft_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	valid(char *str)
{
	int	dot;
	int	digit;

	dot = 0;
	digit = 0;
	while (*str && ((*str >= 9 && *str <= 13) || *str == ' '))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str == '.')
		{
			if (dot)
				return (0);
			dot = 1;
		}
		else if (ft_is_digit(*str))
			digit = 1;
		else
			return (0);
		str++;
	}
	return (digit);
}
