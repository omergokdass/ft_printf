/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogokdas <ogokdas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 21:34:31 by ogokdas           #+#    #+#             */
/*   Updated: 2025/07/03 21:04:09 by ogokdas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_format(va_list args, char c);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	ft_uint(unsigned int n);
int	ft_hex(unsigned int n, char c);
int	ft_point(unsigned long n, int sign);

#endif
