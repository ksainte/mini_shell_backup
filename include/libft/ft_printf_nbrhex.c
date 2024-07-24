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

int	ft_printf_puthex(int n, char *hex)
{
	unsigned int	nb;
	int				total_print;

	total_print = 0;
	nb = n;
	if (nb < 16)
	{
		write(1, &hex[nb], 1);
		total_print++;
	}
	else
	{
		total_print += ft_printf_puthex(nb / 16, hex);
		total_print += ft_printf_puthex(nb % 16, hex);
	}
	return (total_print);
}

int	ft_printf_nbrhex(int nbr, char c)
{
	char				*high;
	char				*low;

	low = "0123456789abcdef";
	high = "0123456789ABCDEF";
	if (c == 'x')
		return (ft_printf_puthex(nbr, low));
	else
		return (ft_printf_puthex(nbr, high));
	return (0);
}
