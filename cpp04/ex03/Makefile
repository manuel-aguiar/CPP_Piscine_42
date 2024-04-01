# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 16:42:30 by codespace         #+#    #+#              #
#    Updated: 2024/04/01 11:51:08 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=		materia

##	Compiler and flags
COMP		=		c++
FLAGS		=		-Wall -Wextra -Werror -std=c++98 -fsanitize=address -g

## FOLDERS
INC_PATH	=		incs
SRC_PATH	=		srcs
OBJ_PATH	=		objs


## ALL FILES

INC_FILES		=		AMateria.hpp		\
						Character.hpp		\
						Cure.hpp			\
						Ice.hpp				\
						ICharacter.hpp		\
						IMateriaSource.hpp	\
						MateriaSource.hpp


SRC_FILES		=		main.cpp			\
						AMateria.cpp		\
						Ice.cpp				\
						Cure.cpp			\
						Character.cpp		\
						MateriaSource.cpp


## PREP
INCS		:=		$(addprefix $(INC_PATH)/,$(INC_FILES))
SRCS		:=		$(addprefix $(SRC_PATH)/,$(SRC_FILES))
OBJS 		=		$(patsubst $(SRC_PATH)/%.cpp,$(OBJ_PATH)/%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(COMP) $(FLAGS) $(OBJS) -I$(INC_PATH) -o $(NAME)
	echo Program $(NAME) ready!!

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp $(INCS)
	mkdir -p $(dir $@)
	$(COMP) $(FLAGS) -I$(INC_PATH) -c $< -o $@

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
