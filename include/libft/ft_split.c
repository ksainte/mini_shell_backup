/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:50:14 by brahimb           #+#    #+#             */
/*   Updated: 2023/12/30 15:50:40 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_malloc_error(char **strs)
{
	size_t	count;

	count = 0;
	while (strs[count])
	{
		free(strs[count]);
		count++;
	}
	free(strs);
	return (0);
}

size_t	ft_total_words(char const *s, char c)
{
	size_t	count;
	size_t	words;

	if (!s[0])
		return (0);
	count = 0;
	words = 0;
	while (s[count] && s[count] == c)
		count++;
	while (s[count])
	{
		if (s[count] == c)
		{
			words++;
			while (s[count] && s[count] == c)
				count++;
			continue ;
		}
		count++;
	}
	if (s[count - 1] != c)
		words++;
	return (words);
}

void	ft_get_next_word(char **next_word, size_t *next_word_len, char c)
{
	size_t	count;

	*next_word += *next_word_len;
	*next_word_len = 0;
	count = 0;
	while (**next_word && **next_word == c)
		(*next_word)++;
	while ((*next_word)[count])
	{
		if ((*next_word)[count] == c)
			return ;
		(*next_word_len)++;
		count++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	char	*next_word;
	size_t	next_word_len;
	size_t	count;

	if (!s)
		return (0);
	strs = (char **)malloc(sizeof(char *) * (ft_total_words(s, c) + 1));
	if (!strs)
		return (0);
	count = 0;
	next_word = (char *)s;
	next_word_len = 0;
	while (count < ft_total_words(s, c))
	{
		ft_get_next_word(&next_word, &next_word_len, c);
		strs[count] = (char *)malloc(sizeof(char) * (next_word_len + 1));
		if (!strs[count])
			return (ft_malloc_error(strs));
		ft_strlcpy(strs[count], next_word, next_word_len + 1);
		count++;
	}
	strs[count] = 0;
	return (strs);
}

/*int	main(void)
{
	char str[50] = "test case for split is ongoing.";
	char **x = ft_split(str, 's');
	printf("result ft_split:  %s", x[2]);

	return (0);
}
*/
