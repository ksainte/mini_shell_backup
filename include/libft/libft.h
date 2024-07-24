/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brahimb <brahimb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:09:15 by brahimb           #+#    #+#             */
/*   Updated: 2024/07/22 10:30:19 by brahimb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h> //va_start, va_arg, va_copy, va_end
# include "get_next_line.h"


int				ft_atoi(const char *str);
void			ft_bzero(void *ptr, size_t n);
void			*ft_calloc(size_t nelem, size_t elemsize);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *to, const void *from, size_t n);
void			*ft_memmove(void *to, const void *from, size_t n);
void			*ft_memset(void *ptr, int x, size_t n);
char			*ft_strdup(const char *s1);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
size_t			ft_strlcpy(char *dst, char *src, size_t maxlen);
size_t			ft_strlen(const char *str);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *s, const char *find, size_t len);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_tolower(int x);
int				ft_toupper(int x);

char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));

int				ft_printf(const char *str, ...);
int				ft_printf_pointer(unsigned long long ptr);
int				ft_printf_nbr(int n, int fd);
void			ft_printf_putchar(char c, int fd);
int				ft_printf_unbr(unsigned int n, int fd);
int				ft_printf_nbrhex(int nbr, char c);

int				ft_fprintf(int fd, const char *str, ...);
int				ft_fprintf_pointer(int fd, unsigned long long ptr);
int				ft_fprintf_nbr(int n, int fd);
void			ft_fprintf_putchar(char c, int fd);
int				ft_fprintf_unbr(unsigned int n, int fd);
int				ft_fprintf_nbrhex(int fd, int nbr, char c);

#endif