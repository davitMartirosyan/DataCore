NAME = datacore
CC = gcc
CC_FLAGS = #-Wall -Wextra -Werror
LINKERS = -I includes/
SRC = $(wildcard src/*.c) main.c
OBJ = $(SRC:.c=.o)
LIB = ./libft
ARCHIVE = $(LIB)/libft.a
LIBRARY = $(LIB)/libft.a -lm -lreadline
HEADERS = $(wildcard includes/*.h)
DB = ./db
META = ./meta

all: lib $(NAME)

lib: 
	@cd $(LIB) && make

cleanlib:
	@rm -rf $(LIB)/objs $(ARCHIVE)

$(NAME) : $(OBJ)
	$(CC) $(CC_FLAGS) $(OBJ) -o $(NAME) $(LIBRARY) 

%.o : %.c $(HEADERS)
	$(CC) $(LINKERS) $(CC_FLAGS) -c $< -o $@

remove:
	@rm -rf $(DB)/*
	@rm -rf $(META)/*

fclean: clean remove
	@rm -rf $(NAME)

clean: cleanlib
	@rm -rf $(OBJ)

re: fclean all

git:
	@echo "Enter Commit: "
	@read message; \
	git add . && git commit -m "$$message" && git push

.PHONNY: all re clean fclean remove git lib