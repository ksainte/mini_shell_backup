/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:28:30 by bbouaiss          #+#    #+#             */
/*   Updated: 2023/08/10 18:30:57 by bbouaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elemsize)
{
	void	*ptr;

	ptr = malloc(nelem * elemsize);
	if (ptr == NULL)
		return (NULL);
	if (ptr)
		ft_bzero(ptr, nelem * elemsize);
	return (ptr);
}
/*
int	main(void)
{
	void	*ptrcalloc;
	void	*ptrft_calloc;

	ptrcalloc = calloc(10, 4);
	ptrft_calloc = ft_calloc(10, 4);
	if (!ft_memcmp(ptrcalloc, ptrft_calloc, (10 * 4)))
		printf("Test - OK\n", 1);
	else
		printf("Test- KO\n", 1);
	free(ptrcalloc);
	free(ptrft_calloc);
	return (0);
}
*/
