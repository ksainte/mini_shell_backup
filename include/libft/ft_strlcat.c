/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:29:13 by bbouaiss          #+#    #+#             */
/*   Updated: 2023/08/10 16:55:33 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	char	*des;
	char	*source;
	size_t	end;
	size_t	destlen;

	des = dest;
	source = src;
	end = size;
	while (end-- != 0 && *des != '\0')
		des++;
	destlen = des - dest;
	end = size - destlen;
	if (end == 0)
		return (destlen + ft_strlen(source));
	while (*source != '\0')
	{
		if (end != 1)
		{
			*des++ = *source;
			end--;
		}
		source++;
	}
	*des = '\0';
	return (destlen + (source - src));
}	
/*
int	main(void)
{
	char d[100];
	int c;
	char u[100];
	int o;

	c = strlcat(d, "Brahim", 7);
	o = ft_strlcat(u, "Brahim", 7);
	printf("%s\n%d\n", d, c);
	printf("%s\n%d\n", u, o);
	return (0);
}*/