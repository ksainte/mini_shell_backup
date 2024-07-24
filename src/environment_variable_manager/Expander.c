/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:55:15 by brahimb           #+#    #+#             */
/*   Updated: 2024/07/21 16:40:54 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern t_shell	shell;

char	*search_env_key(char *key)
{
	char *tmp_key;
	char *tmp;

	tmp_key = search_value_env_lst(key);
	if (tmp_key == NULL)
	{
		tmp = ft_strtok(key, "/");
		tmp_key = search_value_env_lst(tmp);
		tmp = tmp_key;
		if (tmp_key != NULL)
		{
			tmp_key = ft_strjoin(tmp, "/");
			free(tmp);
			tmp = tmp_key;
			tmp_key = ft_strjoin(tmp, ft_strtok(NULL, ""));
			free(tmp);
		}
	}
	return (tmp_key);
}

void	expand_env(t_node **node)
{
	t_node	*tmp;
	char	*value;
	char	*tmp_value;

	tmp = *node;
	value = tmp->value;
	tmp_value = NULL;
	if (ft_strncmp(tmp->value, "$?", 2) == 0)
	{
		tmp->value = ft_itoa(shell.exit_status);
		free(value);
	}
	else if (tmp->value[0] == '$' && ft_strlen(tmp->value) != 1)
	{
		tmp_value = search_env_key(tmp->value + 1);
		if (tmp_value == NULL)
			tmp->value = ft_strdup("");
		else
			tmp->value = ft_strdup(tmp_value);
		free(value);
	}
}

void	expander(t_node **node_list)
{
	t_node	*tmp;

	tmp = *node_list;
	while (tmp)
	{
		if (tmp->type == WORD || tmp->type == DOUBLE_QUOTE)
			expand_env(&tmp);
		tmp = tmp->next;
	}
}
