# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 11:05:55 by apopinea          #+#    #+#              #
#    Updated: 2018/03/05 14:40:21 by apopinea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean, fclean, re, $(NAME), ree

.SUFFIXES:

DIR_SH_GENERAL = modules/

########### char ###################
DIR_CHAR =		$(DIR_SH_GENERAL)char/
DIR_S_CHAR = 	$(DIR_CHAR)srcs/
DIR_H_CHAR = 	$(DIR_CHAR)includes/
HEADER_CHAR = 	lchar.h			\
				p_lchar.h

SRCS_CHAR =		ft_char_cmp_nocase.c 	\
				ft_isalnum.c 			\
				ft_isalpha.c 			\
				ft_isascii.c 			\
				ft_isdigit.c 			\
				ft_isprint.c			\
				ft_tolower.c 			\
				ft_toupper.c

########### ft_printf ###############
DIR_FT_PRINTF = 	$(DIR_SH_GENERAL)ft_printf/
DIR_S_FT_PRINTF =	$(DIR_FT_PRINTF)srcs/
DIR_H_FT_PRINTF = 	$(DIR_FT_PRINTF)includes/
HEADER_FT_PRINTF =	ft_printf.h 		\
					p_ft_printf.h

SRCS_FT_PRINTF =	ft_printf.c 				\
					ft_printf2.c 				\
					ft_init_tab.c 				\
					ft_pars_arg.c 				\
					ft_capt_flag_attribut.c 	\
					ft_capt_flag_width.c 		\
					ft_capt_flag_prec.c 		\
					ft_capt_flag_mod.c 			\
					ft_capt_flag_cv.c 			\
					ft_cv_di.c 					\
					ft_cv_di_2.c 				\
					ft_cv_di_3.c 				\
					ft_cv_di_4.c 				\
					ft_print_outil.c			\
					ft_print_outil_2.c			\
					ft_print_di.c				\
					ft_print_di_2.c				\
					ft_print_di_3.c				\
					ft_print_di_spe.c			\
					ft_print_di_spe_2.c			\
					ft_print_di_spe_3.c			\
					ft_cv_err.c 				\
					ft_cv_s.c 					\
					ft_cv_s_2.c 				\
					ft_print_s.c 				\
					ft_print_s_spe.c 			\
					ft_cv_f.c 					\
					ft_cv_f_2.c 				\
					ft_cv_f_3.c 				\
					ft_print_f.c 				\
					ft_print_f_2.c 				\
					ft_print_f_3.c 				\
					ft_print_f_4.c 				\
					ft_print_f_5.c 				\
					ft_print_f_spe.c 			\
					ft_print_f_spe_2.c 			\
					ft_print_f_spe_3.c 			\
					ft_print_f_spe_4.c 			\
					ft_print_f_spe_5.c 			\
					ft_cv_e.c 					\
					ft_cv_e_2.c 				\
					ft_cv_e_3.c 				\
					ft_print_e.c 				\
					ft_print_e_2.c 				\
					ft_print_e_3.c 				\
					ft_print_e_4.c 				\
					ft_print_e_5.c				\
					ft_cv_c.c 					\
					ft_cv_c_2.c 				\
					ft_print_c.c 				\
					ft_cv_p.c 					\
					ft_cv_p_2.c 				\
					ft_cv_p_3.c 				\
					ft_print_p.c 				\
					ft_print_p_2.c 				\
					ft_cv_x.c 					\
					ft_cv_x_2.c 				\
					ft_cv_x_3.c 				\
					ft_print_x.c 				\
					ft_print_x_2.c 				\
					ft_cv_b.c 					\
					ft_cv_b_2.c 				\
					ft_print_b.c 				\
					ft_print_b_2.c 				\
					ft_cv_cc.c 					\
					ft_cv_cc_2.c 				\
					ft_print_cc.c 				\
					ft_print_cc_2.c 			\
					ft_cv_ss.c 					\
					ft_cv_ss_2.c 				\
					ft_print_ss.c 				\
					ft_cv_u.c 					\
					ft_cv_u_2.c 				\
					ft_cv_u_3.c 				\
					ft_cv_uu.c 					\
					ft_cv_dd.c 					\
					ft_cv_xx.c 					\
					ft_cv_mod.c 				\
					ft_cv_ee.c 					\
					ft_cv_o.c 					\
					ft_cv_o_2.c 				\
					ft_cv_o_3.c 				\
					ft_print_o.c 				\
					ft_print_o_2.c 				\
					ft_cv_oo.c 					\
					ft_cv_n.c

############ ft_prtl #############
DIR_FT_PRTL = $(DIR_SH_GENERAL)ft_prtl/
DIR_S_FT_PRTL = $(DIR_FT_PRTL)srcs/
DIR_H_FT_PRTL = $(DIR_FT_PRTL)includes/
HEADER_FT_PRTL	=	ft_prtl.h			\
					p_ft_prtl.h

SRCS_FT_PRTL =	ft_prtl.c 				\
				prtl_sfduee.c 			\
				prtl_cn0rrff.c 			\
				prtl_tl.c 				\
				prtl_llccssierror.c 	\
				ft_init_tabm.c

########### liste ##############
DIR_LST = $(DIR_SH_GENERAL)lst/
DIR_S_LST = $(DIR_LST)srcs/
DIR_H_LST = $(DIR_LST)includes/
HEADER_LST =	lst.h		\
				p_lst.h

SRCS_LST =	ft_lst_push_back.c 		\
			ft_lst_push_sort.c 		\
			ft_lstnew.c 			\
			ft_lstdelone.c 			\
			ft_lstdel.c 			\
			ft_lst_len.c			\
			ft_lst_push_front.c		\
			ft_lstiter.c 			\
			ft_lstmap.c

########## main ############
DIR_MAIN = $(DIR_SH_GENERAL)main/
DIR_S_MAIN = $(DIR_MAIN)srcs/
DIR_H_MAIN = $(DIR_MAIN)includes/
HEADER_MAIN =	lmain.h		\
				p_lmain.h

SRCS_MAIN = 	ft_getstr.c

############# matrix ##############
DIR_MATRIX = $(DIR_SH_GENERAL)matrix/
DIR_S_MATRIX = $(DIR_MATRIX)srcs/
DIR_H_MATRIX = $(DIR_MATRIX)includes/
HEADER_MATRIX =	matrix.h 	\
				p_matrix.h

SRCS_MATRIX = 	ft_cre_matrix.c 			\
				ft_print_matrix.c 			\
				ft_opera_matrix.c 			\
				ft_mult_matrix.c 			\
				ft_del_matrix.c 			\
				ft_resize_matrix.c 			\
				ft_det_matrix.c 			\
				ft_dup_matrix.c 			\
				ft_com_matrix.c 			\
				ft_nb_mult_matrix.c 		\
				ft_invers_matrix.c 			\
				ft_div_matrix.c

############## memory #############
DIR_MEMORY = $(DIR_SH_GENERAL)memory/
DIR_S_MEMORY = $(DIR_MEMORY)srcs/
DIR_H_MEMORY = $(DIR_MEMORY)includes/
HEADER_MEMORY =	memory.h 		\
				p_memory.h

SRCS_MEMORY =	ft_memset.c 		\
				ft_bzero.c 			\
				ft_memcpy.c 		\
				ft_rememalloc.c 	\
				ft_memdup.c 		\
				ft_memdel.c 		\
				ft_memmove.c 		\
				ft_memchr.c 		\
				ft_memcmp.c 		\
				ft_memccpy.c 		\
				ft_memalloc.c 		\

############## nombre #############
DIR_NOMBRE = $(DIR_SH_GENERAL)nombre/
DIR_S_NOMBRE = $(DIR_NOMBRE)srcs/
DIR_H_NOMBRE = $(DIR_NOMBRE)includes/
HEADER_NOMBRE =	nombre.h 		\
				p_nombre.h

SRCS_NOMBRE =	ft_atoi.c 			\
				ft_atof.c 			\
				ft_abs.c 			\
				ft_pow.c 			\
				ft_atoi_base.c

############## put_x ###############
DIR_PUT_X = $(DIR_SH_GENERAL)put_x/
DIR_S_PUT_X = $(DIR_PUT_X)srcs/
DIR_H_PUT_X = $(DIR_PUT_X)includes/
HEADER_PUT_X =	put_x.h 		\
				p_put_x.h

SRCS_PUT_X	=	ft_putbuf_fd.c 				\
				ft_putbuf_itoa_base_fd.c	\
				ft_putbuf_itoa_fd_1.c 		\
				ft_putbuf_itoa_fd_2.c 		\
				ft_putbuf_loop_fd.c 		\
				ft_putbuf_mm_fd_np.c		\
				ft_putchar_fd.c 			\
				ft_putchar.c 				\
				ft_putendl_fd.c 			\
				ft_putendl.c 				\
				ft_putfloat.c 				\
				ft_putnbr_fd.c 				\
				ft_putnbr_long.c 			\
				ft_putnbr.c					\
				ft_putnbuf_fd_np.c 			\
				ft_putstr_fd.c 				\
				ft_putstr.c 				\
				ft_write_buf.c

############## Strings ############
DIR_STR = $(DIR_SH_GENERAL)string/
DIR_S_STR = $(DIR_STR)srcs/
DIR_H_STR = $(DIR_STR)includes/
HEADER_STR =	str.h 		\
				p_str.h

SRCS_STR =		ft_cmpt_chr.c 			\
				ft_get_line.c 			\
				ft_itoa.c 				\
				ft_itoa2.c 				\
				ft_low_case.c			\
				ft_print_next_line.c	\
				ft_scitoa.c 			\
				ft_str_next_line.c		\
				ft_itoa_base.c			\
				ft_strcat.c 			\
				ft_strchr.c 			\
				ft_strchr_replace.c 	\
				ft_strcmp.c 			\
				ft_strclr.c 			\
				ft_strcpy.c 			\
				ft_strdel.c 			\
				ft_strdup.c 			\
				ft_striter.c 			\
				ft_striteri.c 			\
				ft_strjoin.c 			\
				ft_strlcat.c 			\
				ft_strlen.c 			\
				ft_strmap.c 			\
				ft_strmapi.c 			\
				ft_strncat.c 			\
				ft_strncmp.c 			\
				ft_strncpy.c 			\
				ft_strnew.c 			\
				ft_strnjoin.c 			\
				ft_strnstr.c 			\
				ft_strrchr.c 			\
				ft_strscut.c 			\
				ft_strsplit.c 			\
				ft_strsplit_buf.c 		\
				ft_strstr.c 			\
				ft_strsub.c 			\
				ft_strswap.c 			\
				ft_strtrim.c			\
				ft_tabscpy.c			\
				ft_up_case.c

############## sys_files ############
DIR_SYS_FILES = $(DIR_SH_GENERAL)sys_files/
DIR_S_SYS_FILES = $(DIR_SYS_FILES)srcs/
DIR_H_SYS_FILES = $(DIR_SYS_FILES)includes/
HEADER_SYS_FILES = 	sys_files.h 			\
					p_sys_files.h

SRCS_SYS_FILES =	ft_base_name.c 				\
					ft_compare_file.c 			\
					ft_compare_text.c 			\
					ft_get_n_line.c				\
					ft_get_tab_line.c			\
					ft_init_path.c 				\
					ft_join_path.c 				\
					ft_mkdir_1.c				\
					ft_mkdir_2.c				\
					ft_mkdir_free.c				\
					ft_open_file.c 				\
					ft_rm.c

############## utilities ############
DIR_UTILITIES = $(DIR_SH_GENERAL)utilities/
DIR_S_UTILITIES = $(DIR_UTILITIES)srcs/
DIR_H_UTILITIES = $(DIR_UTILITIES)includes/
HEADER_UTILITIES = 	lutil.h 			\
					p_lutil.h

SRCS_UTILITIES =	es_ft.c 			\
					ft_auth_char.c 		\
					ft_change_ext.c 	\
					ft_error_r.c 		\
					ft_lpause.c 		\
					ft_pprtl.c 			\
					ft_success.c 		\
					ft_xx_is.c

NAME = libftprintf.a

OPT_H = -I

DIR_HEADER_G =	common_inc/
DIR_HEADER_G2 =	common_inc_p/

HEADER_G =		$(DIR_HEADER_G2)p_common_inc.h	\
				$(DIR_HEADER_G)error_str.h 		\
				$(DIR_HEADER_G)libft_com.h

DIR_HEADER_SPE = $(DIR_H_CHAR)
DIR_HEADER_SPE += $(DIR_H_FT_PRINTF)
DIR_HEADER_SPE += $(DIR_H_FT_PRTL)
DIR_HEADER_SPE += $(DIR_H_LST)
DIR_HEADER_SPE += $(DIR_H_MAIN)
DIR_HEADER_SPE += $(DIR_H_MATRIX)
DIR_HEADER_SPE += $(DIR_H_MEMORY)
DIR_HEADER_SPE += $(DIR_H_NOMBRE)
DIR_HEADER_SPE += $(DIR_H_PUT_X)
DIR_HEADER_SPE += $(DIR_H_STR)
DIR_HEADER_SPE += $(DIR_H_SYS_FILES)
DIR_HEADER_SPE += $(DIR_H_UTILITIES)

DIR_H_TT_TMP = $(DIR_HEADER_G)
DIR_H_TT_TMP += $(DIR_HEADER_G2)
DIR_H_TT_TMP += $(DIR_HEADER_SPE)
DIR_H_TT = $(addprefix $(OPT_H), $(DIR_H_TT_TMP))

HEADER_SPE 	= $(addprefix $(DIR_H_CHAR), $(HEADER_CHAR))
HEADER_SPE 	+= $(addprefix $(DIR_H_FT_PRINTF), $(HEADER_FT_PRINTF))
HEADER_SPE 	+= $(addprefix $(DIR_H_FT_PRTL), $(HEADER_FT_PRTL))
HEADER_SPE 	+= $(addprefix $(DIR_H_LST), $(HEADER_LST))
HEADER_SPE 	+= $(addprefix $(DIR_H_MAIN), $(HEADER_MAIN))
HEADER_SPE 	+= $(addprefix $(DIR_H_MATRIX), $(HEADER_MATRIX))
HEADER_SPE 	+= $(addprefix $(DIR_H_MEMORY), $(HEADER_MEMORY))
HEADER_SPE 	+= $(addprefix $(DIR_H_NOMBRE), $(HEADER_NOMBRE))
HEADER_SPE 	+= $(addprefix $(DIR_H_PUT_X), $(HEADER_PUT_X))
HEADER_SPE 	+= $(addprefix $(DIR_H_STR), $(HEADER_STR))
HEADER_SPE 	+= $(addprefix $(DIR_H_SYS_FILES), $(HEADER_SYS_FILES))
HEADER_SPE 	+= $(addprefix $(DIR_H_UTILITIES), $(HEADER_UTILITIES))

H_TT = $(HEADER_G)
H_TT += $(HEADER_SPE)

SRCS = $(addprefix $(DIR_S_CHAR), $(SRCS_CHAR))
SRCS += $(addprefix $(DIR_S_FT_PRINTF), $(SRCS_FT_PRINTF))
SRCS += $(addprefix $(DIR_S_FT_PRTL), $(SRCS_FT_PRTL))
SRCS += $(addprefix $(DIR_S_LST), $(SRCS_LST))
SRCS += $(addprefix $(DIR_S_MAIN), $(SRCS_MAIN))
SRCS += $(addprefix $(DIR_S_MATRIX), $(SRCS_MATRIX))
SRCS += $(addprefix $(DIR_S_MEMORY), $(SRCS_MEMORY))
SRCS += $(addprefix $(DIR_S_NOMBRE), $(SRCS_NOMBRE))
SRCS += $(addprefix $(DIR_S_PUT_X), $(SRCS_PUT_X))
SRCS += $(addprefix $(DIR_S_STR), $(SRCS_STR))
SRCS += $(addprefix $(DIR_S_SYS_FILES), $(SRCS_SYS_FILES))
SRCS += $(addprefix $(DIR_S_UTILITIES), $(SRCS_UTILITIES))

SROS = $(SRCS:.c=.o)
SRDS = $(SRCS:.c=.d)

FLAG = -Wall -Werror -Wextra -MMD
CC = gcc

all: $(NAME)

$(NAME): $(SROS)
	@ar rc $(NAME) $(SROS)
	@ranlib $(NAME)
	@echo "\033[1m\033[32mSuccess : \033[0m compilation \033[33m\033[1mlibft.a\033[0m\n"

%.o: %.c
	@$(CC) $(FLAG) -o $@ -c $< $(DIR_H_TT)
	@echo "\033[32m\033[1m[OK]\033[0m " $(notdir $<)


clean:
	@rm -f $(SROS) $(SRDS)
	@echo "\033[1m\033[31msuppression libft *.o\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1m\033[31msuppression libftprintf.a\033[0m"

re: fclean all

ree: re
	@rm -f $(SROS) $(SRDS)
	@echo "\033[1m\033[31msuppression libft *.o\033[0m"

-include $(SROS:.o=.d)
