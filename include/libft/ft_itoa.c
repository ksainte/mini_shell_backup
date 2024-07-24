/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:51:15 by brahimb           #+#    #+#             */
/*   Updated: 2023/12/30 15:51:44 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_int_len(long nbr)
{
	int	count;

	count = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		count++;
	}
	if (nbr == 0)
		return (count + 1);
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	nbr;
	int		len;
	int		count;
	char	*str;

	nbr = n;
	len = ft_int_len(nbr);
	str = ft_calloc(len, sizeof(char));
	count = len - 1;
	if (!str)
		return (0);
	if (nbr < 0)
		nbr *= -1;
	while (nbr != 0)
	{
		str[--count] = ((nbr % 10) + 48);
		nbr /= 10;
	}
	if (n < 0)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	return (str);
}
