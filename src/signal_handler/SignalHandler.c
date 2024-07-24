/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SignalHandler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:21:20 by brahimb           #+#    #+#             */
/*   Updated: 2024/07/23 15:02:07 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern t_shell	shell;

void	signal_handler_child(int sigtype)
{
	int	status;
	int	pid_stat;
	int shell_lvl;

	pid_stat = 1;
	shell_lvl = 0;
	if (sigtype == SIGCHLD)
	{
		shell_lvl = ft_atoi(search_value_env_lst("SHLVL")) + 1;
		edit_env_lst(&shell.env_lst, "SHLVL", ft_itoa(shell_lvl));
		while (pid_stat > 0)
			pid_stat = waitpid(-1, &status, WNOHANG);
		// if (WTERMSIG(status) == SIGINT)
		// {
		// 	shell.sig_c = 1;
		// }
		//	printf("");
		edit_env_lst(&shell.env_lst, "SHLVL", ft_itoa(shell_lvl - 1));
		shell.exit_status = WEXITSTATUS(status);
		// dprintf(2, "is %d", shell.exit_status);
	}
}

void	signal_handler_default(int sigtype)
{
	if (sigtype == SIGINT)
	{
		if (wait3(NULL, WNOHANG, NULL) != -1)
			printf("\n");
		else
		{
			printf("\n");
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
		shell.sig_c = 1;
	}
}

void	signal_to_default_behaviour(void)
{
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
}

void	initiliaze_signal(void)
{
	struct sigaction	sa_default;
	struct sigaction	sa_ignore;

	sa_default.sa_handler = signal_handler_default;
	sigemptyset(&sa_default.sa_mask);
	sa_default.sa_flags = SA_RESTART;
	sa_ignore.sa_handler = SIG_IGN;
	sigemptyset(&sa_ignore.sa_mask);
	sa_ignore.sa_flags = 0;
	sigaction(SIGINT, &sa_default, NULL);
	sigaction(SIGQUIT, &sa_ignore, NULL);
	signal(SIGCHLD, signal_handler_child);
}
