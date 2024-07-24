/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:28:59 by bbouaiss          #+#    #+#             */
/*   Updated: 2023/08/10 18:11:50 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *to, const void *from, size_t n)
{
	char		*tempto;
	const char	*tempfrom;

	tempto = to;
	tempfrom = from;
	if (!tempto && !tempfrom)
		return (0);
	while (n-- > 0)
		*tempto++ = *tempfrom++;
	return (to);
}
/*
int	main(void)
{
	char str[50] = "test case for memcpy is ongoing.";
	char str2[50] = "test case for memcpy is ongoing.";
	char strto[50] = "................................................";
	char strto2[50] = "................................................";

	printf("\nBefore ft_memcpy(): %s\n", strto);
	ft_memcpy(strto, str, 8*sizeof(char));
	printf("After ft_memcpy():  %s", strto);

	printf("\nBefore memcpy(): %s\n", strto2);
	memcpy(strto2, str2, 8*sizeof(char));
	printf("After memcpy():  %s", strto2);
	return (0);
}
*/
