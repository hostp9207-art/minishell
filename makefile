CC = gcc

CFLAGS = -Wall -Wextra -Werror -std=c11 -Iinclude

TARGET = minishell

SRC = src/main.c \
      src/shell.c \
      src/parser.c \
      src/builtins.c

OBJ = $(SRC:.c=.o)


all: $(TARGET)


$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJ)


fclean: clean
	rm -f $(TARGET)


re: fclean all


.PHONY: all clean fclean re