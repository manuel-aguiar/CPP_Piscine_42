# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/28 16:36:42 by codespace         #+#    #+#              #
#    Updated: 2024/04/01 11:44:42 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=		diamondtrap

##	Compiler and flags
COMP		=		c++
FLAGS		=		-Wall -Wextra -Werror -std=c++98 -Wshadow -fsanitize=address -g

## FOLDERS
INC_PATH	=		incs
SRC_PATH	=		srcs
OBJ_PATH	=		objs


## ALL FILES

INC_FILES		=		ClapTrap.hpp				\
						ScavTrap.hpp				\
						FragTrap.hpp				\
						DiamondTrap.hpp

SRC_FILES		=		main.cpp					\
						ClapTrap.cpp				\
						ClapTrap_functions.cpp		\
						ScavTrap.cpp				\
						FragTrap.cpp				\
						DiamondTrap.cpp

## PREP
ALL_INCS	:=		$(addprefix $(INC_PATH)/,$(INC_FILES))

SRCS		:=		$(addprefix $(SRC_PATH)/,$(SRC_FILES)) \

OBJS 		=		$(patsubst $(SRC_PATH)/%.cpp,$(OBJ_PATH)/%.o,$(SRCS))

INCS		= 		-I$(INC_PATH)

all: $(NAME)

$(NAME): $(OBJS)
	$(COMP) $(FLAGS) $(OBJS) $(INCS) -o $(NAME)
	@echo Program $(NAME) ready!!

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp $(ALL_INCS)
	@mkdir -p $(dir $@)
	$(COMP) $(FLAGS) $(INCS) -c $< -o $@

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

run: all
	@./$(NAME)

.PHONY: clean fclean re git run
