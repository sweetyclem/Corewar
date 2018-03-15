/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_x.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 14:44:24 by apopinea          #+#    #+#             */
/*   Updated: 2018/03/05 14:21:48 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUT_X_H
# define PUT_X_H

void	ft_putbuf_litoa_fd_np(int fd, long int n, char *dst, int *i);
void	ft_putbuf_fd_loop_char_np(int fd_n_x, char c, char *dst, int *i);
void	ft_putbuf_fd_loop_tabu_np(int fd, int nb_tabu, char *dst, int *i);
void	ft_loop_putchar(char c, unsigned int i);
void	ft_putchar(char c);
void	ft_putendl(char const *s);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putfloat(double n);
void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr3(long long n);
void	ft_putnbr4(long long n);
void	ft_putstr(char const *str);
void	ft_putstr_fd(char const *s, int fd);
int		ft_putstrr(char const *str);
void	ft_putbuf_len_np(char *s, char *d);
void	ft_putnbuf_np(char *s, char *d, int i);
void	ft_putnbuf_fd_np(int fd_n_size[2], char *src, char *dst, int *i);
void	ft_loop_putchar_fd(char c, int fd, int nb);

/*
**	ft_putbuf_fd_endl_np -> libft/put_x/ft_putbuf_fd.c
**		copy une chaine dans une autre si trop grand print dans le fd
**		ajoute un \n a la fin
**		size de dst 65536
**		non proteger
*/
void	ft_putbuf_fd_endl_np(int fd, char *src, char *dst, int *i);

/*
**	ft_putbuf_fd_endl_p -> libft/put_x/ft_putbuf_fd.c
**		copy une chaine dans une autre si trop grand print dans le fd
**		ajoute un \n a la fin
**		size de dst 65536
**		proteger
*/
char	ft_putbuf_fd_endl_p(int fd, char *src, char *dst, int *i);

/*
**	ft_putbuf_fd_np -> libft/put_x/ft_putbuf_fd.c
**		copy une chaine dans une autre si trop grand print dans le fd
**		size de dst 65536
**		non protegee
*/
void	ft_putbuf_fd_np(int fd, char *src, char *dst, int *i);

/*
**	ft_putbuf_fd_p -> libft/put_x/ft_putbuf_fd.c
**		copy une chaine dans une autre si trop grand print dans le fd
**		size de dst 65536
**		proteger
*/
char	ft_putbuf_fd_p(int fd, char *src, char *dst, int *i);

/*
**	ft_putchar_fd -> libft/put_x/ft_putchar_fd.c
**		ecrit dans un fd un char
*/
void	ft_putchar_fd(char c, int fd);

/*
**	ft_putbuf_fd_cendl_np	-> libft/put_x/ft_putbuf_fd.c
**		ecrit dans un buffer et finit par ';\n'
**		si buffer full -> write dans fd.
*/
void	ft_putbuf_fd_cendl_np(int fd, char *src, char *dst, int *i);

/*
**	ft_putbuf_itoa_fd_np	-> libft/put_x/ft_putitoa_base_fd.c
**		equivalent a ft_itoa_base mais ecrit dans un buffer *dst
*/
void	ft_putbuf_itoa_base_fd_np(int fd_n_base, int nb, char *dst, int *i);

/*
**	ft_putbuf_itoa_fd_np	-> libft/put_x/ft_putitoa_fd.c
**		equivalent a ft_itoa mais ecrit dans un buffer *dst
*/
void	ft_putbuf_itoa_fd_np(int fd, int nb, char *dst, int *i);

/*
**	ft_putbuf_mm_fd_np
**			->	libft/put_x/ft_putbuf_mm_fd_np.c
**		permet d'enregistrer une donnee passer en void (*d) dans un fichier
**		identifie par son fd.
*/
void	ft_putbuf_mm_fd_np(int fd_n_size, void *d, char *dst, int *i);

/*
**	ft_putbuf_np	->	libft/put_x/ft_write_buf.c
**		recopie s dans d
*/
void	ft_putbuf_np(char *s, char *d, int *i);

/*
**	ft_putbuf_itoa_np	-> libft/put_x/ft_putbuf_itoa_fd_2.c
**		idem ft_itoa (convertie int -> string) mais
**		ecrit dans un buffer passe en parametre.
*/
void	ft_putbuf_itoa_np(int nb, char *dst, int *i);

/*
**	ft_putbuf_scitoa_fd_np	-> libft/put_x/ft_putbuf_itoa_fd_2.c
**		idem ft_scitoa (convertie float->string) mais
**		ecrit dans un buffer passe en parametre.
*/
void	ft_putbuf_scitoa_fd_np(int pre0_fd16, double nb, char *dst, int *i);

#endif
