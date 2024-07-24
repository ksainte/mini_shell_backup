/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandLineInterface.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:06:48 by ksainte           #+#    #+#             */
/*   Updated: 2024/07/24 13:16:27 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern t_shell shell;

void	ft_free_table(char **buffer)
{
	int	i;

	i = -1;
	while (buffer[++i] != NULL)
		free(buffer[i]);
	// free(buffer);
}

void	ft_free(t_node **lst)
{
	t_node	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		(*lst)->type = 0;
        free((*lst)->value);
		free(*lst);
		*lst = tmp;
	}
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
}
void ft_print_commands(t_node *node_list, t_cmd *cmd)
{
    t_args *cmd_args;
    t_redirect_in *cmd_in;
    t_redirect_out *cmd_out;

    cmd_args = cmd->args;
    cmd_in = cmd->list_in;
    cmd_out = cmd->list_out;
    printf("original node list:\n");
    while(node_list)
    {
        printf("node has value:%s and type:%d\n", node_list->value, node_list->type);
        node_list = node_list->next;
    }
    if(cmd)
        printf("First command is:\n");
    while(cmd)
    {
        printf("cmd name is:%s\n", cmd->name);
        while(cmd_args)
        {
            printf("cmd arg is:%s\n", cmd_args->arg_value);
            cmd_args = cmd_args->next;
        }
        while(cmd_in)
        {
            printf("cmd redirect-in name is:%s\n", cmd_in->name);
            printf("cmd redirect-in type is:%d\n", cmd_in->type);
            cmd_in = cmd_in->next;
        }
        while(cmd_out)
        {
            printf("cmd redirect-out name is:%s\n", cmd_out->name);
            printf("cmd redirect-out type is:%d\n", cmd_out->type);
            cmd_out = cmd_out->next;
        }
        cmd = cmd->next;
        if(cmd)
            printf("New command:\n");
    }
}

char *ft_get_cmd(char *str)
{
    char **tab;
    int i;

    i = 0;
    // printf("%s\n", str);
    tab = ft_split(str, 47);
    while(tab[i])
        i++;
    // printf("%s", tab[i - 1]);
    return(tab[i - 1]);
}

void	ft_print_table(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		ft_printf("%s\n", tab[i]);
		i++;
	}
}
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char const *s, int fd)
{
	int		i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
void ft_newline_to_null(char *str)
{
	int	i;

	i = 0;
    // dprintf(2, "seg2\n");
	while (str && str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
    // dprintf(2, "seg3\n");
}
void ft_null_to_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i + 1] != '\0')
		return ;
	str[i] = '\n';
}

int ft_cmp_gnl_word(char *gnl, char *word)
{
	int return_value;

	return_value = -1;
    // dprintf(2, "ok7\n");
	ft_newline_to_null(gnl);
    // dprintf(2, "seg\n");
	return_value = ft_strncmp(gnl, word, ft_strlen(word) + 1);
    // dprintf(2, "ok8\n");
	ft_null_to_newline(gnl);
	return (return_value);
}

int ft_heredoc(t_redirect_in *cmd_in)
{

    int pipes[2];
    char *str;
    // int status;
    // int len;

    signal_to_default_behaviour();
    pipe(pipes);
    // close(0);
    str = get_next_line(0);
    // dprintf(2, "str is %s\n", str);
    // len = ft_strlen(cmd_in->name);
    // dprintf(2, "first is %d", len);
    // dprintf(2, "ok4\n");
    // dprintf(2, "this is the name %s\n", cmd_in->name);
    while(ft_cmp_gnl_word(str, cmd_in->name)!= 0)
    {
        // dprintf(2, "ok6\n");
        ft_putstr_fd(str, pipes[1]);
        str = get_next_line(0);
		//ft_newline_to_null(str);
    }
    // dprintf(2, "ok5\n");
	//ft_null_to_newline(str);
    close(pipes[1]);
	initiliaze_signal();
    // printf("works\n");
    // dprintf(2, "first");
        // wait(&status);
    // dprintf(2, "%d\n",pipes[0]);
    return(pipes[0]);
}
//pour une commande telle que cat Makefile > bb | wc -l < bb c est normal que ca marche seulement
//une fois sur deux, parfois l info que bb est fill n arrive pas assez vite a wc -l
//bash beug aussi parfois avec un "bb is not a file nor a directory"
void ft_execute_path(char *executable, char **tab, t_cmd *cmd, int in_pipe[], int out_pipe[], int i, int p)
{
    t_redirect_in *cmd_in;
    t_redirect_out *cmd_out;

    cmd_in = cmd->list_in;
    cmd_out = cmd->list_out;
    if(*tab[0] == '\0')
        executable = "/bin/true";
    char **args = tab;
	char **newenviron = NULL;
    int in;
    int out;
	// int	status;

    
    // status = 0;
    // if(shell.exit_status != 0)
    //     exit(-1);
  //c est important que les pipes soient avant les redirections car les redirections ont la
  //priorite en terme de in et de out, par exemple ls -l /etc | tail -n +10 | wc -l < Makefile
  //doit execve wc -l sur le in de Makefile et pas sur celui de read pipe.
	// dprintf(2, "we are in a child process\n");
    if(shell.sig_c == 1)
        exit(-1);
    if(in_pipe[0] != -1)
    {
        if(i == 0)
        {
            close(out_pipe[0]);//close fd:5
            // dup2(out_pipe[1], 1);//ecris ds fd:6 a la place que ds stdout
            // close(out_pipe[1]);//close fd:6
            // dprintf(2, "first");
        }
        else if(i == p - 1)
        {
            close(in_pipe[1]);//close fd:4
            if(!cmd_in)
                dup2(in_pipe[0], 0);//lis dans fd:5, makes them equivalent
            close(in_pipe[0]);//close fd:3
            // dprintf(2, "second");
        }
        else
        {
            close(out_pipe[0]);//close fd:3
            // dup2(out_pipe[1], 1);//ecris dans fd:4//mais pas si builtin
            // close(out_pipe[1]);//close fd:4
            
            close(in_pipe[1]);//close fd:6
            if(!cmd_in)
                dup2(in_pipe[0], 0);//lis ds fd:5
            close(in_pipe[0]);//close fd:5
            // dprintf(2, "third");
        }
    }
    if(cmd_in)
    {
        while(cmd_in->next)
        {
            if(cmd_in->type == 4)//in
            {
                in = open(cmd_in->name, O_RDONLY);
                if(in == -1)
                {
                    ft_error();
                    exit(-1);
                }
            }
            else if(cmd_in->type == 6)//heredoc
            {
                in = ft_heredoc(cmd_in);
                if(in == -1)
                {
                    ft_error();
                    exit(-1);
                }
            }
            cmd_in = cmd_in->next;
            close(in);
        }
        if(cmd_in->type == 4)//in
        {
            in = open(cmd_in->name, O_RDONLY);
            if(in == -1)
            {
                ft_error();
                exit(-1);
            }
        // dprintf(2, "third");
        }
        else if(cmd_in->type == 6)//heredoc
        {
            // dprintf(2, "ok3\n");
            // dup(0);//lis ds fd:5
            in = ft_heredoc(cmd_in);
            if(in == -1)
            {
                ft_error();
                exit(-1);
            }
            if(!(ft_strncmp(tab[0], "cd", 3)))//pas oublier de gerer cd .. << e
            {
                builtin_cd(1, tab[1]);
                exit(-1);
            }
        }
        dup2(in, 0);
        close(in);
    }
    if(cmd_out)
    {
        while(cmd_out->next)
        {
            if(cmd_out->type == 7)//redirect append
                out = open(cmd_out->name, O_CREAT, 0644);
            else if(cmd_out->type == 5)
                out = open(cmd_out->name, O_TRUNC | O_CREAT, 0644);
            cmd_out = cmd_out->next;
            close(out);
        }
        if(cmd_out->type == 5)//redirect out
            out = open(cmd_out->name, O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
        else//append
            out = open(cmd_out->name, O_WRONLY | O_APPEND |O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
    }
    //signal_to_default_behaviour();
    if(cmd_out && !(ft_strncmp(tab[0], "echo", 5)))
    {   
        // dprintf(2, "ok\n");
        builtin_echo(tab, out);
        close(out);
        exit(-1);

    }
    else if(!(ft_strncmp(tab[0], "echo", 5)) && (i == p - 1))
    {
        // dprintf(2, "ok2\n");
        if(shell.sig_c == 0)
        {
            builtin_echo(tab, 1);
            exit(-1);
        }
        else
            exit(-1);

    }
    else if(!(ft_strncmp(tab[0], "echo", 5)))
    {
        // dprintf(2, "ok3\n");
        // close(out_pipe[0]);//close fd:3
        builtin_echo(tab, out_pipe[1]);
        close(out_pipe[1]);//close fd:6
        exit(-1);

    }
    else if(cmd_out && !(ft_strncmp(tab[0], "export", 7)))
    {
        //dprintf(2, "ok\n");
        builtin_export(out, tab + 1);
        close(out);
        exit(-1);

    }
    else if(!(ft_strncmp(tab[0], "export", 7)) && (i == p - 1))
    {
        //dprintf(2, "ok2\n");
        builtin_export(1, tab + 1);
        close(1);
        exit(-1);

    }
    else if(!(ft_strncmp(tab[0], "export", 7)))
    {
        // dprintf(2, "ok3\n");
        builtin_export(out_pipe[1], tab + 1);
        close(out_pipe[1]);//close fd:6
        exit(-1);
    }
    else if(cmd_out && !(ft_strncmp(tab[0], "env", 4)))
    {
        if(cmd->args)
        {
            ft_error();
            exit(-1);

        }
        else
        {
        //dprintf(2, "ok\n");
            builtin_env(out);
            close(out);
            exit(-1);
        }

    }
    else if(!(ft_strncmp(tab[0], "env", 4)) && (i == p - 1))
    {
        //dprintf(2, "ok2\n");
        if(cmd->args)
        {
            ft_error();
            exit(-1);

        }
        else
        {
            builtin_env(1);
            close(1);
            exit(-1);
        }
    }
    else if(!(ft_strncmp(tab[0], "env", 4)))
    {
        if(cmd->args)
        {
            ft_error();
            exit(-1);

        }
        else
        {
            // dprintf(2, "ok3\n");
            builtin_env(out_pipe[1]);
            close(out_pipe[1]);//close fd:6
            exit(-1);
        }
    }
    else
    {
        if(in_pipe[0] != -1 && (i == 0))
        {
            dup2(out_pipe[1], 1);//ecris ds fd:6 a la place que ds stdout
            close(out_pipe[1]);//close fd:6
        }
        if(in_pipe[0] != -1 && (i != 0) && (i != p - 1))
        {
            dup2(out_pipe[1], 1);//ecris dans fd:4//mais pas si builtin
            close(out_pipe[1]);//close fd:4
        }
        if(cmd_out)//c est pas l un ou l autre, je overwrite!,REDIRECTION a toujours la priorite
        {
            dup2(out, 1);// cat Makefile > test, a la place de stdout ds le prompt, fais le dans le fd de out
            close(out);
        }
		newenviron = env_lst_to_tab(shell.env_lst);
	    signal_to_default_behaviour();
        shell.exit_status = execve(executable, args, newenviron);//if in file will understand to read from it because dup2(in, 0), by default dup2(out, 1)
	    initiliaze_signal();//important de garder
        exit(-1);
    }
	/* execve() only returns on error */
	perror("execve");
    exit(shell.exit_status);
}

void ft_print_builtin(char **tab)
{
    // printf("ok\n");
    if(!(ft_strncmp(tab[0], "pwd", 4)))
        builtin_pwd(1);
    exit(-1);
}

void ft_execute(char **tab, t_cmd *cmd, int in_pipe[], int out_pipe[], int j, int p, int h)
{
    int i;
    char *temp;
    char *temp1;
    char *str;
    char *executable;
    int w = 0;
    char *temp_search;

    if(!(ft_strncmp(tab[0], "cd", 3)) && (h == 0))//pas oublier de gerer ls | cd .. << e p = 2, h = 1
    {
        builtin_cd(1, tab[1]);
        exit(-1);
    }
    else if(!(ft_strncmp(tab[0], "exit", 5)))
    {
        clear_history();
        builtin_exit(1, tab + 1);
    }
    executable = NULL;
        temp_search = ft_strdup(search_value_env_lst("PATH"));
        // dprintf(2, "\ns is %s", temp_search);
        str = ft_strtok(temp_search, ":");//cat, dont need to free since its a static
        free(temp_search);
        while(str)
        {
            // dprintf(2, "\ns is %s", str);
            temp = ft_strjoin(str, "/");
            temp1 = ft_strjoin(temp, tab[0]);
            i = access(temp1, X_OK);
            if(i == 0)
            {
                executable = temp1;//bin/cat and tab[0] is already first command
                free(temp);
                w = 1;
                // dprintf(2, "\nexec is %s\n", executable);
                break;
            }
            str = ft_strtok(NULL, ":");
            free(temp);
            free(temp1);
        }
        if(w == 0)
        {
            // dprintf(2, " 2 is\n");
            i = access(tab[0], X_OK);
            if(i == 0)//bin/cat
            {
                executable = tab[0];
                tab[0] = ft_get_cmd(tab[0]);
            }
        }
        else if (i == -1 && *tab[0] != '\0' && w == 0)
        {
               ft_error();
               exit(-1);
        }
    if(!(ft_strncmp(tab[0], "pwd", 4)))
        ft_print_builtin(tab);
    else
        ft_execute_path(executable, tab, cmd, in_pipe, out_pipe, j, p);
}
char **ft_calloc_cmd_len(t_cmd *cmd)
{
    int i;
    t_args *cmd_args;
    char **tab;
    
    i = 0;
    cmd_args = cmd->args;
    if(cmd->name)
        i++;
    while(cmd_args)
    {
        i++;
        cmd_args = cmd_args->next;
    }
    tab = calloc(sizeof(char*), i + 1);
    return(tab);
}

char **ft_fill_tab(char **tab, t_cmd *cmd)
{
    int i;
    t_args * cmd_args;

    cmd_args = cmd->args;
    if(cmd->name == NULL)
        tab[0] = "\0";
    else
        tab[0] = cmd->name;
    i = 1;
    while(cmd_args)
    {
        tab[i] = cmd_args->arg_value;//eq. de dire *(tab + i) = //;
        cmd_args = cmd_args->next;
        i++;
    }
    tab[i] = NULL;
    return(tab);
}
int ft_cmd_size(t_cmd *cmd)
{
    int i;

    i = 0;
    while(cmd)
    {
        i++;
        cmd = cmd->next;
    }
    return(i);
}
void ft_build_to_parent(t_cmd *cmd, char **tab, int b)
{
    t_redirect_in *cmd_in;
    t_redirect_out *cmd_out;

    cmd_in = cmd->list_in;
    cmd_out = cmd->list_out;
    int in;
    int out;
    int pid;
  
    if(cmd_in)
    {
        while(cmd_in->next)
        {
            if(cmd_in->type == 4)//in
            {
                in = open(cmd_in->name, O_RDONLY);
                if(in == -1)
                    ft_error();
            }
            else if(cmd_in->type == 6)//heredoc
            {
                in = ft_heredoc(cmd_in);
                if(in == -1)
                    ft_error();
            }
            cmd_in = cmd_in->next;
            close(in);
        }
        if(cmd_in->type == 4)//in
        {
            in = open(cmd_in->name, O_RDONLY);
            if(in == -1)
                ft_error();
        }
        else if(cmd_in->type == 6)//heredoc
        {
                pid = fork();
                if(pid == 0)
                {
                    in = ft_heredoc(cmd_in);
                    if(in == -1)
                    {
                        ft_error();
                    }
                }
        }
        close(in);
        if(b == 1)
            builtin_echo(tab, 1);//faut gerer le error, error si file existe pas, dans ce cas n echo pas
        else if(b == 2)
            builtin_export(1, tab);//gerer erreur
        else if(b == 3)
             builtin_env(1);
        else if(shell.sig_c == 0 && b == 4)//dans le genre
            builtin_cd(1, tab[1]);
        //echo z < zzz
    }
    if(cmd_out)
    {
        while(cmd_out->next)
        {
            if(cmd_out->type == 7)//redirect append
                out = open(cmd_out->name, O_CREAT, 0644);
            else if(cmd_out->type == 5)
                out = open(cmd_out->name, O_TRUNC | O_CREAT, 0644);
            cmd_out = cmd_out->next;
            close(out);
        }
        if(cmd_out->type == 5)//redirect out
            out = open(cmd_out->name, O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
        else//append
            out = open(cmd_out->name, O_WRONLY | O_APPEND |O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
        // dup2(out, 1);// cat Makefile > test, a la place de stdout ds le prompt, fais le dans le fd de out
        if(b == 1)
            builtin_echo(tab, out);
        else if(b == 2)
            builtin_export(out, tab);
        else if(b == 3)
             builtin_env(out);
        else if(b == 4)
            builtin_cd(1, tab[1]);
        close(out);
    }
}

int ft_heredoc_in_current_command(t_cmd *cmd)
{
    t_redirect_in *cmd_in;

    cmd_in = cmd->list_in;
    if(cmd_in)
    {
        while(cmd_in)
        {
            if(cmd_in->type == 6)//heredoc
                return(1);
            cmd_in = cmd_in->next;
        }
    }
    return(0);
}
//read 1 and write is 2
// if p == 1 with builtins with redirection
//if p > 1, than you handle everything in child
void ft_execve(t_cmd *cmd)
{
    char **tab;
    int pid;
    int p;
    int i;
    int status;
    int h;
    
    i = 0;
    h = 0;
    p = ft_cmd_size(cmd);
    int in_pipe[2];
    int out_pipe[2];
    in_pipe[0] = -1;
    if (cmd->next)
    {
        pipe(in_pipe); // 1ere 3 4
    }
    while(cmd)
    {
        if (in_pipe[0] != -1)
        {
            pipe(out_pipe);// 1ere it:5 6, 2eme it:devient 3 4(ferme avant)
            //3eme:redevient 5 et 6
        }
        tab = ft_calloc_cmd_len(cmd);
        tab = ft_fill_tab(tab, cmd);
        h = ft_heredoc_in_current_command(cmd);
        if(!(ft_strncmp(tab[0], "cd", 3)) && (p == 1))
        {
            if(cmd->list_in || cmd->list_out)
                ft_build_to_parent(cmd, tab, 4);
            else
                builtin_cd(1, tab[1]);
        }
        else if(!(ft_strncmp(tab[0], "unset", 6)))
             builtin_unset(tab);
        else if(!(ft_strncmp(tab[0], "env", 4)) && (p == 1) && (h == 0))
        {
            // printf("test");
            if(cmd->args)
                ft_error();
            else if(cmd->list_in || cmd->list_out)
                ft_build_to_parent(cmd, tab, 3);
            else
                builtin_env(1);
        }
        else if(!(ft_strncmp(tab[0], "echo", 5)) && (p == 1) && (h == 0))
        {
            // printf("test");
            if(cmd->list_in || cmd->list_out)
                ft_build_to_parent(cmd, tab, 1);
            else
                builtin_echo(tab, 1);
        }
        else if(!(ft_strncmp(tab[0], "export", 7)) && (p == 1) && (h == 0))
        {
            // printf("test");
            if(cmd->list_in || cmd->list_out)
                ft_build_to_parent(cmd, tab + 1, 2);
            else
                builtin_export(1, tab + 1);
        }
        else if(!(ft_strncmp(tab[0], "exit", 5)) && (p == 1) && (h == 0))
        {
            clear_history();
            builtin_exit(1, tab + 1);
        }
        else
        {
            pid = fork();
            if(pid == 0)
                ft_execute(tab, cmd, in_pipe, out_pipe, i, p, h);
            // wait(NULL);
        }
        cmd = cmd->next;
        i++;
        // ft_free_table(tab);
        if(in_pipe[0] != -1)
        {
            close(in_pipe[0]); // 1ere:ferme 3, 2eme: ferme 5, 3eme: ferme 3
            close(in_pipe[1]); // 1ere:ferme 4, 2eme: ferme 6, 3eme: ferme 4
        }
        in_pipe[0] = out_pipe[0]; // 1ere :5, 2eme: 3, 3eme: 5
        in_pipe[1] = out_pipe[1]; // 1eme:6, 2eme: 4, 3eme : 6
        wait(&status);
    }
    close(out_pipe[0]);
    close(out_pipe[1]);
    // wait(&status);
    for (i = 0; i < p; i++)
        wait(&status);
    // wait(NULL);
    // ft_free_table(tab);
}

int check_only_space(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while(str[i])
	{
		if(str[i] == ' ' || str[i] == '\t'	|| str[i] == '\n' 
				|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r') 
			count++;
		i++;
	}
	if(count == i)
		return(1);
	return(0);
}

int cli()
{
	char *rl;
    t_node *node_list = NULL;
    t_cmd *cmd_list;
    
    while(1)
    {
        rl = readline(">$ ");
        shell.sig_c = 0;
        // shell.exit_status = 0;
		if (rl == NULL)
		{
			printf("exit\n");
			break ;
		}
		else if(*rl == '\0' || check_only_space(rl) == 1)
			continue ;
        if(*rl != '\0' || check_only_space(rl) == 1)//rl est l adresse du premier char,*rl est le contenu
            add_history(rl);
        // printf("Tokenize %s:\n", rl);
        node_list = ft_tokenize(rl);
		expander(&node_list);
        if(node_list)
            cmd_list = ft_parse(node_list);
        if(!node_list || !cmd_list)
            return(0);
        // ft_print_commands(node_list, cmd_list);
        ft_execve(cmd_list);
        free(rl);
        ft_free(&node_list);
		rl_on_new_line();
		rl_replace_line("", 0);
    }
    if (node_list != NULL)
		ft_free(&node_list);
    return (0);
}
// printf("cmd_out->name == %s, cmd_next == %s\n",cmd_out->name, cmd_out->next->name);
