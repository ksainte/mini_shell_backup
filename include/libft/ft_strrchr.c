/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:29:25 by bbouaiss          #+#    #+#             */
/*   Updated: 2023/08/10 13:00:15 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	char	*save;

	save = 0;
	ch = (char) c;
	while (*s)
	{
		if (*s == ch)
			save = (char *) s;
		s++;
	}
	if (*s == ch)
		save = (char *) s;
	return (save);
}

/*int	main(void)
{
	char str[50] = "test case for strrchr is ongoing.";
	printf("result ft_strrchr:  %s", ft_strrchr("abcdef.", 'e'));
	printf("\nresult strrchr:  %s", strrchr("abcdef.", 'e'));

	return (0);
}
*/
