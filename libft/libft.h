/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepherd <sepherd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:03:16 by arecce            #+#    #+#             */
/*   Updated: 2023/05/23 16:19:21 by sepherd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

long long			ft_atoi(const char *str);
void				ft_bzero(void *s, int n);
void				*ft_calloc(size_t count, size_t size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memchr(const void *s, int c, int n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, unsigned int n);
void				*ft_memmove(void *dst, const void *src, int len);
void				*ft_memset(void *b, int c, int len);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(char *src);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle, \
					size_t len);
char				*ft_strrchr(const char *s, int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char *s, int fd);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), \
					void (*del)(void *));
int					ft_putchar(int c);
int					ft_conversions(va_list args, const char c);
int					ft_putstr(char *str);
int					ft_printf(const char *str, ...);
int					ft_numlen(long long nb);
void				ft_convert(int nb, const char *digit);
int					ft_putnbr(int nb);
void				ft_unconvert(unsigned int nb);
int					ft_putunbr(unsigned int nb);
void				ft_hexconvert(unsigned int nb, const char c);
int					ft_hex_len(long long nb);
int					ft_puthex(unsigned int nb, const char c);
void				ft_ptrconvert(uintptr_t ptr, char *digit);
int					ft_ptr_len(uintptr_t ptr);
int					ft_putptr(unsigned long long ptr);
size_t				gnl_strlen(char *str);
char				*gnl_strchr(char *s, int c);
char				*gnl_strjoin(char *s1, char *s2);
char				*ft_reading(int fd, char *save);
char				*ft_get_line(char *save);
char				*ft_backup(char *save);
char				*get_next_line(int fd);

#endif