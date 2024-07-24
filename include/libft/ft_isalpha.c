/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:15:31 by bbouaiss          #+#    #+#             */
/*   Updated: 2023/08/03 21:10:32 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <ctype.h>
#include <stdio.h>*/
#include "libft.h"

int	ft_isalpha(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1024);
	if (c >= 'A' && c <= 'Z')
		return (1024);
	return (0);
}
/*
int	main(void)
{
	printf("value of original: %d \n",isalpha(-65));
	printf("value of me: %d",ft_isalpha(-65));
	return (0);
}
*/