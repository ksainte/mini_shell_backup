/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:29:08 by bbouaiss          #+#    #+#             */
/*   Updated: 2024/06/06 17:02:53 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = c;
	while (*s != ch)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return ((char *) s);
}
#include <stdio.h>

// int	main(void)
// {
// 	char str[50] = "test case for strchr is ongoing.";
// 	printf("result ft_strchr:  %s", ft_strchr("abcdef.", 'b'));
// 	return (0);
// }
