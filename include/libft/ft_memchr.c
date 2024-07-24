/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:28:50 by bbouaiss          #+#    #+#             */
/*   Updated: 2023/08/07 13:59:11 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <string.h>*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*st;
	size_t			count;

	ch = (unsigned char) c;
	st = (unsigned char *) s;
	count = 0;
	while (count < n)
	{
		if (st[count] == ch)
			return ((void *) &st[count]);
		count++;
	}
	return (0);
}
/*int	main(void)
{
	char str[50] = "test case for memchr is ongoing.";
	char *ptrtestft = ft_memchr(str, 'e', 1);
	char *ptrtest = memchr(str, 'e', 3);
	printf("result ft_memchr:  %s", ptrtestft);
	printf("\nresult memchr:  %s", ptrtest);

	return (0);
}
*/