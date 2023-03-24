#include "cub3d.h"

void	init(t_cube *cube)
{
	init_win(cube);
	init_img(cube);

	cube->w = false;
	cube->a = false;
	cube->s = false;
	cube->d = false;
	cube->ra = false;
	cube->la = false;
}

void	init_win(t_cube *cube)
{
	int	x;
	int	y;
	int	z;

	cube->mlx = mlx_init();
	cube->win = mlx_new_window(cube->mlx, cube->win_width, cube->win_height, "cub3d");
	cube->win_img_ptr = mlx_new_image(cube->mlx, cube->win_width, cube->win_height);
	cube->win_addr = (int *)mlx_get_data_addr(cube->win_img_ptr, &x, &y, &z);
}

void	init_img(t_cube *cube)
{
	int	x;
	int	y;
	int	z;

	cube->map_s.img_ptr = mlx_new_image(cube->mlx, cube->map_s.map_width, cube->map_s.map_height);
	cube->map_s.addr = (int *)mlx_get_data_addr(cube->map_s.img_ptr, &x, &y, &z);

}
