NAME := libftprintf.a
SRC := ft_printf.c
OBJ := $(SRC:%.c=%.o)
CC := cc
CFLAGS := -Wall -Wextra -Werror
HEADER := ft_printf.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -include $(HEADER) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
