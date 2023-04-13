CC = gcc
FLAGS = -Wall -Wextra -Werror -framework OpenGL -framework AppKit -L./minilibx -lmlx
FLAGS_FWIN = -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz
NAME = cub3d
SRCS = srcs/*.c libft/*.c

all:
#	@make -C libft
	@$(CC) $(SRCS) -o $(NAME) $(FLAGS)

windows:
	@$(CC) $(SRCS) -o $(NAME) $(FLAGS_FWIN)

clean:
#	@make clean -C libft

fclean:	clean
	@rm -rf $(NAME)
	@rm -rf $(NAME).dSYM
#	@make fclean -C libft

re: fclean all

norm:
	@norminette $(SRCS)

.PHONY: all clean fclean norm re
