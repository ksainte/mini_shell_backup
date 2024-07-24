/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:39:34 by brahimb           #+#    #+#             */
/*   Updated: 2024/06/21 13:42:58 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	count;

	count = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (1);
	while (s1[count] || s2[count])
	{
		if ((unsigned char) s1[count] != (unsigned char) s2[count])
			return ((unsigned char) s1[count] - (unsigned char) s2[count]);
		count++;
	}
	return (0);
}
