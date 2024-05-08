# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 16:42:30 by codespace         #+#    #+#              #
#    Updated: 2024/05/08 14:00:37 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=		iterators

##	Compiler and flags
COMP		=		c++
FLAGS		=		-Wall -Wextra -Werror -std=c++98 -g
FSANITIZE_FLAGS =	 -fsanitize=address -g
DEBUG_FLAGS	=		-DDEBUG_CONSTRUCTOR -DOPERATORS

## FOLDERS
INC_PATH	=		incs
TPP_PATH	=		tpp
SRC_PATH	=		srcs
OBJ_PATH	=		objs


## ALL FILES

INC_FILES 		=	GroupIterator.hpp		\
					IterFuncs.hpp			\
					FordJohnsonSort.hpp		\
					QuickSort.hpp

TPP_FILES		=	GroupIterator.tpp		\
					IterFuncs.tpp			\
					FordJohnsonSort.tpp		\
					QuickSort.tpp



SRC_FILES		=	main.cpp


## PREP
INCS		:=		$(addprefix $(INC_PATH)/,$(INC_FILES))
TPPS		:=		$(addprefix $(TPP_PATH)/,$(TPP_FILES))
SRCS		:=		$(addprefix $(SRC_PATH)/,$(SRC_FILES))
OBJS 		=		$(patsubst $(SRC_PATH)/%.cpp,$(OBJ_PATH)/%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(COMP) $(FLAGS) $(OBJS) -I$(INC_PATH) -o $(NAME)
	@echo Program $(NAME) ready!!

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp $(INCS) $(TPPS)
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
	@git add $(INCS) $(SRCS) $(TPPS) Makefile && git commit -m "commiting" && git push

run: all
	@./$(NAME)

debug: FLAGS += $(DEBUG_FLAGS)
debug: re run

fsan: FLAGS += $(FSANITIZE_FLAGS)
fsan: re run

fun: FLAGS += -D_ALL_IN
fun: re run

.PHONY: clean fclean re git run debug
