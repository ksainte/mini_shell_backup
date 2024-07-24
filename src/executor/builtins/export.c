/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:45:59 by brahimb           #+#    #+#             */
/*   Updated: 2024/07/23 10:50:54 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

extern t_shell	shell;

void	add_empty_key(t_env **env_lst, char *key, char *value)
{
	if (!search_value_env_lst(key))
		add_env_lst(env_lst, key, value);
		//edit_env_lst(env_lst, key, value);
	//else
		//add_env_lst(env_lst, key, value);
}

void	builtin_export(int fd, char **strs)
{
	char	*key;
	char	*value;
	t_env	*env_lst;

	env_lst = shell.env_lst;
	shell.exit_status = 0;
	if (!strs[0])
		return	print_env_lst(fd, 1); 
	while (*strs)
	{
		if (ft_strchr(*strs, '='))
		{
			key = ft_strtok(*strs, "=");
			value = ft_strtok(NULL, "=");
			if (!value)
				value = "\t";
			if (search_value_env_lst(key))
				edit_env_lst(&env_lst, key, value);
			else
				add_env_lst(&env_lst, key, value);
		}
		else
			add_empty_key(&env_lst, *strs, "");
		strs++;
	}
}
