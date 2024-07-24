/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:28:19 by bbouaiss          #+#    #+#             */
/*   Updated: 2023/12/30 15:48:41 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char ch)
{
	if (ch == 9 || ch == 10 || ch == 11 || ch == 12 || ch == 13 || ch == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	count;
	int	result;

	sign = 1;
	count = 0;
	result = 0;
	while (ft_isspace(str[count]))
		count++;
	if (str[count] == '+' && str[count + 1] != '-')
		count++;
	if (str[count] == '-')
	{
		sign = -1;
		count++;
	}
	while (str[count] && str[count] >= 48 && str[count] <= 57)
	{
		result *= 10;
		result += str[count] - 48;
		count++;
	}
	return (result * sign);
}

/*
int	main(void)
{
	int		atoi;
	int		ft_atoi;
	char	str[] = {"  \t	 ++--1221"};

	atoi = atoi(str);
	ft_atoi = ft_atoi(str);
	printf("atoi %d\nft_atoi %d\n", atoi, ft_atoi);
	return (0);
}
*/