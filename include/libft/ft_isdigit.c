/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:14:05 by bbouaiss          #+#    #+#             */
/*   Updated: 2023/08/03 21:10:39 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <ctype.h>
#include <stdio.h>*/
#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	return (0);
}
/*int	main(void)
{
	printf("value of original: %d \n",isdigit(5));
	printf("value of me: %d",ft_isdigit(5));
	return (0);
}
*/