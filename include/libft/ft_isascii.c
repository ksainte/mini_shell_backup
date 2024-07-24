/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:32:45 by bbouaiss          #+#    #+#             */
/*   Updated: 2023/08/03 21:10:35 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <ctype.h>
#include <stdio.h>*/
#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*int	main(void)
{
	printf("value of original: %d \n",isascii(555));
	printf("value of me: %d",ft_isascii(555));
	return (0);
}
*/