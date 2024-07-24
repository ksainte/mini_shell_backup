/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:29:22 by bbouaiss          #+#    #+#             */
/*   Updated: 2023/08/07 17:35:25 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *find, size_t len)
{
	size_t	c;
	size_t	x;

	c = 0;
	x = 0;
	if (find[0] == 0)
		return ((char *) s);
	while (c < len && s[c])
	{
		while (s[c + x] == find[x] && s[c + x] && c + x < len)
		{
			x++;
			if (find[x] == 0)
				return ((char *) s + c);
		}
		c++;
		x = 0;
	}
	return (0);
}
/*
int main(void)
{
	char	*strnstr1;
	char	*strnstr2;
	char	str0[] = {"Hello world!"};
	char	str1[] = {"world"};

	strnstr1 = strnstr(str0, str1, 5);
	strnstr2 = ft_strnstr(str0, str1, 5);
	printf("native - %s\n ft - %s\n", ret_strnstr, ret_ft_strnstr);
	return (0);
}
*/