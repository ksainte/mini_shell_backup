/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:12:32 by brahimb           #+#    #+#             */
/*   Updated: 2024/07/23 11:03:04 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_shell	shell;

int	main(int argc, char **argv, char **envp)
{
	//fix to env -i segfault
	if (!envp[0])
		exit(0);
	shell.exit_status = 0;
	if (argc != 1 || argv[1])
		printf("Error: too many arguments\n");
	else
	{
		initiliaze_signal();
		if (initiliaze_envp(envp))
			return (1);
		shell.pwd = ft_strdup(search_value_env_lst("PWD"));
		shell.exit_status = cli();
	}
	return (shell.exit_status);
}
