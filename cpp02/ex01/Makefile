# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 11:17:51 by codespace         #+#    #+#              #
#    Updated: 2023/12/28 11:05:21 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##	Program Name
NAME 		=		fixed_point_ex01

##	Compiler and flags
COMP		=		c++
FLAGS		=		-Wall -Wextra -Werror -std=c++98 -fsanitize=address -g

## ALL FILES

SRCS		=		main.cpp	\
					Fixed.cpp

OBJS 		=		$(patsubst %.cpp,%.o,$(SRCS))

INCS		=		-I./

## RECIPES
all: $(NAME)

$(NAME): $(OBJS)
	@$(COMP) $(FLAGS) $(OBJS) $(INCS) -o $(NAME)
	@echo Program $(NAME) ready!!

$(OBJS): %.o: %.cpp
	@$(COMP) $(FLAGS) $(INCS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

git: fclean
	@git add . && git commit -m "commiting" && git push

.PHONY: clean fclean re git
