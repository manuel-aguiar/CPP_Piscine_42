# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/28 16:01:53 by codespace         #+#    #+#              #
#    Updated: 2024/01/10 15:22:07 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=		zombies

##	Compiler and flags
COMP		=		c++
FLAGS		=		-Wall -Wextra -Werror -std=c++98 -fsanitize=address -g

## FOLDERS
INC_PATH	=		incs
SRC_PATH	=		srcs
OBJ_PATH	=		objs


## ALL FILES
INC_FILES	=		Zombie.h			\
					Zombie.hpp

SRC_FILES	=		main.cpp			\
					Zombie.cpp			\
					newZombie.cpp		\
					randomChump.cpp

## PREP

INCS		:=		$(addprefix $(INC_PATH)/,$(INC_FILES))

SRCS		:=		$(addprefix $(SRC_PATH)/,$(SRC_FILES))

OBJS 		=		$(patsubst $(SRC_PATH)/%.cpp,$(OBJ_PATH)/%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	@$(COMP) $(FLAGS) $(OBJS) -I$(INC_PATH) -o $(NAME)
	@echo Program $(NAME) ready!!

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp $(INCS)
	@mkdir -p $(dir $@)
	@$(COMP) $(FLAGS) -I$(INC_PATH) -c $< -o $@

clean:
	@if [ -d "$(OBJ_PATH)" ]; then \
	 rm -rf $(OBJ_PATH); \
    fi

fclean: clean
	@if [ -e "$(NAME)" ]; then \
	 rm $(NAME); \
    fi

re: fclean all

git: fclean
	@git add . && git commit -m "commiting" && git push

run: re
	@./$(NAME)

.PHONY: clean fclean re git run
