/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arangoni <arangoni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:05:23 by arangoni          #+#    #+#             */
/*   Updated: 2022/04/26 19:37:19 by arangoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define PI 3.14159265359
# define BUFFER_SIZE 4096
# ifndef OPEN_MAX
#  define OPEN_MAX 1000
# endif

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdint.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		mini_atoi(char **s);
int		ft_printf(const char *s, ...);
int		conv_c(void *arg, int flags[7]);
int		conv_s(void *arg, int flags[7]);
int		conv_d(void *arg, int flags[7]);
int		conv_i(void *arg, int flags[7]);
int		conv_u(void *arg, int flags[7]);
int		conv_p(void *arg, int flags[7]);
int		conv_x(void *arg, int flags[7]);
int		conv_big_x(void *arg, int flags[7]);
int		conv_prct(void *arg, int flags[7]);
char	*ft_jointab(char **tab, char c);
char	*precision(char *s, int flags[7]);
char	*min_field(char *s, int field, int field_type);
char	*to_base(unsigned long long n, const char *base);
char	*ft_freejoin(char *s1, char const *s2);
char	*ft_strlower(char *str);
int		ft_abs(int n);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_max(int a, int b);
int		ft_lstsize(t_list *lst);
int		ft_atoi(const char *str);
size_t	ft_tab_size(char **tab);
int		ft_atoi_base(char *str, char *base);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
float	ft_deg_to_rad(int d);
char	*ft_itoa(int n);
char	*ft_strdup(const char *src);
char	**ft_tab_add(char **tab, char *new, int pos, int free_tab);
char	*get_next_line(int fd);
char	*ft_freejoinchar(char *s1, char const s2);
char	*ft_strchr(const char *s, int c);
void	ft_tab_print(char **tab);
char	*ft_strrchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	**ft_split(char const *s, char c);
void	ft_freetab(void *splitted);
void	ft_bzero(void *s, size_t n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	*gc_add(t_list **gc, size_t size);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_int_memset(void *b, int c, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
