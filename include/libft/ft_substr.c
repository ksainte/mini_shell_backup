/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:49:20 by brahimb           #+#    #+#             */
/*   Updated: 2023/08/10 14:02:44 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	char	*substr;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	substr = ft_calloc(len + 1, sizeof(char));
	count = 0;
	if (!substr)
		return (0);
	while (count < len)
	{
		substr[count] = s[start + count];
		count++;
	}
	return (substr);
}
/*int	main(void)
{
	char str[50] = "test case for substr is ongoing.";
	printf("result ft_substr:  %s", ft_substr(str, 10,20));

	return (0);
}
*/
