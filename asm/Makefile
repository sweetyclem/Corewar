# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trichert <trichert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/13 09:01:39 by cpirlot           #+#    #+#              #
#    Updated: 2018/03/19 18:07:49 by trichert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=  asm

CC			= gcc
FLAGS		= -Wall -Werror -Wextra -g
SRC			= champ.c 		\
			compile.c		\
			instruct.c		\
 			label.c			\
			main.c			\
			op.c			\
			parse_body.c	\
			parse_header.c	\
			parse_params.c  \
			utils.c

OBJDIR		= obj
OBJ	= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))
VPATH:=src/:${VPATH}

# PROGRESS BAR
T = $(words $(OBJ))
N = 0
C = $(words $N)$(eval N := x $N)
ECHO = "[`expr $C  '*' 100 / $T`%]"

#Colors
_GREY=\x1b[30m
_RED=\x1b[31m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_BLUE=\x1b[34m
_PURPLE=\x1b[35m
_CYAN=\x1b[36m
_WHITE=\x1b[37m
_END=\x1b[0m

all: $(NAME)

$(NAME): lib $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $@ -I includes/ -L libft/ -lft
	@echo "\nAsm compilation : $(_CYAN)done$(_END)"

$(OBJDIR)/%.o: %.c
	@mkdir -p obj
	@printf "%-60b\r" "$(ECHO) $(_CYAN) Compiling $@ $(_END)"
	@$(CC) $(FLAGS) -c $< -o $@ -I includes/ -I libft/includes/

lib:
	@make -C libft/

clean:
	@$(RM) -rf $(OBJDIR)
	@make clean -C libft/
	@echo "$(_RED)clean asm:$(_END) done"

fclean: clean
	@$(RM) -f $(NAME)
	@$(RM) -f resources/players/$(NAME)
	@$(RM) -f resources/$(NAME)
	@make fclean -C libft/
	@echo "$(_RED)fclean asm:$(_END) done"

re:
	@make fclean
	@make


.PHONY: all clean fclean re
