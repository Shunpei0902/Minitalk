CNAME = client
SNAME = server

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address 
CSRCS = ft_client.c
SSRCS = ft_server.c
# COBJS = $(CSRCS:.c=.o)
# SOBJS = $(SSRCS:.c=.o)

B_CNAME = client_bonus
B_SNAME = server_bonus

B_CSRCS = ft_client_bonus.c
B_SSRCS = ft_server_bonus.c
# B_COBJS = $(B_CSRCS:.c=.o)
# B_SOBJS = $(B_SSRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

all: $(LIBFT_LIB) $(CNAME) $(SNAME)

$(CNAME): $(CSRCS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(CSRCS) -o $(CNAME) $(LIBFT_LIB)

$(SNAME): $(SSRCS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(SSRCS) -o $(SNAME) $(LIBFT_LIB)

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

$(B_CNAME): $(B_CSRCS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(B_CSRCS) -o $(B_CNAME) $(LIBFT_LIB)

$(B_SNAME): $(B_SSRCS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(B_SSRCS) -o $(B_SNAME) $(LIBFT_LIB)

bonus: $(LIBFT_LIB) $(B_CNAME) $(B_SNAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(CNAME) $(SNAME) $(B_CNAME) $(B_SNAME)

re: fclean all

.PHONY: all clean fclean re