/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnvironmentVariableManagerHelper.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:08:49 by brahimb           #+#    #+#             */
/*   Updated: 2024/07/24 13:12:52 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**env_lst_to_tab(t_env *env_lst)
{
	t_env	*tmp;
	char	**env_tab;
	int		i;

	tmp = env_lst;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	env_tab = malloc(sizeof(char *) * (i + 1));
	if (!env_tab)
		return (NULL);
	i = 0;
	while (env_lst)
	{
		env_tab[i] = ft_strjoin(env_lst->key, "=");
		env_tab[i] = ft_strjoin(env_tab[i], env_lst->value);
		env_lst = env_lst->next;
		i++;
	}
	env_tab[i] = NULL;
	return (env_tab);
}

void	free_env_lst(t_env *env_lst)
{
	t_env	*tmp;

	while (env_lst->prev)
		env_lst = env_lst->prev;
	while (env_lst)
	{
		tmp = env_lst;
		env_lst = env_lst->next;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
	}
}

char	*ft_strtok(char *str, char *delim)
{
	static char	*ptr;
	char		*token;
	int			count;

	if (str)
		ptr = str;
	if (!ptr || !*ptr)
		return (NULL);
	count = 0;
	while (ptr[count])
	{
		if (ft_strchr(delim, ptr[count]))
		{
			ptr[count] = '\0';
			token = ptr;
			ptr += count + 1;
			return (token);
		}
		count++;
	}
	token = ptr;
	ptr += count;
	return (token);
}

int	edit_env_lst(t_env **env_lst, char *key, char *value)
{
	t_env	*tmp;

	tmp = *env_lst;
	if (!key || !value)
		return (1);
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
		{
			free(tmp->value);
			tmp->value = ft_strdup(value);
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

int	delete_env_lst(t_env **env_lst, char *key)
{
	t_env	*tmp;

	tmp = *env_lst;
	if (!key)
		return (1);
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
		{
			if (tmp->prev)
				tmp->prev->next = tmp->next;
			if (tmp->next)
				tmp->next->prev = tmp->prev;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}
