NAME = pipex

NAME_BONUS = pipex

SRCS = pipex.c\
		utils.c checks.c

SRCS_BONUS = src_bonus/pipex_bonus.c\
			src_bonus/free_bonus.c \
			src_bonus/free2_bonus.c\
			src_bonus/utils2_bonus.c\
			src_bonus/utils_bonus.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra -g3 #-fsanitize=leak

INCLUDES = -I./lib -I./includes/pipex #includes buscan recursivamente

LIBS = -L./lib/ft_printf -L./lib/libft

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./lib/ft_printf
	make -C ./lib/libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -lftprintf -lft -o $(NAME)

bonus: $(OBJS_BONUS) src_bonus/pipex_bonus.h
		make -C ./lib/ft_printf
		make -C ./lib/libft
		$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBS) -lftprintf -lft -o $(NAME_BONUS)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	@make clean -C ./lib/ft_printf
	@make clean -C ./lib/libft

fclean: clean
	rm -f $(NAME)
	@make fclean -C ./lib/ft_printf
	@make fclean -C ./lib/libft

re: fclean all

.PHONY: all clean fclean re