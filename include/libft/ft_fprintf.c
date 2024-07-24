/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:44:49 by brahimb           #+#    #+#             */
/*   Updated: 2024/07/22 10:26:58 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_fprintf_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_fprintf_str(int fd, char *str)
{
	int		total_print;

	total_print = 0;
	if (str == NULL)
	{
		write(fd, "(null)", 6);
		total_print = 6;
	}
	while (str && *str)
	{
		ft_printf_putchar(*str++, fd);
		total_print++;
	}
	return (total_print);
}

int	ft_fprintf_char(int fd, char c)
{
	int		total_print;

	total_print = 0;
	ft_fprintf_putchar(c, fd);
	total_print++;
	return (total_print);
}

int	ft_fprint_any(int fd, char c, va_list *argsp)
{
	int		total_print;

	total_print = 0;
	if (c == 'c')
		total_print += ft_fprintf_char(fd, va_arg(*argsp, int));
	if (c == 's')
		total_print += ft_fprintf_str(fd, va_arg(*argsp, char *));
	if (c == 'p')
		total_print += ft_fprintf_pointer(fd, va_arg(*argsp, unsigned long long));
	if (c == 'd' || c == 'i')
		total_print += ft_fprintf_nbr(va_arg(*argsp, int), fd);
	if (c == 'u')
		total_print += ft_fprintf_unbr(va_arg(*argsp, unsigned int), fd);
	if (c == 'X' || c == 'x')
		total_print += ft_fprintf_nbrhex(fd, va_arg(*argsp, int), c);
	if (c == '%')
	{
		ft_fprintf_putchar('%', fd);
		total_print++;
	}
	return (total_print);
}

int	ft_fprintf(int fd, const char *str, ...)
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
			ft_fprintf_putchar(c, fd);
			total_print++;
		}
		else
		{
			c = *++str;
			total_print += ft_fprint_any(fd, c, &args);
		}
		str++;
	}
	va_end(args);
	return (total_print);
}
