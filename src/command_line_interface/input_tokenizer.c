/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_tokenizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:28:34 by ks19              #+#    #+#             */
/*   Updated: 2024/06/21 21:52:29 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int ft_sim_double_quote(char *s, char doubles)
{
    int i;

    i = 0;
    while(s[i])
    {
        if(s[i] == doubles)
            return(1);
        i++;
    }
    return(0);
}

int ft_sim_single_quote(char *s, char single)
{
    int i;

    i = 0;
    while(s[i])
    {
        if(s[i] == single)
            return(1);
        i++;
    }
    return(0);
}

type    get_type_token(char *rl)
{
	if (*rl == '>')
	{
		if (*(rl + 1) == '>')
			return (REDIRECT_APPEND);
		return (REDIRECT_OUT);
	}
	else if (*rl == '<')
	{
		if (*(rl + 1) == '<')
			return (REDIRECT_HEREDOC);
		return (REDIRECT_IN);
	}
	else if (*rl == '|')
		return (PIPE);
    else if (*rl == '\'')
        {
            if(!ft_sim_single_quote(rl + 1, 39))
                return(INVALID);
            return(SINGLE_QUOTE);
        }
    else if (*rl == '\"')
        {
            if(!ft_sim_double_quote(rl + 1, 34))
                return(INVALID);
            return(DOUBLE_QUOTE);   
        }
	else
        return (WORD);
}
t_node	*ft_lastnode(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_node	*ft_prev_node(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next != NULL)
		lst = lst->next;
	return (lst);
}
 
void	ft_add_back(t_node **list, t_node *new)
{
	if (!list)
		return ;
	if (!*list)//premier node
    {
		*list = new;
        new->prev = NULL;
    }
	else//deux node
    {
		(ft_lastnode(*list))->next = new;
        new->prev = ft_prev_node(*list);
    }
}

t_node	*ft_stack_new(char *str, int return_value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		exit(0);
    new->value = str;//on stock l'& du premier char de la string dans ce node
	new->type = return_value;
	new->next = NULL;
	return (new);
}
int ft_word_len(const char *s)
{
    int     i;

    i = 0;
	while (s[i])
	{
        if((s[i] <= 12 && s[i] >= 9) || s[i] == 32 || s[i] == '<' || s[i] == '>' || s[i] == '|')
            return(i); 
        i++;
	}
	return(i);
}

char *ft_fill_token(char *rl, int value, int *len)
{
    char *str;

    if(value == SINGLE_QUOTE || value == DOUBLE_QUOTE)//il commencer par single
    {
        *len = ft_handle_quotes(rl);//si "",va return 2
        if(*len == -1)
            return(NULL);
        str = ft_substr(rl, 0, *len);
        if (!str) // Check if memory allocation failed
            return (NULL);
        ft_trim_spaces(str);
    }
    else if(value == REDIRECT_IN || value == REDIRECT_OUT)
    {
        str = ft_substr(rl, 0, 1);
        if (!str) // Check if memory allocation failed
            return (NULL);
        *len = 1;
    }
    else if(value == REDIRECT_APPEND || value == REDIRECT_HEREDOC)
    {
        str = ft_substr(rl, 0, 2);
        if (!str) // Check if memory allocation failed
            return (NULL);
        *len = 2;
    }
    else if(value == PIPE)
    {
        str = ft_substr(rl, 0, 1);
        if (!str) // Check if memory allocation failed
            return (NULL);
        *len = 1;
    }
    else
    {
        *len = ft_handle_quotes(rl);//si "",va return 2
        if(*len == -1)
            return(NULL);
        str = ft_substr(rl, 0, *len);
        if (!str) // Check if memory allocation failed
            return (NULL);
        ft_trim_spaces(str);
    }
    return(str);
}

t_node *ft_tokenize(char *rl)
{
    t_node *node;
    int i;
    int return_value;
    char *tmp;
    int len;

    i = 0;
    len = 0;
    node = NULL;
    while(rl[i])
    {
        if((rl[i] <= 12 && rl[i] >= 9) || rl[i] == 32) 
            i++;
        else if(rl[i])
        {
            return_value = get_type_token(rl + i);
            if(return_value == INVALID)
            {
                ft_free(&node);
                ft_error();
                return(NULL);
            }
            tmp = ft_fill_token(rl + i, return_value, &len);//pointer tmp points each time at a new address, all addresses must remain in heap
            if(tmp == NULL)
            {
                ft_free(&node);
                ft_error();
                return(NULL);
            }
            ft_add_back(&node, ft_stack_new(tmp, return_value));//pas certain que c est oblige d envoyer l & du node, cm tu ajoutes un next a un node
        }
        i = i + len;
        len = 0;
    }
    return(node);
}

//'''''''

//"hey""you''''''"
//hey'"you'''''''"d"''

//hey'"you''''''''d'

//hey'"you''''''"d"'


//ab"cs"'ef"""gh
//cat M""'akefile'""''

//cat 'M''akefile'""''       < "M"'akefile2'""''
//hey"you     ''"'myfriend'