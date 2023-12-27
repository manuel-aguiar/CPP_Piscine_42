

NAME 		=		megaphone

##	Compiler and flags
COMP		=		c++
FLAGS		=		-Wall -Wextra -Werror -std=c++98 -fsanitize=address -g


## FOLDERS
INC_PATH	=		incs
SRC_PATH	=		./
OBJ_PATH	=		objs


## ALL FILES
SRC_FILES	=	megaphone.cpp


## PREP
INCS		=	-I$(INC_PATH)
SRCS		:=	$(addprefix $(SRC_PATH), $(SRC_FILES))
OBJS		:=	$(patsubst $(SRC_PATH)/%.c,$(OBJ_PATH)/%.o,$(SRCS))


## RECIPES
all: $(NAME)

$(NAME): $(OBJS)
	@$(COMP) $(FLAGS) $(OBJS) $(INCS) -o $(NAME)
	@echo Program $(NAME) ready!!

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(dir $@)
	@$(COMP) $(FLAGS) $(INCS) -c $< -o $@

clean:
	@if [ -d "$(OBJ_PATH)" ]; then \
        rm -rf $(OBJ_PATH); \
    fi
	@echo Objects successfully deleted!

fclean: clean
	@if [ -e "$(NAME)" ]; then \
        rm $(NAME); \
    fi
	@echo Done!!

re: fclean all

git: fclean
	@git add . && git commit -m "commiting" && git push

.PHONY: clean fclean re git
