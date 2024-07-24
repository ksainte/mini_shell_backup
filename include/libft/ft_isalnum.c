/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:25:50 by bbouaiss          #+#    #+#             */
/*   Updated: 2023/08/03 21:10:28 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <ctype.h>
#include <stdio.h>*/
#include "libft.h"

int	ft_isalnum(int c)
{
	if (c >= 'a' && c <= 'z')
		return (8);
	if (c >= 'A' && c <= 'Z')
		return (8);
	if (c >= '0' && c <= '9')
		return (8);
	return (0);
}
/*
int	main(void)
{
	printf("value of original: %d \n",isalnum(65));
	printf("value of me: %d",ft_isalnum(65));
	return (0);
}
*/