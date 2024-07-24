/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:58:31 by brahimb           #+#    #+#             */
/*   Updated: 2024/07/22 10:40:04 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

extern t_shell	shell;

int	check_exit_code(int fd, char *str)
{
	char	*int_str;
	int		exit_code;

	exit_code = 0;
	int_str = str;
	if (str != NULL)
	{
		if (*str == '-' || *str == '+')
			str++;
		while (*str)
		{
			if (!ft_isdigit(*str))
			{
				ft_fprintf(fd, " >: exit: %s: numeric argument required\n", int_str);
				exit(EXIT_NUMERIC_ERROR);
			}
			str++;
		}
		exit_code = ft_atoi(int_str);
	}
	return (exit_code);
}

void	builtin_exit(int fd, char **strs)
{
	char	*int_str;

	int_str = strs[0];
	if (strs[1])
	{
		ft_fprintf(fd, "exit: too many arguments\n");
		shell.exit_status = 1;
		return ;
	}
	shell.exit_status = check_exit_code(fd, int_str);
	exit(shell.exit_status);
}
