/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnvironmentVariableManager.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:46:53 by brahimb           #+#    #+#             */
/*   Updated: 2024/07/24 13:13:20 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern t_shell	shell;

int	add_env_lst(t_env **env_lst, char *key, char *value)
{
	t_env	*new_lst;
	t_env	*last_lst;

	new_lst = (t_env *)malloc(sizeof(t_env));
	if (!new_lst)
		return (1);
	if (!key || !value)
		return (0);
	last_lst = *env_lst;
	new_lst->key = ft_strdup(key);
	new_lst->value = ft_strdup(value);
	new_lst->next = NULL;
	if (*env_lst == NULL)
	{
		new_lst->prev = NULL;
		*env_lst = new_lst;
	}
	else
	{
		while (last_lst->next)
			last_lst = last_lst->next;
		last_lst->next = new_lst;
		new_lst->prev = last_lst;
	}
	return (0);
}

void	print_env_lst(int fd, int mode)
{
	t_env	*env_lst;

	env_lst = shell.env_lst;
	while (env_lst->prev)
		env_lst = env_lst->prev;
	while (env_lst)
	{
		if (mode == 1 && ft_strncmp(env_lst->value, "", 2) != 0 && ft_strncmp(env_lst->value, "\t", 2) != 0)
			ft_fprintf(fd, "%s=%s\n", env_lst->key, env_lst->value);
		if (mode == 1 && ft_strncmp(env_lst->value, "", 2) == 0)
			ft_fprintf(fd, "%s=''\n", env_lst->key);
		if (mode == 1 && ft_strncmp(env_lst->value, "\t", 2) == 0)
			ft_fprintf(fd, "%s=''\n", env_lst->key, "");
		if (mode == 2 && ft_strncmp(env_lst->value, "", 2) != 0)
			ft_fprintf(fd, "%s=%s\n", env_lst->key, env_lst->value);
		if (mode == 0)
			ft_fprintf(fd, "%s=%s\n", env_lst->key, env_lst->value);
		env_lst = env_lst->next;
	}
}

char	*search_value_env_lst(char *key)
{
	t_env	*env_lst;

	env_lst = shell.env_lst;
	while (env_lst->prev)
		env_lst = env_lst->prev;
	while (env_lst)
	{
		if (!ft_strcmp(env_lst->key, key))
			return (env_lst->value);
		env_lst = env_lst->next;
	}
	return (NULL);
}

int	initiliaze_envp(char **envp)
{
	t_env	*env_lst;

	env_lst = NULL;
	if (!envp)
		return (1);
	while (*envp)
	{
		if (add_env_lst(&env_lst, ft_strtok(*envp, "="), ft_strtok(NULL, "")))
			return (1);
		envp++;
	}
	while (env_lst->prev)
		env_lst = env_lst->prev;
	shell.env_lst = env_lst;
	return (0);
}
