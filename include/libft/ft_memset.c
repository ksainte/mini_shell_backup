/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:29:04 by bbouaiss          #+#    #+#             */
/*   Updated: 2023/08/03 21:11:05 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"

void	*ft_memset(void *ptr, int x, size_t n)
{
	size_t	count;
	char	*temp;

	count = 0;
	temp = ptr;
	while (count < n)
		*(temp + count++) = x;
	return (ptr);
}

/*int	main(void)
{
	char str[50] = "test case for memset is ongoing.";
	char str2[50] = "test case for memset is ongoing.";

	printf("\nBefore ft_memset(): %s\n", str);
	ft_memset(str + 25, '.', 8*sizeof(char));
	printf("After ft_memset():  %s", str);

	printf("\nBefore memset(): %s\n", str2);
	memset(str2 + 25, '.', 8*sizeof(char));
	printf("After memset():  %s", str);
	return (0);
}*/
