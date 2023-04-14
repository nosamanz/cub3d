CC = gcc
FLAGS = -Wall -Wextra -Werror -framework OpenGL -framework AppKit -L./minilibx -lmlx
FLAGS_FWIN = -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz
NAME = cub3d
NAME_BONUS = cub3d_bonus
SRCS = mandatory/srcs/*.c mandatory/libft/*.c
SRCS_BONUS = bonus/srcs/*.c bonus/libft/*.c

all:
	@$(CC) $(SRCS) -o $(NAME) $(FLAGS)

windows:
	@$(CC) $(SRCS) -o $(NAME) $(FLAGS_FWIN)

clean:
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)

fclean:	clean
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)
	@rm -rf $(NAME).dSYM
	@rm -rf $(NAME_BONUS).dSYM

re: fclean all

bonus:
	@$(CC) $(SRCS_BONUS) -o $(NAME_BONUS) $(FLAGS)

norm:
	@norminette $(SRCS)

.PHONY: all clean fclean norm re
