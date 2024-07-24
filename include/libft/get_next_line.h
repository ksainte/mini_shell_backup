/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:47:02 by ksainte           #+#    #+#             */
/*   Updated: 2024/07/11 09:45:52 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*get_str(char *test, char *buff, char *str);
char	*ft_read_str(int fd, char *buff, char *test);
// int		ft_strlen1(char *str);
int		ft_n_present(char *left_str, char c);
// char	*ft_strjoin1(char *left_str, char *buff);
// void	*ft_memcpy(void *dst, const void *src, size_t n);
// void	*ft_bzero(void *s, size_t n);

#endif