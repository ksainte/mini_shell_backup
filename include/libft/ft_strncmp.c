/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:29:20 by bbouaiss          #+#    #+#             */
/*   Updated: 2023/08/10 04:15:57 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <string.h>
#include <stdio.h>*/
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 0;
	while ((s1[count] || s2[count]) && count < n)
	{
		if ((unsigned char) s1[count] != (unsigned char) s2[count])
			return ((unsigned char) s1[count] - (unsigned char) s2[count]);
		count++;
	}
	return (0);
}
/*
int main(void)
{
	char str1[] = "AA";//{'\201'};
	char str2[] = "AA0";//{'A'};

	printf("%d\n", strncmp(str1, str2));
	printf("%d", ft_strncmp(str1, str2));
	return (0);
}*/