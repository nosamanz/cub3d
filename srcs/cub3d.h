#ifndef CUB3D_H
#define CUB3D_H

typedef struct s_cube
{
	char **map;
	int count;
} t_cube;

#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include <math.h>
#include <fcntl.h>

int	name_chck(char **av);
int	map_init(char **av, t_cube *cube);
#endif
