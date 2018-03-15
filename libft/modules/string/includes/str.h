/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 15:00:10 by apopinea          #+#    #+#             */
/*   Updated: 2018/03/05 14:23:42 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

# include <string.h>
# include <stdarg.h>
# include <inttypes.h>

# define BUFF_SIZE 1000

char				*ft_get_line(char *s, int *i);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strrchr(const char *s, int c);
void				ft_strdel(char **as);
char				*ft_strnew(size_t size);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				ft_str_end_cmp_np(char *s1, char *s2);
char				*ft_strjoin_np(char *s1, char *s2);

/*
**	ft_itoa	->	libft/string/ft_itoa.c
**		convertie la valeur contenue dans un int
**		en chiffre dans une string
*/
char				*ft_itoa(int n);

/*
**	ft_itoa_base	->	libft/string/ft_itoa_base.c
**		convertie une valeur en int, en une chaine dans
**		dans une base b;
*/
char				*ft_itoa_base(int value, int base);
void				ft_tabscpy(char **d, char **s, int i, int j);
char				*ft_strscut(char **src, const char *cut, int o);
void				ft_low_case(char *str);
void				ft_up_case(char *str);

void				ft_tabscpy(char **d, char **s, int c, int l);
void				ft_strswap(char **s1, char **s2);
char				*ft_scitoa(double nb, char pre);
char				*ft_strnjoin(char *s1, char *s2, int n);
char				*ft_strjoin_4(char *s1, char *s2, char *s3, char *s4);

/*
**	ft_print_next_line-> libft/main/ft_print_next_line.c
**		print la ligne courante dans un fd et avance lindice de la str
**		peut colorer le texte
*/
void				ft_print_next_line(char *s, int *i, int fd);

/*
**	ft_print_next_line_color -> libft/main/ft_print_next_line.c
**		print la ligne courante dans un fd et avance lindice de la str
**		peut colorer le texte
*/
void				ft_print_next_line_color(char *s, int *i, char *color,
						int fd);

/*
**	ft_strcmp_np	->	string/ft_strcmp.c
**		/!\ No PROTECTION /!\
**		compare deux strings char par char tant qu'elles sont identiques.
**		renvoit 0 si completement identique, sinon la difference entre les char
*/
char				ft_strcmp_np(const char *s1, const char *s2);

/*
**	ft_strcmp_nocase	->	string/ft_strcmp.c
**		compare deux strings (sans distinction de case : MAJUSCULE/minuscule)
**		char par char tant qu'elles sont identiques.
**		renvoit 0 si completement identique, sinon la difference entre les char
*/
char				ft_strcmp_nocase(char *s1, char *s2);

/*
**	ft_strcmp	->	string/ft_strcmp.c
**		compare deux strings char par char tant qu'elles sont identiques.
**		renvoit 0 si completement identique, sinon la difference entre les char
*/
int					ft_strcmp(const char *s1, const char *s2);

/*
**	ft_cmpt_chr  -->  libft/string/ft_cmpt_chr.c
**		compte le nombre de char c dans un string
*/
int					ft_cmpt_chr(char *s, char c);

/*
**	ft_cmpt_n_chr  -->  libft/string/ft_cmpt_chr.c
**		compte le nombre de char c dans un string
**		avec end comme limit, ne stop pas a '\0'
*/
int					ft_cmpt_n_chr(char *s, int end, char c);

/*
**	ft_ftoa 	->	ft_itoa.c
**		transforme double en char*
**		pre	-> nombre de chifre après la virgule
*/
char				*ft_ftoa(double n, unsigned char pre);

/*
**	ft_ftoa 	->	ft_itoa2.c
**		transforme long int en char*
*/
char				*ft_ldtoa(long int n);

/*
**	ft_low_case -> ft_low_case.c
**		met en minuscule un chaine de char
*/
void				ft_low_case(char *str);

/*
**	ft_ftoa 	->	ft_itoa2.c
**		transforme size_t en char*
*/
char				*ft_lutoa(size_t n);

/*
**	ft_str_next_line_p -> libft/string/ft_str_next_line.c
**		renvoi l'indice sur la prochaine ligne de la chaine passer en param
**		not protected
*/
int					ft_str_next_line_np(char *str, int i);

/*
**	ft_str_next_line_p -> libft/string/ft_str_next_line.c
**		renvoi l'indice sur la prochaine ligne de la chaine passer en param
**		protected
*/
int					ft_str_next_line_p(char *str, int i);

/*
**	ft_str_part_cmp_p_r_i -> libft/string/ft_strncmp.c
**		compare s2 a s1 sur la longeur de s2, renvoi sa len
*/
int					ft_str_part_cmp_p_r_i(char *s1, char *s2);

/*
**	ft_str_replace_next_chr -> libft/string/ft_strchr_replace.c
**		remplace le prochain char c par r dans une string
*/
int					ft_str_replace_next_chr(char *s, char c, char r);

/*
**	ft_strchr	->	libft/string/ft_strchr.c
**		recherche c dans
**		renvoie la addresse de c dans s
*/
char				*ft_strchr(const char *s, char c);

/*
**	ft_strchr_i	->	libft/string/ft_strchr.c
**		recherche c dans
**		renvoie la position de c dans s
*/
int					ft_strchr_i(char *s, char c);

/*
**	ft_strchr_i_back	->	libft/string/ft_strchr.c
**		recherche c dans s
**		renvoie la position de la derniere c dans s
*/

int					ft_strchr_i_back(char *s, char c);

/*
**	ft_strdup	->	libft/string/ft_strdup.c
**		duplique dans un malloc une chaine
*/
char				*ft_strdup(const char *s1);

/*
**	ft_strfstr	-> libft/ft_strnstr.c
**		recherche sur tout "big" une partie de sub
**		renvoi success or fail
*/
char				ft_strfstr(const char *big, const char *sub);

/*
**	ft_strjoin	-> libft/string/ft_strjoin.c
**		concatene 2 chaine en mallocant une string
**		de la longueur egale a la somme de ces 2 dernieres.
*/
char				*ft_strjoin(char const *s1, char const *s2);

/*
**	ft_strjoin_3	-> ft_strjoin.c
**		concatene 3 chaines en mallocant une string
**		de la longueur egale a la somme de ces 3 dernieres.
*/
char				*ft_strjoin_3(char *s1, char *s2, char *s3);

/*
**	ft_strjoin_n ->ft_strjoin.c
**		concatene n chaines en mallocant une string
**		de la longueur egale a la somme de ces n dernieres.
*/
char				*ft_strjoin_n(int n, ...);

/*
**	ft_strlen  -->  libft/string/ft_strlen.c
**		compte le nombre de char dans une string
*/
size_t				ft_strlen(const char *s);

/*
**	ft_strlen_np  -->  libft/string/ft_strlen.c
**		compte le nombre de char dans une string, no protected
*/
int					ft_strlen_np(const char *s);

/*
**	ft_strlen_p  -->  libft/string/ft_strlen.c
**		compte le nombre de char dans une string
*/
int					ft_strlen_p(const char *s);

/*
**	ft_strncmp_nocase -> libft/string/ft_strncmp.c
**		compare deux str sans distinction de case, sur n char
*/
char				ft_strncmp_nocase(char *s1, char *s2, int n);

/*
**	ft_strncpy_2	->libft/ft_strncpy.c
**		copie n char, sans protection
*/
int					ft_strncpy_2(char *dst, char *src, int len);

/*
**	ft_strndup	->	libft/string/ft_strdup.c
**		duplique dans un malloc n + 1 char,
**		les n premier char d'une chaine
*/
char				*ft_strndup(const char *s1, int i);

/*
**	ft_strnstr	->	libft/ft_strnstr.c
**		recherche dans une partie de big (<len) sub;
**		renvoie la position de sub dans big si ok, ou NULL sinon
*/
char				*ft_strnstr(const char *big,
	const char *little, unsigned int len);

/*
**	ft_strsplit_buf -> libft/string/ft_strsplit_buf.c
**		compte le nombre de sous-string delimite par c
**		remplace c par '\0'
*/
int					ft_strsplit_buf(char *s, char c);

/*
**	ft_strstr	->	libft/ft_strstr.c
**		recherche little dans big,
**		renvoie la position de little dans big si ok, sinon NULL
*/
char				*ft_strstr(char *big, char *little);

/*
**	ft_strtrim_back	-> libft/string/ft_strtrim.c
**		suprime les espaces derriere une str et renvoie la str
*/
char				*ft_strtrim_back(char *s);

/*
**	ft_strtrim_both	-> libft/string/ft_strtrim.c
**		suprime les espaces devant et derriere une str et renvoie la str
*/
char				*ft_strtrim_both(char *s);

/*
**	ft_strtrim_front -> libft/string/ft_strtrim.c
**		suprime les espaces devant une str et renvoie la str
*/
char				*ft_strtrim_front(char *s);

/*
**	ft_wcharlen -> ft_strlen.c
**		compte le nombre de char dans un wchar_t*
*/
size_t				ft_wcharlen(const wchar_t *s);

#endif
