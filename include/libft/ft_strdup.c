/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:29:10 by bbouaiss          #+#    #+#             */
/*   Updated: 2023/08/07 17:23:03 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copystr;
	int		count;

	count = 0;
	copystr = (char *) malloc(ft_strlen(s1) + 1);
	if (!copystr)
		return (0);
	while (s1[count])
	{
		copystr[count] = s1[count];
		count++;
	}
	copystr[count] = '\0';
	return (copystr);
}
/*
int	main(void)
{

	return (0);
}
*/