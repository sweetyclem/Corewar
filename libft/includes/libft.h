/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:54:22 by clanier           #+#    #+#             */
/*   Updated: 2018/03/29 11:40:08 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <errno.h>
# include "get_next_line.h"
# include "ft_printf.h"
# include "ft_prtl.h"

# define FI_ __FILE__
# define FU_ __FUNCTION__
# define LI_ __LINE__
# define ER 		errno
# define FFL 		FI_, FU_, LI_

# define FAIL 0
# define SUCCESS 1

# define E_MLC		"Could not allocate memory for : "
# define E_OPF		"Could not open file : "
# define E_RDF		"Could not read file or file is empty : "
# define MDI		"more details in : "

# define BUFF_SIZE_2_16 65536

int					ft_strchr_i(char *s, char c);
char				*ft_get_line(char *s, int *i);
char				*ft_cut_first_line(char *str);
char				*ft_point_to_next_line(char *str);
int					ft_strlen_np(const char *s);
char				*ft_open_file(char *s, int *len);
int					ft_create_file(char *p);
char				*ft_strtrim_both(char *s);
int					ft_str_is_digits(char *str);
char				*ft_skip_whitespace(char *str);
char				ft_rm(char *path);
char				*ft_strjoin_np(char *s1, char *s2);
char				*ft_strndup(const char *s1, int i);
void				ft_putbuf_fd_np(int fd, char *src, char *dst, int *i);
void				ft_putbuf_fd_loop_char_np(int fd_n_x, char c,
		char *dst, int *i);
int					ft_error_d(int fd, const char *s, ...);
char				ft_error_c(int fd, const char *s, ...);
void				*ft_error_n(int fd, const char *s, ...);
void				ft_error_v(int fd, const char *s, ...);
char				*ft_scitoa(double nb, char pre);
char				*ft_lutoa(size_t n);
char				*ft_ldtoa(long int n);
size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *s);
char				*ft_strcdup(const char *s, char c);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strnstr(char *haystack, char *needle, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(char *haystack, char *needle);
char				*ft_itoa(int nb);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strnew(size_t size);
char				**ft_strsplit(char const *s, char c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				*ft_freejoin(char *dst, char *src);
void				*ft_bzero(void *s, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memcpy_rev(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_tab(int lines, char **tab);
void				ft_putnbr_tab(int rows, int lines, int **tab);
void				*ft_realloc(void *ptr, size_t size);
void				ft_uputnbr(unsigned int n);
int					ft_atoi(const char *str);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strcmp(char *s1, char *s2);
int					ft_strncmp(char *s1, char *s2, unsigned int n);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_nbrtotal_tab(int rows, int lines, int **tab);
int					**ft_nbrset_tab(int rows, int lines, int **tab, int n);
int					ft_abs(int n);
int					ft_putwchar(wchar_t chr);
int					ft_nbrlen(int n);
float				ft_sqrt(int i);
double				ft_pow(double n, int exp);

#endif
