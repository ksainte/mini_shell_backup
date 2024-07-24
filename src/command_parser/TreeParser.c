/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TreeParser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:10:41 by brahimb           #+#    #+#             */
/*   Updated: 2024/06/24 16:00:28 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int ft_grammar_check(t_node *list)
{
    while(list)
    {
        if(list->type == 8)//on est sur le pipe
        {
            if(!(list->next) || list->next->type == 8)
                return(0);
            if(!(list->prev))
                return(0);
        }
        if((list->type >= 4 && list->type <= 7))
        {
            if((!(list->next)) || (list->next->type != 1 && list->next->type != 2 && list->next->type != 3))
                return(0);
        }       
        list = list->next;
    }
    return(1);
}

t_cmd	*ft_new_cmd(void)//une nouvelle commande avec toutes les listes adjacantes vides
{
	t_cmd	*new;

	new = malloc(sizeof(t_cmd));
	if (!new)
		return(NULL);
    new->has_cmd = 0;
    new->name = NULL;
	new->args = NULL;
	new->next = NULL;
    new->list_in = NULL;
	new->list_out = NULL;
	return (new);
}
t_cmd *ft_lastcmd(t_cmd *list)
{
    if(!list)
        return(NULL);
    while(list->next)
        list = list->next;
    return(list);
}
t_cmd	*ft_add_cmd(t_cmd *list, t_cmd *new)
{
	if (!list)//premier node du pointeur existe
		list = new;
	else
		(ft_lastcmd(list))->next = new;
    return(list);
}

t_args	*ft_new_arg(t_node *node)//une nouvelle commande avec toutes les listes adjacantes vides
{
	t_args	*new;

	new = malloc(sizeof(t_args));
	if (!new)
		return(NULL);
    new->arg_value = node->value;
	new->next = NULL;
	return (new);
}
t_args *ft_lastarg(t_args *list)
{
    if(!list)
        return(NULL);
    while(list->next)
        list = list->next;
    return(list);
}

void ft_add_arg(t_cmd *list, t_args *new)
{
    if (!(list->args))
		list->args = new;
	else
		(ft_lastarg(list->args))->next = new;
}
void ft_fill_word_or_quote(t_node *node, t_cmd *current_cmd)
{
    if(current_cmd->has_cmd == 0)
        {
            current_cmd->name = node->value;
            current_cmd->has_cmd = 1;
        }
    else
        {
            ft_add_arg(current_cmd, ft_new_arg(node));
        }
}
t_redirect_out	*ft_new_out(t_node *node)//une nouvelle commande avec toutes les listes adjacantes vides
{
	t_redirect_out	*new;

	new = malloc(sizeof(t_redirect_out));
	if (!new)
		return(NULL);
    new->name = node->next->value;
    new->type = node->type;
    new->fd = 0;
	new->next = NULL;
	return (new);
}
t_redirect_out *ft_lastout(t_redirect_out *list)
{
    if(!list)
        return(NULL);
    while(list->next)
        list = list->next;
    return(list);
}

void ft_add_out(t_cmd *list, t_redirect_out *new)
{
    if(!(list->list_out))
		list->list_out = new;
	else
		(ft_lastout(list->list_out))->next = new;
}
t_redirect_in	*ft_new_in(t_node *node)//une nouvelle commande avec toutes les listes adjacantes vides
{
	t_redirect_in	*new;

	new = malloc(sizeof(t_redirect_in));
	if (!new)
		return(NULL);
    new->name = node->next->value;
    new->type = node->type;
    new->fd = 0;
	new->next = NULL;
	return (new);
}
t_redirect_in *ft_lastin(t_redirect_in *list)
{
    if(!list)
        return(NULL);
    while(list->next)
        list = list->next;
    return(list);
}

void ft_add_in(t_cmd *list, t_redirect_in *new)
{
    if(!(list->list_in))
		list->list_in = new;
	else
		(ft_lastin(list->list_in))->next = new;
}
void ft_fill_redirection(t_node *node, t_cmd *current_cmd)
{

    if(node->type == 5 || node->type == 7)//> out et >> append
        {
            ft_add_out(current_cmd, ft_new_out(node));
        }
    else//< in et << heredoc
        {
            ft_add_in(current_cmd, ft_new_in(node));
        }
}
t_cmd *ft_create_command(t_node **node, t_cmd *cmd_list)//tu envoies l & de cmd_list
{
    t_cmd *current_cmd;

    cmd_list = ft_add_cmd(cmd_list, ft_new_cmd());//cmd_list = new premiere it
    current_cmd = ft_lastcmd(cmd_list);//pointe sur la meme & mais deux pointeurs differents
    while(*node && (*node)->type != 8)//debut de ta commande
    {
        if((*node)->type >= 1 && (*node)->type <= 3)//premier node avant redirection, ou deuxieme apres 
        {
            ft_fill_word_or_quote(*node, current_cmd);
        }
        else if((*node)->type >= 4 && (*node)->type <= 7)
        {
            ft_fill_redirection(*node, current_cmd);
            *node = (*node)->next;//add redirections,skip redirected value
        }
        *node = (*node)->next;
    }
    return(cmd_list);
}
//va renvoyer la LL des commandes
t_cmd *ft_parse(t_node *head)
{
    t_cmd *command_list;//a LL of commands
    
    if(!(ft_grammar_check(head)))
        return(NULL);
    command_list = NULL;
    while(head)
    {
        command_list = ft_create_command(&head, command_list);//sera la mm & a partir du 2eme cmd
        if(!head)//fin de la cmd
            break;        
        head = head->next;//tu stop sur un pipe, tu passes a la commande suivante
    }
    return(command_list);
}
