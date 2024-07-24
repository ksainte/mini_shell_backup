/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:29:02 by bbouaiss          #+#    #+#             */
/*   Updated: 2023/12/30 15:51:20 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"

void	*ft_memmove(void *to, const void *from, size_t n)
{
	unsigned char		*tempto;
	unsigned char		*tempfrom;
	size_t				count;

	tempto = (unsigned char *)to;
	tempfrom = (unsigned char *)from;
	count = -1;
	if (tempfrom > tempto)
	{
		while (n > ++count)
			tempto[count] = tempfrom[count];
	}
	else if (tempfrom < tempto)
	{
		while (n > 0)
		{
			tempto[n - 1] = tempfrom[n - 1];
			n--;
		}
	}
	else if (tempto == tempfrom)
		tempto = tempfrom;
	return (to);
}

/*
int	main(void)
{
	char str[50] = "test case for memmove is ongoing.mmm";
	char str2[50] = "test case for memmove is ongoing.mmm";
	char strto[50] = "................................................";
	char strto2[50] = "................................................";

	printf("\nBefore ft_memmove(): %s\n", strto);
	ft_memmove(strto, str, 90*sizeof(char));
	printf("After ft_memmove():  %s", strto);

	printf("\nBefore memmove(): %s\n", strto2);
	memmove(strto2, str2, 90*sizeof(char));
	printf("After memmove():  %s", strto2);
	return (0);
}
*/
