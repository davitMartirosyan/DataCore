NAME = datacore
CC = gcc
CC_FLAGS = #-Wall -Wextra -Werror
LINKERS = -I includes/
SRC = $(wildcard src/*.c) main.c
OBJ = $(SRC:.c=.o)
LIBRARY = libft/libft.a -lm -lreadline
HEADERS = $(wildcard includes/*.h)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CC_FLAGS) $(OBJ) -o $(NAME) $(LIBRARY) 

%.o : %.c $(HEADERS)
	$(CC) $(LINKERS) $(CC_FLAGS) -c $< -o $@

fclean: clean
	@rm -rf $(NAME)

clean:
	@rm -rf $(OBJ)

re: fclean all

git:
	@echo "Enter Commit: "
	@read message; \
	git add . && git commit -m "$$message"

.PHONNY: all re clean fclean