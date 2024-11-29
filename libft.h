/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:22:06 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/14 17:22:06 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

// === ft_printf ===

int		ft_printf(const char *format, ...);

// === get_next_line ===

char	*get_next_line(int fd);

// === ctype ===

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_iscntrl(int c);
int		ft_isdigit(int c);
int		ft_isgraph(int c);
int		ft_islower(int c);
int		ft_isprint(int c);
int		ft_ispunct(int c);
int		ft_isspace(int c);
int		ft_isupper(int c);
int		ft_isxdigit(int c);
int		ft_isascii(int c);
int		ft_isblank(int c);

int		ft_toupper(int c);
int		ft_tolower(int c);

// === lst ===

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new_node);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new_node);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// === put_fd ===

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// === stdio ===

// === stdlib ===

int		ft_abs(int j);
int		ft_atoi(const char *str);
long	ft_atol(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_itoa(int n);
long	ft_strtol(const char *nptr, char **endptr, int base);

typedef struct s_qsort_context {
	char	*base;
	size_t	size;
	int		(*compar)(const void *, const void *);
}	t_qsort_context;

typedef struct s_qs_vars {
	size_t	pivot_index;
	void	*pivot;
	size_t	i;
	size_t	j;
}	t_qs_vars;

void	ft_qsort(void *base, size_t nmemb, size_t size, \
				int (*compar)(const void *, const void *));

// === string ===

// === str ===

size_t	ft_strlen(const char *s);
char	*ft_strcat(char *dest, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *s);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *haystack, const char *needle);

// === strn ===

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strncat(char *dest, const char *src, size_t n);
char	*ft_strnchr(const char *s, int c, size_t n);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strndup(const char *s1, size_t n);
size_t	ft_strnlen(const char *s, size_t maxlen);
char	*ft_strnset(char *s, int c, size_t n);

// === mem ===

void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memdup(void *src, size_t n);
void	*ft_memfrob(void *s, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memset(void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

// === etc　===

void	ft_bzero(void *s, size_t n);
size_t	ft_strlcat(char *dest, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

// === strings ===

int		ft_strcasecmp(const char *s1, const char *s2);
int		ft_strncasecmp(const char *s1, const char *s2, size_t n);

// === utils ===

int		ft_max(int a, int b);
int		ft_min(int a, int b);
void	ft_swap(int *a, int *b);
float	q_rsqrt(float number);

#endif
