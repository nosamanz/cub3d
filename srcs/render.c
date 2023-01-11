#include "cub3d.h"

unsigned long	rgb_to_hex(int transparent ,int r, int g, int b)//0x_00_00_ff
{
	return ((transparent << 24)+(r << 16) + (g << 8) + (b));
}

void render(t_cube *cube)
{
	int k = 0;
	int i;
	while (k != MINIMAP_HEIGHT)
	{
		i = -1;
		while (i++ != MINIMAP_WIDTH)
			cube->map_s.addr[MINIMAP_WIDTH * k + i] = rgb_to_hex(255, 0,0,0);
		k++;
	}
	draw_win(cube);
	draw_img(cube);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->win_img_ptr, 0, 0);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->map_s.img_ptr, 0, 0);
	mlx_loop(cube->mlx);
}
