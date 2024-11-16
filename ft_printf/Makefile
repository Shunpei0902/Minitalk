NAME = libftprintf.a
SRC = ./ft_printf.c ./ft_put.c ./ft_putnbr_hex.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRC:.c=.o)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all