# **************************************************************************** #
#											 #
#								 :::      ::::::::    #
#    Makefile						 :+:      :+:    :+:    #
#							    +:+ +:+	  +:+      #
#    By: codespace <codespace@student.42.fr>	 +#+  +:+	+#+	  #
#							+#+#+#+#+#+   +#+	     #
#    Created: 2023/12/27 11:53:05 by codespace	  #+#    #+#		#
#    Updated: 2023/12/28 15:41:23 by codespace	 ###   ########.fr	 #
#											 #
# **************************************************************************** #

NAME 		=		animals

##	Compiler and flags
COMP		=		c++
FLAGS		=		-Wall -Wextra -Werror -std=c++98 -fsanitize=address -g

## FOLDERS
INC_PATH	=		incs
SRC_PATH	=		srcs
OBJ_PATH	=		objs


## ALL FILES

INC_FILES		=		Animal.hpp		\
						Cat.hpp			\
						Dog.hpp			\
						WrongAnimal.hpp	\
						WrongCat.hpp	\
						Brain.hpp

SRC_FILES		=		main.cpp		\
						Animal.cpp		\
						Cat.cpp			\
						Dog.cpp			\
						WrongAnimal.cpp	\
						WrongCat.cpp	\
						Brain.cpp

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
