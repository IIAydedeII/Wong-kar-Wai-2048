# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/14 18:38:49 by adede             #+#    #+#              #
#    Updated: 2026/11/14 19:50:28 by adede            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# =========================================
# ANSI Escape Sequences
# =========================================

# Basic
ESC				:=	\033
RESET			:=	$(ESC)[0m

# Colors
GREEN			:=	$(ESC)[0;32m
YELLOW			:=	$(ESC)[0;33m
RED				:=	$(ESC)[0;31m
BLUE			:=	$(ESC)[0;34m

# Text Styles
BOLD			:=	$(ESC)[1m
DIM				:=	$(ESC)[2m
INVERSE			:=	$(ESC)[7m

# =========================================
# Compilation
# =========================================

NAME 			=	wong_kar_wai

CC				=	cc

LIBFT_DIR		=	libft
LIBFT			=	$(LIBFT_DIR)/libft.a

INCLUDES		=	-I ./includes -I $(LIBFT_DIR)

LIBRARIES		=	-l ncurses

MAIN			=	main.c

SRCS			=	$(addprefix src/,$(MAIN)) \
					$(addprefix src/components/,window.c)	

OBJS			=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): ${LIBFT} $(OBJS)
	@printf "$(GREEN)$(BOLD)[$(NAME)]$(RESET)"
	@printf "$(GREEN) Linking$(RESET)\n"
	@$(CC) -Wall -Werror -Wextra $(INCLUDES) $(LIBRARIES) $(OBJS) $(LIBFT) -o $@

$(LIBFT):
	@printf "$(BLUE)$(BOLD)[$(LIBFT_DIR)]$(RESET)"
	@printf "$(BLUE) Creating library$(RESET)\n"
	@$(MAKE) -s -C $(LIBFT_DIR)

%.o: %.c
	@printf "$(DIM)$(BOLD)[$(NAME)]$(RESET)"
	@printf "$(DIM) Compiling $<$(RESET)\n"
	@$(CC) -Wall -Werror -Wextra $(INCLUDES) -c $< -o $@

clean:
	@printf "$(YELLOW)Cleaning objects$(RESET)\n"
	@rm -f $(OBJS)
	@$(MAKE) -s -C $(LIBFT_DIR) clean

fclean: clean
	@printf "$(RED)Cleaning all$(RESET)\n"
	@rm -f $(NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
