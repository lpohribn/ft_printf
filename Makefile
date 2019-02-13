# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/01 16:55:56 by lpohribn          #+#    #+#              #
#    Updated: 2018/05/01 16:56:02 by lpohribn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRC_DIR		=	./src/
OBJ_DIR		=	./obj/
INC_DIR		=	./inc/

HEADER		=	$(INC_DIR)ft_printf.h

SRC			=	ft_printf.c \
				ft_parse_type.c \
				ft_parse_spec.c\
				ft_digit.c \
				ft_char.c \
				ft_string.c \
				ft_wstring.c \
				ft_uxop.c \
				ft_unicode.c\
				ft_width_n_prec_d.c \
				ft_color.c \
				ft_n_k_star.c \
				ft_putresult.c

OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

FLAGS		=	-Wall -Werror -Wextra

HEAD_FLAGS	=	-I $(INC_DIR)

CC			=	gcc

all: $(NAME)
	
$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o : %.c $(HEADER)
	$(CC) -c $< -o $@ $(FLAGS) $(HEAD_FLAGS)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(OBJ_DIR)

re : fclean all

vpath %.c $(SRC_DIR)
