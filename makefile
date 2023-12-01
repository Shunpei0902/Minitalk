CNAME = client
SNAME = server

CC = cc
# CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address 
CSRCS = ft_client.c
SSRCS = ft_server.c
COBJS = $(CSRCS:.c=.o)
SOBJS = $(SSRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

all: $(LIBFT_LIB) $(CNAME) $(SNAME)

$(CNAME): $() $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(CSRCS) -o $(CNAME) $(LIBFT_LIB)

$(SNAME): $(SSRCS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(SSRCS) -o $(SNAME) $(LIBFT_LIB)

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(CNAME) $(SNAME)

re: fclean all

.PHONY: all clean fclean re