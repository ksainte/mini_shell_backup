/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:49:43 by brahimb           #+#    #+#             */
/*   Updated: 2023/08/07 21:05:43 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		count;
	int		count2;
	char	*str;

	count = 0;
	count2 = 0;
	str = (char *) ft_calloc((ft_strlen(s1) + ft_strlen(s2)) + 1, sizeof(char));
	if (!str)
		return (0);
	while (s1[count])
	{
		str[count] = s1[count];
		count++;
	}
	while (s2[count2])
		str[count++] = s2[count2++];
	return (str);
}
/*int	main(void)
{
	char str[50] = "test case for ft_strjoin is ongoing.";

	printf("result ft_strjoin:  %s", ft_strjoin("str", "join"));
	return (0);
}
*/