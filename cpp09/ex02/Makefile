# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 16:42:30 by codespace         #+#    #+#              #
#    Updated: 2024/05/02 12:04:56 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=		PmergeMe

##	Compiler and flags
COMP		=		c++
FLAGS		=		-Wall -Wextra -Werror -std=c++98
FSANITIZE_FLAGS =	 -fsanitize=address -g
DEBUG_FLAGS	=		-DDEBUG_CONSTRUCTOR -DOPERATORS

## FOLDERS
INC_PATH	=		incs
SRC_PATH	=		srcs
OBJ_PATH	=		objs


## ALL FILES

INC_FILES		=	PmergeMe.hpp		\
					MergeInsertComp.hpp



SRC_FILES		=	main.cpp		\
					PmergeMe.cpp	\
					globals.cpp



## PREP
INCS		:=		$(addprefix $(INC_PATH)/,$(INC_FILES))
SRCS		:=		$(addprefix $(SRC_PATH)/,$(SRC_FILES))
OBJS 		=		$(patsubst $(SRC_PATH)/%.cpp,$(OBJ_PATH)/%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(COMP) $(FLAGS) $(OBJS) -I$(INC_PATH) -o $(NAME)
	@echo Program $(NAME) ready!!

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

git:
	@git add $(INCS) $(SRCS) Makefile cpp09_ex02_notes.txt && git commit -m "commiting" && git push

run: all
	@./$(NAME)

debug: FLAGS += $(DEBUG_FLAGS)
debug: re run

fsan: FLAGS += $(FSANITIZE_FLAGS)
fsan: re run

.PHONY: clean fclean re git run debug
