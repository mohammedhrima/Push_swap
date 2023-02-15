# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhrima <mhrima@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 20:55:22 by mhrima            #+#    #+#              #
#    Updated: 2023/02/15 21:30:10 by mhrima           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra # don't forget flags
NAME = ./push_swap
NAME_BONUS = ./checker
RM = rm -rf

LIB = ./Libft/libft.a
SRCS = mandatory/push_swap.c mandatory/three_sorting.c mandatory/five_sorting.c \
	   mandatory/more_than_five_sorting1.c  mandatory/more_than_five_sorting2.c

SRC_BONUS = bonus/checker.c

SRCS_UTILS = utils/utils.c utils/checking.c utils/moves.c

SRCS_PARSING = parsing/parsing.c

OBJS =  push_swap.o three_sorting.o five_sorting.o \
	   more_than_five_sorting1.o  more_than_five_sorting2.o

OBJ_BONUS = checker.o

OBJS_UTILS = utils.o checking.o moves.o

OBJS_PARSING = parsing.o

all: $(NAME)
bonus: $(NAME_BONUS)

$(OBJS):$(SRCS)
	@echo compilling $(SRCS)
	@$(CC) $(CFLAGS) -c $(SRCS)

$(OBJ_BONUS):$(SRC_BONUS)
	@echo compilling $(SRC_BONUS)
	@$(CC) $(CFLAGS) -c $(SRC_BONUS)

$(OBJS_UTILS):$(SRCS_UTILS)
	@echo compilling $(SRCS_UTILS)
	@$(CC) $(CFLAGS) -c $(SRCS_UTILS)


$(OBJS_PARSING):$(SRCS_PARSING)
	@echo compilling $(SRCS_PARSING)
	@$(CC) $(CFLAGS) -c $(SRCS_PARSING)

$(NAME): $(OBJS) $(OBJS_UTILS) $(OBJS_PARSING) $(LIB)
	@echo compilling $(NAME)
	@$(CC) $(CFLAGS) $(LIB) $(OBJS) $(OBJS_UTILS) $(OBJS_PARSING) -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS) $(OBJS_UTILS) $(OBJS_PARSING) $(LIB)
	@echo compilling $(NAME_BONUS)
	@$(CC) $(CFLAGS) $(LIB) $(OBJ_BONUS) $(OBJS_UTILS) $(OBJS_PARSING) -o $(NAME_BONUS)

clean:
	@echo removing $(OBJS) $(OBJ_BONUS) $(OBJS_UTILS) $(OBJS_PARSING) 
	@$(RM) $(OBJS) $(OBJ_BONUS) $(OBJS_UTILS) $(OBJS_PARSING) 

fclean: clean
	@echo removing $(NAME) $(NAME_BONUS) 
	@$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

