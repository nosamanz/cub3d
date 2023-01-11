#include "cub3d.h"

void render(t_cube *cube)
{
	int	x;
	int	y;
	int	z;

	int i,k;

	k = 0;
	cube->mlx_s.mlx = mlx_init();
	cube->mlx_s.win = mlx_new_window(cube->mlx_s.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	cube->win_img_ptr = mlx_new_image(cube->mlx_s.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	cube->win_addr = (int *)mlx_get_data_addr(cube->win_img_ptr, &x, &y, &z);

	while (k != WINDOW_HEIGHT)
	{
		i = -1;
		if (k < WINDOW_HEIGHT / 2)
		{
			while (i++ != WINDOW_WIDTH)
				cube->win_addr[WINDOW_WIDTH * k + i] = RED_PIXEL;
		}
		else
		{
			while (i++ != WINDOW_WIDTH)
				cube->win_addr[WINDOW_WIDTH * k + i] = GREEN_PIXEL;
		}
		k++;
	}
	mlx_put_image_to_window(cube->mlx_s.mlx, cube->mlx_s.win, cube->win_img_ptr, 0, 0);
	mlx_loop(cube->mlx_s.mlx);
}
