CC = gcc
FLAGS = -framework OpenGL -framework AppKit -L./minilibx -lmlx
NAME = cub3d
SRCS = srcs/*.c libft/*.c

all:
#	@make -C libft
	@$(CC) $(SRCS) -o $(NAME) $(FLAGS)

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