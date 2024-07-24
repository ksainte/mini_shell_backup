/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:47:49 by brahimb           #+#    #+#             */
/*   Updated: 2024/07/22 11:20:07 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

extern t_shell	shell;

void	builtin_unset(char **strs)
{
	shell.exit_status = 0;
	while (*strs)
	{
		if (ft_strcmp(*strs, "_") == 1)
			delete_env_lst(&shell.env_lst, *strs);
		strs++;
	}
}
