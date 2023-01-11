#include "cub3d.h"

void	init(t_cube *cube)
{
	init_win(cube);
	init_img(cube);
}

void	init_win(t_cube *cube)
{
	int	x;
	int	y;
	int	z;

	cube->mlx = mlx_init();
	cube->win = mlx_new_window(cube->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	cube->win_img_ptr = mlx_new_image(cube->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	cube->win_addr = (int *)mlx_get_data_addr(cube->win_img_ptr, &x, &y, &z);
}

void	init_img(t_cube *cube)
{
	int	x;
	int	y;
	int	z;

	cube->map_s.img_ptr = mlx_new_image(cube->mlx, MINIMAP_WIDTH, MINIMAP_HEIGHT);
	cube->map_s.addr = (int *)mlx_get_data_addr(cube->map_s.img_ptr, &x, &y, &z);
}
