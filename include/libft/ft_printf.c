/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:44:49 by brahimb           #+#    #+#             */
/*   Updated: 2024/05/31 16:27:28 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_printf_str(char *str)
{
	int		total_print;

	total_print = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		total_print = 6;
	}
	while (str && *str)
	{
		ft_printf_putchar(*str++, 1);
		total_print++;
	}
	return (total_print);
}

int	ft_printf_char(char c)
{
	int		total_print;

	total_print = 0;
	ft_printf_putchar(c, 1);
	total_print++;
	return (total_print);
}

int	ft_print_any(char c, va_list *argsp)
{
	int		total_print;

	total_print = 0;
	if (c == 'c')
		total_print += ft_printf_char(va_arg(*argsp, int));
	if (c == 's')
		total_print += ft_printf_str(va_arg(*argsp, char *));
	if (c == 'p')
		total_print += ft_printf_pointer(va_arg(*argsp, unsigned long long));
	if (c == 'd' || c == 'i')
		total_print += ft_printf_nbr(va_arg(*argsp, int), 1);
	if (c == 'u')
		total_print += ft_printf_unbr(va_arg(*argsp, unsigned int), 1);
	if (c == 'X' || c == 'x')
		total_print += ft_printf_nbrhex(va_arg(*argsp, int), c);
	if (c == '%')
	{
		ft_printf_putchar('%', 1);
		total_print++;
	}
	return (total_print);
}

int	ft_printf(const char *str, ...)
{
	int		total_print;
	char	c;
	va_list	args;

	total_print = 0;
	c = 0;
	va_start(args, str);
	while (*str)
	{
		c = *str;
		if (c != '%')
		{
			ft_printf_putchar(c, 1);
			total_print++;
		}
		else
		{
			c = *++str;
			total_print += ft_print_any(c, &args);
		}
		str++;
	}
	va_end(args);
	return (total_print);
}
