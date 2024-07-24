/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:29:17 by bbouaiss          #+#    #+#             */
/*   Updated: 2023/08/09 16:19:40 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <string.h>
#include <stdio.h>*/
#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}
/*int	main(void)
{
	char ch[]={'g', 'e', 'e', 'k', 's', '\0', '\0'};
	printf("value of original: %lu \n",strlen(ch));
	printf("value of me: %d",ft_strlen(ch));
	
	return (0);
}
*/