# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 11:17:51 by codespace         #+#    #+#              #
#    Updated: 2023/12/27 16:55:52 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##	Program Name
NAME 		=		harl

##	Compiler and flags
COMP		=		c++
FLAGS		=		-Wall -Wextra -Werror -std=c++98 -fsanitize=address -g

## ALL FILES

SRCS		=		main.cpp	\
					Harl.cpp

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
