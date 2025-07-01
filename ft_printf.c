/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogokdas <ogokdas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 21:33:39 by ogokdas           #+#    #+#             */
/*   Updated: 2025/07/01 21:33:39 by ogokdas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_format(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg((args), int)));
	else if (c == 's')
		return (ft_putstr(va_arg((args), char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg((args), int)));
	else if (c == 'u')
		return (ft_uint(va_arg((args), unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_hex(va_arg((args), unsigned int), c));
	else if (c == 'p')
		return (ft_point(va_arg((args), unsigned long), 1));
	else if (c == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			len += ft_format(args, str[i + 1]);
			i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
