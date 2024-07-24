/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbrhex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:44:49 by brahimb           #+#    #+#             */
/*   Updated: 2023/08/24 17:54:56 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_fprintf_puthex(int fd, int n, char *hex)
{
	unsigned int	nb;
	int				total_print;

	total_print = 0;
	nb = n;
	if (nb < 16)
	{
		write(fd, &hex[nb], 1);
		total_print++;
	}
	else
	{
		total_print += ft_fprintf_puthex(fd, nb / 16, hex);
		total_print += ft_fprintf_puthex(fd, nb % 16, hex);
	}
	return (total_print);
}

int	ft_fprintf_nbrhex(int fd, int nbr, char c)
{
	char				*high;
	char				*low;

	low = "0123456789abcdef";
	high = "0123456789ABCDEF";
	if (c == 'x')
		return (ft_fprintf_puthex(fd, nbr, low));
	else
		return (ft_fprintf_puthex(fd, nbr, high));
	return (0);
}
