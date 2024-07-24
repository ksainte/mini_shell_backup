/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:49:59 by brahimb           #+#    #+#             */
/*   Updated: 2024/06/07 12:05:48 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*create_str(const char *s1, size_t start, size_t len)
{
	char	*str;
	size_t	count;

	if (len <= 0 || start >= ft_strlen(s1))
		return (ft_strdup(""));
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	count = 0;
	while (count < len)
	{
		str[count] = s1[start + count];
		count++;
	}
	return (str);
}

int	to_trim(const char *set, char c)
{
	int	count;

	count = 0;
	while (set[count])
	{
		if (c == set[count])
			return (1);
		count++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int	count;
	int	count2;

	count = 0;
	count2 = ft_strlen(s1) - 1;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	while (to_trim(set, s1[count]))
		count++;
	while (to_trim(set, s1[count2]))
		count2--;
	return (create_str(s1, count, count2 - (count - 1)));
}

/*int	main(void)
{
	char str[50] = "cccmtest case for strtrim is ongoingmm.";
	printf("result ft_substr:  %s", ft_strtrim(str, "cm"));

	return (0);
}
*/