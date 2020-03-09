# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skennith <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/27 16:37:07 by skennith          #+#    #+#              #
#    Updated: 2020/01/23 21:04:34 by skennith         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC_DIR = ./srcs/

SRC = algorithm.c \
		create_list.c \
		figures.c \
		fillit.c \
		main.c \
		validation.c

SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJ = $(SRC:.c=.o)
OBJ_DIR = ./obj/
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

INC = fillit.h
INC_DIR = ./includes/
INCS = $(addprefix $(INC_DIR), $(INC))

LIB_OBJ = *.o
LIB_OBJ_DIR = ./libft/obj/
LIB_OBJS = $(addprefix $(LIB_OBJ_DIR), $(LIB_OBJ))
LIB_SRC_DIR = ./libft/srcs/
LIB_INC = libft.h get_next_line.h
LIB_INC_DIR = ./libft/includes/
LIB_INCS = $(addprefix $(LIB_INC_DIR), $(LIB_INC))

FLAGS = -g -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIB_INC_DIR)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(LIB_OBJS) $(OBJS)
		@gcc $(OBJS) ./libft/libft.a -o $(NAME)

$(OBJ_DIR):
		@mkdir -p $@
		@mkdir -p $(LIB_OBJ_DIR)

$(LIB_OBJ_DIR)%.o: $(LIB_SRC_DIR)%.c $(LIB_INCS)
		@make -C libft

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS)
		gcc $(FLAGS) -o $@ -c $<

clean:
		@make clean -C libft
		@rm -f $(OBJS)
		@rm -rf $(OBJ_DIR)

fclean: clean
		@make fclean -C libft
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
