/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogokdas <ogokdas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 21:35:44 by ogokdas           #+#    #+#             */
/*   Updated: 2025/07/03 20:19:34 by ogokdas          ###   ########.fr       */
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
	ret += write(1, &"0123456789"[n % 10], 1);
	return (ret);
}

int	ft_uint(unsigned int n)
{
	int	ret;

	ret = 0;
	if (n >= 10)
		ret += ft_uint(n / 10);
	ret += write(1, &"0123456789"[n % 10], 1);
	return (ret);
}

int	ft_hex(unsigned int n, char c)
{
	int	ret;

	ret = 0;
	if (n >= 16)
		ret += ft_hex(n / 16, c);
	if (c == 'x')
		ret += write(1, &"0123456789abcdef"[n % 16], 1);
	else if (c == 'X')
		ret += write(1, &"0123456789ABCDEF"[n % 16], 1);
	return (ret);
}

int	ft_point(unsigned long n, int sign)
{
	int	ret;

	ret = 0;
	if (n == 0)
		return (write(1, "(nil)", 5));
	if (sign == 1)
	{
		ret += write(1, "0x", 2);
	}
	if (n >= 16)
		ret += ft_point(n / 16, 0);
	ret += write(1, &"0123456789abcdef"[n % 16], 1);
	return (ret);
}
