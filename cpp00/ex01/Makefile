

NAME 		=		phonebook

##	Compiler and flags
COMP		=		c++
FLAGS		=		-Wall -Wextra -Werror -std=c++98 -fsanitize=address -g


## FOLDERS
INC_PATH	=		incs
SRC_PATH	=		srcs
OBJ_PATH	=		objs


## ALL FILES
SRC_FILES	=	Phonebook.cpp			\
				Contact.cpp				\
				main.cpp

## PREP

SRCS		:=		$(addprefix $(SRC_PATH)/,$(SRC_FILES))

OBJS 		=	$(patsubst $(SRC_PATH)/%.cpp,$(OBJ_PATH)/%.o,$(SRCS))

INCS		=	-I$(INC_PATH)


## RECIPES
all: $(NAME)

$(NAME): $(OBJS)
	@$(COMP) $(FLAGS) $(OBJS) $(INCS) -o $(NAME)
	@echo Program $(NAME) ready!!

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp
	mkdir -p $(dir $@)
	@echo new folder!
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

.PHONY: clean fclean re git
