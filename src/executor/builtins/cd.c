/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:25:30 by brahimb           #+#    #+#             */
/*   Updated: 2024/07/22 10:37:55 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

extern t_shell	shell;

int	execute_cd(char *s)
{
	char	*path;

	path = ft_calloc(PATH_MAX, sizeof(char));
	if (s == NULL || *s == '\0' || ft_strcmp(s, "~") == 0)
		return (chdir(search_value_env_lst("HOME")));
	if (ft_strcmp(s, "-") == 0)
		return (chdir(search_value_env_lst("OLDPWD")));
	if (ft_strcmp(s, ".") == 0)
		return (chdir(search_value_env_lst("PWD")));
	if (ft_strcmp(s, "..") == 0)
	{
		ft_strlcpy(path, search_value_env_lst("PWD"), PATH_MAX);
		ft_strlcat(path, "/", PATH_MAX);
		ft_strlcat(path, s, PATH_MAX);
		return (chdir(path));
	}
	if (s[0] != '/')
	{
		getcwd(path, PATH_MAX);
		ft_strlcat(path, "/", PATH_MAX);
		ft_strlcat(path, s, PATH_MAX);
		// printf("path: %s\n", path);
		return (chdir(path));
	}
	return (chdir(s));
}

void	builtin_cd(int fd, char *s)
{
	char	path[PATH_MAX];
	t_env	*env_lst;

	env_lst = shell.env_lst;
	if (execute_cd(s) != -1)
	{
		getcwd(path, PATH_MAX);
		edit_env_lst(&env_lst, "OLDPWD", search_value_env_lst("PWD"));
		edit_env_lst(&env_lst, "PWD", path);
		shell.exit_status = 0;
	}
	else
	{
		ft_fprintf(fd, "Error: cd\n");
		edit_env_lst(&env_lst, "PWD", shell.pwd);
		edit_env_lst(&env_lst, "OLDPWD", shell.pwd);
		chdir(shell.pwd);
		shell.exit_status = 1;
	}
}
