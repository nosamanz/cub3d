#ifndef CUB3D_H
#define CUB3D_H

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

typedef struct s_mlx
{
	void *mlx;
	void *win;
} t_mlx;

typedef struct s_map
{
	int *img_addr;
	int map_width;
	int map_height;
} t_map;


typedef struct s_cube
{
	char	**map_file;
	char	**map;
	int		count;
	t_map map_s;
	t_mlx mlx_s;
} t_cube;

#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include <math.h>
#include <fcntl.h>

int		name_chck(char **av);
int		map_init(char **av, t_cube *cube);
//////////render//////////
void	render(t_cube *cube);

void	mini_map(t_cube *cube);
void	check_map_size(t_cube *cube);
#endif
