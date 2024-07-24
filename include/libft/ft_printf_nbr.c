/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:44:49 by brahimb           #+#    #+#             */
/*   Updated: 2023/08/24 17:54:56 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_nbr(int n, int fd)
{
	char	c;
	long	nb;
	int		total_print;

	nb = n;
	c = 'x';
	total_print = 0;
	if (nb < 0)
	{
		write(fd, "-", 1);
		total_print++;
		nb = nb * -1;
	}
	if (nb < 10)
	{
		c = nb + '0';
		write(fd, &c, 1);
		total_print++;
	}
	else
	{
		total_print += ft_printf_nbr(nb / 10, fd);
		total_print += ft_printf_nbr(nb % 10, fd);
	}
	return (total_print);
}
