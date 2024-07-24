/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:07:35 by ks19              #+#    #+#             */
/*   Updated: 2024/06/17 11:22:38 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int ft_token_len(const char *s, int c)
{
	char	ch;
    int     i;

	ch = (char) c;
    i = 0;
	while (s[i])
	{
		if(s[i] == ch)
            return(i);
		i++;
	}	
    return(-1);
}

void ft_trim_spaces(char *str)
{
    int i;
    int count;
    
    i = 0;
    count = 0;
    while(str[i])
    {
        if(str[i] != 7)
        {
            str[count] = str[i];
            count++;
        }
        i++;
    }
    str[count]= '\0';
}

void ft_replace_by_space(char *str, int len, char c)
{
    int i;

    i = 0;
    while(i < len)
    {
        if(str[i] == c)
            str[i] = 7;
        i++;
    }
}
int ft_find_pair(char *str, char c)
{
    int len;

    len = ft_token_len(str + 1, c);//len peut = 0 si ""
    if(len == -1)
        return(-1);
    len += 2;
    ft_replace_by_space(str, len, c);
    return(len);
}

int ft_handle_quotes(char *str)
{
    int i;
    int len;

    i = 0;
    len = 0;
    while(str[i])//si je lui envoie des quotes, cmt savoir ou l arreter?
    {
        if((str[i] <= 12 && str[i] >= 9) || str[i] == 32) //si entre les deux pairs il y a pas d espaces, on continue
            break;
        else if(str[i])//str + i existe
        {
            if(str[i] == '\"')
                len = ft_find_pair(str + i, '\"');//tu envoies a partir du " ou '
            else if(str[i] == '\'')
                len = ft_find_pair(str + i, '\'');
            else
                i++;
            if(len == -1)
                return(-1);
        }
        i = i + len;
        len = 0;
    }
    return(i);//si "", il va return i = 2 minimum car par pair
}