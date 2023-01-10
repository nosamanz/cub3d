#include "cub3d.h"

void render(t_cube *cube)
{
	cube->mlx_s.mlx = mlx_init();
	cube->mlx_s.win = mlx_new_window(cube->mlx_s.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	mlx_loop(cube->mlx_s.mlx);
}
