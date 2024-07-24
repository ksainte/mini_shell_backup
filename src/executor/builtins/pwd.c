/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:18:42 by brahimb           #+#    #+#             */
/*   Updated: 2024/07/22 10:45:36 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

extern t_shell	shell;

void	builtin_pwd(int fd)
{
	ft_fprintf(fd, "%s\n", search_value_env_lst("PWD"));
	shell.exit_status = 0;
}
