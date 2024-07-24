/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:44:49 by brahimb           #+#    #+#             */
/*   Updated: 2023/08/24 17:54:56 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_unbr(unsigned int n, int fd)
{
	char				*dec;
	unsigned int		nb;
	int					total_print;

	nb = n;
	dec = "0123456789";
	total_print = 0;
	if (nb >= 10)
	{
		total_print += ft_printf_unbr(nb / 10, fd);
		total_print += ft_printf_unbr(nb % 10, fd);
	}
	else
	{
		write(fd, &dec[nb], 1);
		total_print++;
	}
	return (total_print);
}
