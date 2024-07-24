/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:47:16 by ksainte           #+#    #+#             */
/*   Updated: 2024/07/11 09:49:52 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

// int	ft_strlen(char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 		i++;
// 	return (i);
// }

int	ft_n_present(char *left_str, char c)
{
	int	i;

	i = 0;
	if (!left_str)
		return (0);
	while (left_str[i] != '\0')
	{
		if (left_str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

// static char	*ft_append(char *dest, char const *src)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	while (dest[i] != '\0')
// 		i++;
// 	j = 0;
// 	while (src[j])
// 		dest[i++] = src[j++];
// 	dest[i] = '\0';
// 	return (dest);
// }

// char	*ft_strjoin1(char *test, char *buff)
// {
// 	size_t	len_s2;
// 	size_t	len_s1;
// 	char	*ms;

// 	if (!test || !buff)
// 		return (NULL);
// 	len_s1 = ft_strlen(test);
// 	len_s2 = ft_strlen(buff);
// 	ms = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
// 	if (ms == NULL)
// 		return (NULL);
// 	*ms = 0;
// 	ms = ft_append(ms, test);
// 	ms = ft_append(ms, buff);
// 	free(test);
// 	return (ms);
// }

// void	*ft_memcpy(void *dst, const void *src, size_t n)
// {
// 	char	*dst2;
// 	char	*src2;
// 	size_t	i;

// 	if (dst == NULL && src == NULL)
// 		return (NULL);
// 	i = 0;
// 	dst2 = (char *)dst;
// 	src2 = (char *)src;
// 	while (i < n)
// 	{
// 		dst2[i] = src2[i];
// 		i++;
// 	}
// 	return (dst2);
// }
