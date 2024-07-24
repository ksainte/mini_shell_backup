/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:02:06 by brahimb           #+#    #+#             */
/*   Updated: 2024/07/23 14:38:47 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <string.h>
# include <limits.h>
# include <signal.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/stat.h>

//# include <linux/limits.h>
# include <sys/wait.h>

# define EXIT_NUMERIC_ERROR 255

extern void rl_replace_line(const char *text, int clear_undo);

//signal_handler/SignalHandler.c
//void	signal_handler(int signum);
void	init_signal_handler(void);
void	initiliaze_signal(void);

//EnvironmentVariablemManager.c

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*prev;
	struct s_env	*next;
}	t_env;

typedef struct s_node
{
	int type;
	char *value;
	struct s_node *next;//init et declaration sur une ligne
	struct s_node *prev;
}	t_node;


typedef struct s_args
{
	char *arg_value;
	struct s_args *next;//init et declaration sur une ligne
}	t_args;

typedef struct s_redirect_in
{
	char *name;
	int type;
	int fd;
	struct s_redirect_in *next;
}	t_redirect_in;

typedef struct s_redirect_out
{
	char *name;
	int type;
	int fd;
	struct s_redirect_out *next;
}	t_redirect_out;

typedef struct s_cmd
{
	int has_cmd;
	char *name;
	struct s_args *args;
	struct s_cmd *next;
	struct s_redirect_in *list_in;
	struct s_redirect_out *list_out;
}	t_cmd;

void			init_signal_handler(void);
void			initiliaze_signal(void);
void			signal_to_default_behaviour(void);

int				initiliaze_envp(char **envp);
void			free_env_lst(t_env *env_lst);
char			*ft_strtok(char *str, char *delim);
int				add_env_lst(t_env **env_lst, char *key, char *value);
void			print_env_lst(int fd, int mode);
char			*search_value_env_lst(char *key);
int				edit_env_lst(t_env **env_lst, char *key, char *value);
int				delete_env_lst(t_env **env_lst, char *key);
void			expander(t_node **node_list);
char			**env_lst_to_tab(t_env *env_lst);

//CommandLineInterface.c
int 			cli();
void 			pwd(void);
int 			cd(char *cmd);
void			exit_err(int errnum);
void			ft_error(void);

//input_tokenizer.c
int ft_find_pair(char *str, char c);
void ft_replace_by_space(char *str, int len, char c);
void ft_trim_spaces(char *str);
int ft_token_len(const char *s, int c);
int ft_handle_quotes(char *str);

//command_parser
typedef enum s_token_type
{
	WORD = 1,
	SINGLE_QUOTE = 2,
	DOUBLE_QUOTE = 3,
	REDIRECT_IN = 4,
	REDIRECT_OUT = 5,
	REDIRECT_HEREDOC = 6,
	REDIRECT_APPEND = 7,
	PIPE = 8,
	INVALID = 9
}	type;

t_node *ft_tokenize(char *rl);
void	ft_free(t_node **lst);
t_cmd 	*ft_parse(t_node *head);

//builtins
void	builtin_cd(int fd, char *s);
void	builtin_echo(char **strs, int fd);
void	builtin_pwd(int fd);
void	builtin_export(int fd, char **strs);
void	builtin_unset(char **strs);
void	builtin_env(int fd);
void	builtin_exit(int fd, char **strs);

//Main.c
typedef struct s_shell
{
	struct s_env		*env_lst;
	int					exit_status;
	char				*rl;
	char				*pwd;
	int					sig_c;
}	t_shell;

#endif