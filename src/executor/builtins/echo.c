/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:03:24 by brahimb           #+#    #+#             */
/*   Updated: 2024/07/23 10:22:17 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	check_option(char *str)
{
	while (*str)
	{
		if (*str != 'n')
			return (0);
		str++;
	}
	return (1);
}

void	builtin_echo(char **strs, int fd)
{
	bool	new_line;

	new_line = true;
	while (*++strs != NULL && ft_strncmp(strs[0], "-", 1) == 0)
	{
		if (check_option(*strs + 1))
			new_line = false;
		else
			break ;
	}
	while (*strs)
	{
		write(fd, *strs, ft_strlen(*strs));
		strs++;
		if (*strs)
			write(fd, " ", 1);
	}
	if (new_line)
		write(fd, "\n", 1);
}
