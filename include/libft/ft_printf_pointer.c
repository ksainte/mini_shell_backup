/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:44:49 by brahimb           #+#    #+#             */
/*   Updated: 2024/05/31 16:27:48 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_putptr_fd(unsigned long long n, int fd)
{
	unsigned long long	nb;
	char				*c;
	int					total_print;

	c = "0123456789abcdef";
	total_print = 0;
	nb = n;
	if (nb < 16)
	{
		write(fd, &c[nb], 1);
		total_print++;
	}
	else
	{
		total_print += ft_printf_putptr_fd(nb / 16, fd);
		total_print += ft_printf_putptr_fd(nb % 16, fd);
	}
	return (total_print);
}

int	ft_printf_pointer(unsigned long long ptr)
{
	int		total_print;

	total_print = 2;
	write(1, "0x", 2);
	if (ptr == 0)
	{
		write(1, "0", 1);
		total_print++;
	}
	else
	{
		total_print += ft_printf_putptr_fd(ptr, 1);
	}
	return (total_print);
}