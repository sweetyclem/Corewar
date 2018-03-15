/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 10:34:14 by apopinea          #+#    #+#             */
/*   Updated: 2017/12/05 16:43:49 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_FT_PRINTF_H
# define P_FT_PRINTF_H

# include "ft_printf.h"
# include "str.h"
# include "nombre.h"
# include "p_common_inc.h"

/*
**	masque pour recuper les flags
*/
# define B_DIESE	0b1
# define B_ZERO 	0b10
# define B_MOIN 	0b100
# define B_SPACE 	0b1000
# define B_PLUS 	0b10000
# define B_AQ 		0b100000
# define B_WIDTH 	0b1000000
# define B_PREC 	0b10000000
# define B_HH		0b100000000
# define B_H		0b1000000000
# define B_L		0b10000000000
# define B_LL		0b100000000000
# define B_BL		0b1000000000000
# define B_J		0b10000000000000
# define B_Z		0b100000000000000
# define B_EXCLU	0b111111100000000

# define BUF_SIZE	65535u

struct s_ft_printf_env;

/*
**	t_ptf_printf
**		pt 		: pointeur sur fonction de convertion
**		flag 	: lettre correspondant a la convertion
*/
typedef struct				s_ptf_printf
{
	void					(*pt)(struct s_ft_printf_env*, va_list);
	char					flag;
}							t_ptf_printf;

/*
**	t_ft_printf_env
**		ap 			: variable de va_start
**		buf 		: buf, contenu a write
**		cur			: indice dans buf
**		ct_total	: longueur total
**		ct_flag 	: longeur flag de la convertion en cours
**		config 		: enregistre présence des composantes des flags
**		width 		: largeur de champs de la cv en cours
**		prec 		: precision de la cv en cours
**		s_prec 		: surplu de convertion
**		s_width 	: surplu de largeur de champs
**		signe 		: signe +, -, ou ' ' en fonction des attributs
**		dot 		: dot ou non pour les float
**		nb_digit 	: longeur de l'argument sans traitement
**		tmp			: valeur intermediair
**		total_sum	: longeur de l'argument en cours
**		stmp		: chaine tampon
**		s 			: residu
**		tab 		: tableau de pointeur sur fonction de convertion
*/
typedef	struct				s_ft_printf_env
{
	va_list					ap;
	char					buf[BUF_SIZE];
	size_t					cur;
	size_t					ct_total;
	size_t					ct_flag;
	short					config;
	size_t					width;
	size_t					prec;
	size_t					s_prec;
	size_t					s_width;
	char					signe;
	char					dot;
	size_t					nb_digit;
	size_t					tmp;
	size_t					total_sum;
	char					stmp[22];
	const char				*s;
	t_ptf_printf			*tab;
}							t_ft_printf_env;

/*
**	ft_init_tab -> ft_printf/ft_init_tab.c
**		initialise le tableau de pointeur sur fonctions de convertions
*/
void						ft_init_tab(t_ptf_printf tab[20]);

/*
**	ft_printf2 -> ft_printf/ft_printf2.c
**		lance processe
*/
void						ft_printf2(t_ft_printf_env *e, const char *s);

/*
**	ft_pars_arg -> ft_printf/ft_pars_arg.c
**		capt le flag et print dans buf
*/
int							ft_pars_arg(t_ft_printf_env *e,
								size_t i);

/*
**	ft_capt_flag_attribut -> ft_printf/ft_capt_flag_attribut.c
**		enregistre les attributs d'un argument dans config
*/
void						ft_capt_flag_attribut(const char *s,
								t_ft_printf_env *e, size_t i);

/*
**	ft_capt_flag_width -> ft_printf/ft_capt_flag_width.c
**		enregistre la largeur de champ d'un argument dans config
*/
void						ft_capt_flag_width(const char *s,
							t_ft_printf_env *e, size_t i);

/*
**	ft_capt_flag_prec -> ft_printf/ft_capt_flag_prec.c
**		enregistre la precision d'un argument dans config
*/
void						ft_capt_flag_prec(const char *s, t_ft_printf_env *e,
								size_t i);

/*
**	ft_capt_flag_mod -> ft_printf/ft_capt_flag_mod.c
**		enregistre le modificateur de longeur d'un argument dans config
*/
void						ft_capt_flag_mod(const char *s, t_ft_printf_env *e,
								size_t i);

/*
**	ft_capt_flag_cv -> ft_printf/ft_capt_flag_cv.c
**		envois a la fonction cv correspondante au type de cv
*/
int							ft_capt_flag_cv(char c, t_ptf_printf *tab,
								t_ft_printf_env *e);

/*
**	ft_cv_di -> ft_printf/ft_cv_di.c
**		rempli le maillon suivant la convertion de type d et i (int),
**		en fonction du modificateur de longeur le nombre est recup dans
**		un type different
*/
void						ft_cv_di(t_ft_printf_env *e, va_list ap);

/*
**	ft_di_up_config -> ft_printf/ft_cv_di_2.c
**		efface les flags superflus :
**			' ' ignoré si +
**			0 ignoré si precision ou -
*/
void						ft_di_up_config(t_ft_printf_env *e);

/*
**	ft_setting_di -> ft_printf/ft_cv_di_2.c
**		rempli la struct des variables pour la convertion
*/
void						ft_setting_di(t_ft_printf_env *e, long long int nb);

/*
**	ft_itoa_di -> ft_printf/ft_cv_di_3.c
**		transforn nb en chaine et recupere le e->signe
*/
void						ft_itoa_di(long long int nb, t_ft_printf_env *e);

/*
**	ft_itoa_di_3 -> t_printf/ft_cv_di_4.c
**		itoa classique dans une chaine
*/
unsigned int				ft_itoa_di_3(unsigned long long nb, char *str,
								unsigned int i);

/*
**	ft_print_di -> ft_printf/ft_print_di.c
**		print dans le bonne ordre la convertion
*/
void						ft_print_di(t_ft_printf_env *e);

/*
**	ft_print_di_b_else -> ft_printf/ft_print_di_2.c
**		print dans les cas restants
*/
void						ft_print_di_else(t_ft_printf_env *e);

/*
**	ft_print_di_b_zero -> ft_printf/ft_print_di_2.c
**		print si attribut 0
*/
void						ft_print_di_b_zero(t_ft_printf_env *e);

/*
**	ft_print_di_b_mois -> ft_printf/ft_print_di_3.c
**		print si attribut -
*/
void						ft_print_di_b_moins(t_ft_printf_env *e);

/*
**	ft_loop_setchar_printf -> ft_printf/ft_print_outil.c
**		copy x fois un char dans une chaine a partir du debut de celle ci
*/
void						ft_loop_setchar_printf(char c, char *s, size_t i);

/*
**	ft_setstr_printf -> ft_printf/ft_print_outil.c
**		copy dans une chaine une autre a partir du debut
*/
void						ft_setstr_printf(char *src, char *dst, size_t i);

/*
**	ft_set_nbr_dot_printf -> ft_printf/ft_print_outil.c
**		copy dans une chaine un nombre en char avec des , entre les millier
*/
void						ft_set_nbr_dot_printf(char *src, char *dst,
								size_t i, size_t j);

/*
**	ft_loop_setchar_printf_spe -> ft_printf/ft_print_outil.c
**		copy x fois un char dans une chaine a partir du debut de celle ci
**		avec verificaion si trops grand -> print le buf plei et continu
*/
void						ft_loop_setchar_printf_spe(char c, char *s,
								size_t i, t_ft_printf_env *e);

/*
**	ft_setstr_printf_spe -> ft_printf/ft_print_outil.c
**		copy dans une chaine une autre a partir du debut
**		avec verificaion si trops grand -> print le buf plein et continu
*/
void						ft_setstr_spe_printf(char *src, char *dst, size_t i,
								t_ft_printf_env *e);

/*
**	ft_set_nbr_dot_printf -> ft_printf/ft_print_outil.c
**		copy dans une chaine un nombre en char avec des , entre les millier
**		avec verificaion si trops grand -> print le buf plein et continu
*/
void						ft_set_nbr_dot_spe_printf(char *src, char *dst,
								size_t i, t_ft_printf_env *e);

/*
**	ft_print_di_spe -> ft_printf/ft_print_di_spe.c
**		print les differentes partie de la convertion dans l'ordre donné
**		par les flag
**		avec verificaion si trops grand -> print le buf plein et continu
*/
void						ft_print_di_spe(t_ft_printf_env *e);

/*
**	ft_print_di_spe_b_else -> ft_printf/ft_print_di_spe_2.c
**		print dans les cas restants
**		avec verificaion si trops grand -> print le buf plei et continu
*/
void						ft_print_di_spe_else(t_ft_printf_env *e);

/*
**	ft_print_di_spe_b_zero -> ft_printf/ft_print_di_spe_2.c
**		print si attribut 0
**		avec verificaion si trops grand -> print le buf plei et continu
*/
void						ft_print_di_spe_b_zero(t_ft_printf_env *e);

/*
**	ft_print_di__spe_b_mois -> ft_printf/ft_print_di_spe_3.c
**		print si attribut -
**		avec verificaion si trops grand -> print le buf plei et continu
*/
void						ft_print_di_spe_b_moins(t_ft_printf_env *e);

/*
**	ft_cv_err -> ft_printf/ft_cv_err.c
**		fonction par defaut de convertion ou appellé si flag incorrect
*/
void						ft_cv_err(t_ft_printf_env *e, char c);

/*
**	ft_cv_s -> ft_printf/ft_cv_s.c
**		effectue les processe de la convertion de type s (string),
**		en fonction du modificateur de longeur le nombre est recup dans
**		un type different
*/
void						ft_cv_s(t_ft_printf_env *e, va_list ap);

/*
**	t_cv_s_null -> ft_printf/ft_cv_s_null.c
**		copy (null) dans buf
*/
void						ft_cv_s_null(t_ft_printf_env *e, char *s);

/*
**	ft_s_up_config -> ft_printf/ft_cv_s_2.c
**		efface les flags superflus :
**			0 ignoré si -
*/
void						ft_s_up_config(t_ft_printf_env *e);

/*
**	ft_setting_s -> ft_printf/ft_cv_s_2.c
**		rempli la struct des variables pour la convertion
*/
void						ft_setting_s(t_ft_printf_env *e, char *str);

/*
**	ft_print_s -> ft_printf/ft_print_s.c
**		print les differentes partie de la convertion dans l'ordre donné
**		par les flag
*/
void						ft_print_s(t_ft_printf_env *e, char *s);

/*
**	ft_print_s_spe -> ft_printf/ft_print_s_spe.c
**		print les differentes partie de la convertion dans l'ordre donné
**		par les flag
**		avec verificaion si trops grand -> print le buf plein et continu
*/
void						ft_print_s_spe(t_ft_printf_env *e, char *s);

/*
**	ft_cv_f	-> ft_printf/ft_cv_f.c
**		affiche les convertion de type double
*/
void						ft_cv_f(t_ft_printf_env *e, va_list ap);

/*
**	ft_f_up_config -> ft_printf/ft_cv_di_2.c
**		efface les flags superflus :
**			' ' ignoré si +
**			0 ignoré si precision ou -
*/
void						ft_f_up_config(t_ft_printf_env *e);

/*
**	ft_setting_f -> ft_printf/ft_cv_f_2.c
**		rempli la struct des variables pour la convertion
*/
void						ft_setting_f(t_ft_printf_env *e, long double *nb);

/*
**	ft_cv_f_signe -> ft_printf/ft_cv_f_3.c
**		recup le signe et le nb_digit
*/
void						ft_cv_f_signe(long double *nb, t_ft_printf_env *e);

/*
**	<-- ft_print_f -> ft_printf/ft_print_f.c
**		print les differentes partie de la convertion dans l'ordre donné
**		par les flag
*/
void						ft_print_f(t_ft_printf_env *e, long double nb);

/*
**	ft_cv_f_put_parti_e -> ft_printf/ft_print_f_2.c
**		print la partie entiere dans buf
*/
long double					ft_cv_f_put_parti_e(t_ft_printf_env *e,
								long double nb);

/*
**	ft_cv_f_put_parti_e_3 -> ft_printf/ft_print_f_3.c
**		print la partie entiere dans buf, avec 'AQ'
*/
long double					ft_cv_f_put_parti_e_3(size_t nb_digit,
								long double nb, char *s);

/*
**	ft_cv_f_put_parti_d -> ft_printf/ft_print_f_3.c
**		print la partie decimal dans buf
*/
long double					ft_cv_f_put_parti_d(long double rest,
								unsigned int prec, char *s);

/*
**	ft_print_f_b_moins -> ft_printf/ft_print_f_4.c
**		print si flag -
*/
void						ft_print_f_b_moins(t_ft_printf_env *e,
								long double nb);

/*
**	ft_print_f_b_zero -> ft_printf/ft_print_f_4.c
**		print si flag zero
*/
void						ft_print_f_b_zero(t_ft_printf_env *e,
								long double nb);

/*
**	ft_print_f_else -> ft_printf/ft_print_f_5.c
**		print autre cas
*/
void						ft_print_f_else(t_ft_printf_env *e,
								long double nb);

/*
**	ft_print_f_spe -> ft_printf/ft_print_f_spe.c
**		print les differentes partie de la convertion dans l'ordre donné
**		par les flag
*/
void						ft_print_f_spe(t_ft_printf_env *e, long double nb);

/*
**	ft_cv_f_put_parti_e_spe -> ft_printf/ft_print_f_spe_2.c
**		print la partie entiere dans buf
**		avec verificaion si trops grand -> print le buf plein et continu
*/
long double					ft_cv_f_put_parti_e_spe(t_ft_printf_env *e,
								long double nb);

/*
**	ft_set_char_verif -> ft_printf/ft_print_outil_2.c
**		copy un char dans buf et verifi si il est plein
*/
void						ft_set_char_verif(char c, t_ft_printf_env *e);

/*
**	ft_cv_f_put_parti_e_spe_3 -> ft_printf/ft_print_f_spe_3.c
**		print la partie entiere dans buf, avec 'AQ'
**		avec verificaion si trops grand -> print le buf plein et continu
*/
long double					ft_cv_f_put_parti_e_spe_3(size_t nb_digit,
								long double nb, t_ft_printf_env *e);

/*
**	ft_cv_f_put_parti_d_spe -> ft_printf/ft_print_f_spe_3.c
**		print la partie decimal dans buf
**		avec verificaion si trops grand -> print le buf plein et continu
*/
void						ft_cv_f_put_parti_d_spe(long double rest,
								unsigned int prec, t_ft_printf_env *e);

/*
**	ft_print_f_b_zero_spe-> ft_printf/ft_print_f_spe_4.c
**		print si flag zero
**		avec verificaion si trops grand -> print le buf plein et continu
*/
void						ft_print_f_b_zero_spe(t_ft_printf_env *e,
								long double nb);

/*
**	ft_print_f_b_moins_spe -> ft_printf/ft_print_f_spe_4.c
**		print si flag -
**		avec verificaion si trops grand -> print le buf plein et continu
*/
void						ft_print_f_b_moins_spe(t_ft_printf_env *e,
								long double nb);

/*
**	ft_print_f_else_spe -> ft_printf/ft_print_f_spe_5.c
**		print dans les autres cas
**		avec verificaion si trops grand -> print le buf plein et continu
*/
void						ft_print_f_else_spe(t_ft_printf_env *e,
								long double nb);

/*
**	ft_cv_e	-> ft_printf/ft_cv_e.c
**		affiche les convertion de type double en ecriture scientifique
*/
void						ft_cv_e(t_ft_printf_env *e, va_list ap);

/*
**	ft_e_up_config -> ft_printf/ft_cv_e_2.c
**		efface les flags superflus :
**			' ' ignoré si +
**			0 ignoré si precision ou -
*/
void						ft_e_up_config(t_ft_printf_env *e);

/*
**	ft_setting_e -> ft_printf/ft_cv_e_2.c
**		rempli la struct des variables pour la convertion
*/
void						ft_setting_e(t_ft_printf_env *e, long double *nb);

/*
**	ft_cv_e_signe -> ft_printf/ft_cv_e_2.c
**		recupere le e->signe et nb_digit de l'exposant
*/
void						ft_cv_e_signe(long double *nb, t_ft_printf_env *e);

/*
**	ft_print_e -> ft_printf/ft_print_e.c
**		print les differentes partie de la convertion dans l'ordre donné
**		par les flag
*/
void						ft_print_e(t_ft_printf_env *e, long double nb);

/*
**	ft_print_f_b_zero -> ft_printf/ft_print_e_2.c
**		print si flag zero
*/
void						ft_print_e_b_zero(t_ft_printf_env *e,
								long double nb);

/*
**	ft_print_f_else -> ft_printf/ft_print_e_2.c
**		print dans les autres cas
*/
void						ft_print_e_else(t_ft_printf_env *e,
								long double nb);

/*
**	ft_cv_e_put_nbr -> ft_printf/ft_print_e_3.c
**		print le nombre en notation scientifique
*/
void						ft_cv_e_put_nbr(t_ft_printf_env *e,
								long double nb);

/*
**	ft_set_partie_e_e -> ft_printf/ft_print_e_4.c
**		print la partie entiere de la notation scientifique
*/
void						ft_set_partie_e_e(t_ft_printf_env *e,
								long double *nb);

/*
**	ft_set_partie_expos_e -> ft_printf/ft_print_e_5.c
**		print l'exposant de la notation scientifique
*/
void						ft_set_partie_expos_e(t_ft_printf_env *e,
								long double nb, int u);

/*
**	ft_cv_c -> ft_printf/ft_cv_c.c
**		effectue les processe de la convertion de type c (char),
**		en fonction du modificateur de longeur le nombre est recup dans
**		un type different
*/
void						ft_cv_c(t_ft_printf_env *e, va_list ap);

/*
**	ft_c_up_config -> ft_printf/ft_cv_c_2.c
**		efface les flags superflus :
**			0 ignoré si -
*/
void						ft_c_up_config(t_ft_printf_env *e);

/*
**	ft_setting_c -> ft_printf/ft_cv_c_2.c
**		rempli la struct des variables pour la convertion
*/
void						ft_setting_c(t_ft_printf_env *e);

/*
**	ft_print_c -> ft_printf/ft_print_c.c
**		print les differentes partie de la convertion dans l'ordre donné
**		par les flag
*/
void						ft_print_c(t_ft_printf_env *e, char c);

/*
**	ft_cv_p -> ft_printf/ft_cv_p.c
**		effectue les processe de la convertion de type print adrr,
**		en fonction du modificateur de longeur le nombre est recup dans
**		un type different
*/
void						ft_cv_p(t_ft_printf_env *e, va_list ap);

/*
**	ft_p_up_config -> ft_printf/ft_cv_p_2.c
**		efface les flags superflus :
**			0 ignoré si - ou prec
*/
void						ft_p_up_config(t_ft_printf_env *e);

/*
**	ft_setting_x -> ft_printf/ft_cv_p_2.c
**		rempli la struct des variables pour la convertion
*/
void						ft_setting_p(t_ft_printf_env *e,
								long long unsigned int nb);

/*
**	ft_itoa_p -> ft_printf/ft_cv_p_3.c
**		transforn nb en chaine en base 16
*/
void						ft_itoa_p(long long unsigned int nb,
								t_ft_printf_env *e);

/*
**	ft_print_p -> ft_printf/ft_print_p.c
**		print dans le bonne ordre la convertion
*/
void						ft_print_p(t_ft_printf_env *e);

/*
**	ft_print_p_else -> ft_printf/ft_print_p_2.c
**		print dans les cas restants
**		avec verificaion si trops grand -> print le buf plei et continu
*/
void						ft_print_p_else(t_ft_printf_env *e);

/*
**	<ft_print_p_zero -> ft_printf/ft_print_p_2.c
**		print si attribut 0
**		avec verificaion si trops grand -> print le buf plei et continu
*/
void						ft_print_p_b_zero(t_ft_printf_env *e);

/*
**	ft_cv_x -> ft_printf/ft_cv_x.c
**		effectue les processe de la convertion de type print hexa,
**		en fonction du modificateur de longeur le nombre est recup dans
**		un type different
*/
void						ft_cv_x(t_ft_printf_env *e, va_list ap);

/*
**	ft_x_up_config -> ft_printf/ft_cv_x_2.c
**		efface les flags superflus :
**			0 ignoré si - ou prec
*/
void						ft_x_up_config(t_ft_printf_env *e,
								unsigned long long int nb);

/*
**	ft_setting_x -> ft_printf/ft_cv_x_2.c
**		rempli la struct des variables pour la convertion
*/
void						ft_setting_x(t_ft_printf_env *e,
								long long unsigned int nb);

/*
**	ft_itoa_x -> ft_printf/ft_cv_x_3.c
**		transforn nb en chaine en base 16
*/
void						ft_itoa_x(long long unsigned int nb,
								t_ft_printf_env *e);

/*
**	ft_print_x -> ft_printf/ft_print_x.c
**		print dans le bonne ordre la convertion
*/
void						ft_print_x(t_ft_printf_env *e);

/*
**	ft_print_x_else -> ft_printf/ft_print_x_2.c
**		print dans les cas restants
**		avec verificaion si trops grand -> print le buf plei et continu
*/
void						ft_print_x_else(t_ft_printf_env *e);

/*
**	<ft_print_x_zero -> ft_printf/ft_print_x_2.c
**		print si attribut 0
**		avec verificaion si trops grand -> print le buf plei et continu
*/
void						ft_print_x_b_zero(t_ft_printf_env *e);

/*
**	ft_cv_b -> ft_printf/ft_cv_b.c
**		effectue les processe de la convertion de print memory,
**		en fonction du modificateur de longeur le nombre est recup dans
**		un type different
*/
void						ft_cv_b(t_ft_printf_env *e, va_list ap);

/*
**	ft_setting_b -> ft_printf/ft_cv_b_2.c
**		rempli la struct des variables pour la convertion
*/
void						ft_setting_b(t_ft_printf_env *e);

/*
**	ft_print_b -> ft_printf/ft_print_b.c
**		print dans le bonne ordre la convertion
*/
void						ft_print_b(t_ft_printf_env *e, unsigned char *tab);

/*
**	ft_itoa_b -> ft_printf/ft_print_b_2.c
**		affiche une zone memoire
*/
void						ft_itoa_b(t_ft_printf_env *e, unsigned char *tab);

/*
**	ft_cv_cc -> ft_printf/ft_cv_cc.c
**		effectue les processe de la convertion de type c (char),
**		en fonction du modificateur de longeur le nombre est recup dans
**		un type different
*/
void						ft_cv_cc(t_ft_printf_env *e, va_list ap);

/*
**	ft_setting_cc -> ft_printf/ft_cv_cc_2.c
**		rempli la struct des variables pour la convertion
*/
void						ft_setting_cc(t_ft_printf_env *e, wchar_t c);

/*
**	ft_cc_up_config -> ft_printf/ft_cv_cc_2.c
**		efface les flags superflus :
**			0 ignoré si -
*/
void						ft_cc_up_config(t_ft_printf_env *e);

/*
**	ft_print_cc -> ft_printf/ft_print_cc.c
**		print dans le bonne ordre la convertion
*/
void						ft_print_cc(t_ft_printf_env *e, wchar_t c);

/*
**	ft_putwchar -> ft_printf/ft_print_cc_2.c
**		print des wchar_t
*/
void						ft_putwchar(t_ft_printf_env *e, wchar_t nb);

/*
**	ft_cv_ss -> ft_printf/ft_cv_ss.c
**		effectue les processe de la convertion de type s (string),
**		en fonction du modificateur de longeur le nombre est recup dans
**		un type different
*/
void						ft_cv_ss(t_ft_printf_env *e, va_list ap);

/*
**	ft_ss_up_config -> ft_printf/ft_cv_ss_2.c
**		efface les flags superflus :
**			0 ignoré si -
*/
void						ft_ss_up_config(t_ft_printf_env *e);

/*
**	ft_setting_ss -> ft_printf/ft_cv_ss_2.c
**		rempli la struct des variables pour la convertion
*/
void						ft_setting_ss(t_ft_printf_env *e, wchar_t *str);

/*
**	ft_print_ss -> ft_printf/ft_print_ss.c
**		print dans le bonne ordre la convertion
*/
void						ft_print_ss(t_ft_printf_env *e, wchar_t *s);

/*
**	ft_setwchar_printf_spe -> ft_printf/ft_print_outil.c
**		copy dans une chaine une autre a partir du debut
**		avec verificaion si trops grand -> print le buf plei et continu
*/
void						ft_setwchar_spe_printf(wchar_t *src,
								t_ft_printf_env *e, size_t j);

/*
**	ft_cv_u -> ft_printf/ft_cv_u.c
**		effectue les processe de la convertion de type u (unsigned int),
**		en fonction du modificateur de longeur le nombre est recup dans
**		un type different
*/
void						ft_cv_u(t_ft_printf_env *e, va_list ap);

/*
**	ft_u_up_config -> ft_printf/ft_cv_u_2.c
**		efface les flags superflus
*/
void						ft_u_up_config(t_ft_printf_env *e);

/*
**	ft_setting_u -> ft_printf/ft_cv_u_2.c
**		rempli la struct des variables pour la convertion
*/
void						ft_setting_u(t_ft_printf_env *e,
								unsigned long long int nb);

/*
**		ft_itoa_u -> ft_printf/ft_cv_u_3.c
**			transforn nb en chaine et recupere le e->signe
*/
void						ft_itoa_u(unsigned long long int nb,
								t_ft_printf_env *e);

/*
**	ft_cv_uu -> ft_printf/ft_cv_uu.c
**		effectue les processe de la convertion de type U (unsigned long int),
**		en fonction du modificateur de longeur le nombre est recup dans
**		un type different
*/
void						ft_cv_uu(t_ft_printf_env *e, va_list ap);

/*
**	ft_cv_dd -> ft_printf/ft_cv_dd.c
**		effectue les processe de la convertion de type D (long int),
**		en fonction du modificateur de longeur le nombre est recup dans
**		un type different
*/
void						ft_cv_dd(t_ft_printf_env *e, va_list ap);

/*
**	ft_cv_xx -> ft_printf/ft_cv_xx.c
**		effectue les processe de la convertion de type X,
**		en fonction du modificateur de longeur le nombre est recup dans
**		un type different
*/
void						ft_cv_xx(t_ft_printf_env *e, va_list ap);

/*
**	ft_cv_mod -> ft_printf/ft_cv_mod.c
**		effectue les processe de la convertion de type %,
**		en fonction du modificateur de longeur le nombre est recup dans
**		un type different
*/
void						ft_cv_mod(t_ft_printf_env *e, va_list ap);

/*
**	ft_cv_ee -> ft_printf/ft_cv_ee.c
**		effectue les processe de la convertion de type E,
**		en fonction du modificateur de longeur le nombre est recup dans
**		un type different
*/
void						ft_cv_ee(t_ft_printf_env *e, va_list ap);

/*
**	ft_cv_o -> ft_printf/ft_cv_o.c
**		effectue les processe de la convertion de type o,
**		en fonction du modificateur de longeur le nombre est recup dans
**		un type different
*/
void						ft_cv_o(t_ft_printf_env *e, va_list ap);

/*
**	ft_o_up_config -> ft_printf/ft_cv_o_2.c
**		efface les flags superflus
*/
void						ft_o_up_config(t_ft_printf_env *e,
								unsigned long long int nb);

/*
**	ft_setting_o -> ft_printf/ft_cv_o_2.c
**		rempli la struct des variables pour la convertion
*/
void						ft_setting_o(t_ft_printf_env *e,
								unsigned long long int nb);

/*
**	ft_itoa_o -> ft_printf/ft_cv_o_3.c
**		transforn nb en chaine en base 8
*/
void						ft_itoa_o(unsigned long long int nb,
								t_ft_printf_env *e);

/*
**	ft_print_o -> ft_printf/ft_print_o.c
**		print dans le bonne ordre la convertion
*/
void						ft_print_o(t_ft_printf_env *e);

/*
**	ft_print_o_b_zero -> ft_printf/ft_print_o_2.c
**		print si attribut 0
*/
void						ft_print_o_b_zero(t_ft_printf_env *e);

/*
**	ft_print_o_b_else -> ft_printf/ft_print_o_2.c
**		print dans les cas restants
*/
void						ft_print_o_else(t_ft_printf_env *e);

/*
**	ft_cv_oo -> ft_printf/ft_cv_oo.c
**		effectue les processe de la convertion de type O,
**		en fonction du modificateur de longeur le nombre est recup dans
**		un type different
*/
void						ft_cv_oo(t_ft_printf_env *e, va_list ap);

/*
**	ft_wcharlen_cor -> ft_printf/ft_print_outil_2.c
**		corrige la longeur de la wchar* en fonction de la precision
*/
size_t						ft_wcharlen_cor(wchar_t *s,
								size_t n, t_ft_printf_env *e);

/*
**	ft_cv_f_arrondi --> ft_printf/ft_print_f_5.c
**		arrondi le nombre en fonction de la precision
*/
void						ft_cv_f_arrondi(t_ft_printf_env *e, size_t nb);

/*
**	ft_cv_n -> ft_printf/ft_cv_n.c
**		effectue les processes de la convertion de type n,
**		enregistre la position current dans la variable recut.
*/
void						ft_cv_n(t_ft_printf_env *e, va_list ap);

#endif
