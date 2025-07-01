/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogokdas <ogokdas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 21:35:44 by ogokdas           #+#    #+#             */
/*   Updated: 2025/07/01 21:35:44 by ogokdas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[++i])
		write(1, &str[i], 1);
	return (i);
}

int	ft_putnbr(int n)
{
	int	ret;

	ret = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		ret += write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
		ret += ft_putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
	return (ret + 1);
}

int	ft_uint(unsigned int n)
{
	int	ret;

	ret = 0;
	if (n >= 10)
		ret += ft_uint(n / 10);
	write(1, &"0123456789"[n % 10], 1);
	return (ret + 1);
}

int	ft_hex(unsigned int a, char c)
{
	int	ret;

	ret = 0;
	if (a >= 16)
		ret += ft_hex(a / 16, c);
	if (c == 'x')
		write(1, &"0123456789abcdef"[a % 16], 1);
	if (c == 'X')
		write(1, &"0123456789ABCDEF"[a % 16], 1);
	return (ret + 1);
}

int	ft_point(unsigned long a, int sign)
{
	int	ret;

	ret = 0;
	if (a == 0)
		return (write(1, "(nil)", 5));
	if (sign == 1)
	{
		ret += write(1, "0x", 2);
	}
	if (a >= 16)
		ret += ft_point(a / 16, 0);
	write(1, &"0123456789abcdef"[a % 16], 1);
	return (ret + 1);
}
