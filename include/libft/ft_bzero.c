/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:28:26 by bbouaiss          #+#    #+#             */
/*   Updated: 2023/08/03 21:10:22 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <string.h>
#include <stdio.h>*/
#include "libft.h"

void	ft_bzero(void *ptr, size_t n)
{
	char	*temp;
	size_t	count;

	temp = ptr;
	count = 0;
	while (count < n)
		*(temp + count++) = '\0';
}

/*int	main(void)
{
	char str[50] = "test case for bzero is ongoing.";
	char str2[50] = "test case for bzero is ongoing.";

	printf("\nBefore ft_bzero(): %s\n", str);
	ft_bzero(str + 25, 8*sizeof(char));
	printf("After ft_bzero():  %s", str);

	printf("\nBefore bzero(): %s\n", str2);
	bzero(str2 + 25, 8*sizeof(char));
	printf("After bzero():  %s", str);
	return (0);
}*/
