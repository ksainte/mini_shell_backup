/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:28:56 by bbouaiss          #+#    #+#             */
/*   Updated: 2023/08/07 14:39:38 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*st1;
	unsigned char	*st2;
	size_t			count;

	st1 = (unsigned char *) s1;
	st2 = (unsigned char *) s2;
	count = 0;
	while (count < n)
	{
		if (st1[count] != st2[count])
			return (st1[count] - st2[count]);
		count++;
	}
	return (0);
}
/*int	main(void)
{
	char str[50] = "test case for memchr is ongoing.";
	char str2[50] = "test case for memchr is ongong.";
	int testft = ft_memcmp(str, str2, 50);
	int test = memcmp(str, str2, 50);
	printf("result ft_memchr:  %d", testft);
	printf("\nresult memchr:  %d", test);

	return (0);
}
*/