NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar -rc
SRCS = ft_putbasics.c ft_putaddress.c ft_puthex.c ft_printf.c\
		ft_printunsigned.c get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
		$(AR) $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re