/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:52:01 by brahimb           #+#    #+#             */
/*   Updated: 2023/08/09 13:42:17 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		count;
	char				*str;

	count = 0;
	str = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!str)
		return (0);
	while (s[count] != '\0')
	{
		str[count] = (*f)(count, s[count]);
		count++;
	}
	return (str);
}
/*
int	main(int argc, char **argv)
{

	return (0);
}
*/