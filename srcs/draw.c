#include "cub3d.h"

void	draw_win(t_cube *cube)
{
	int	k;
	int	i;

	k = 0;
	while (k != cube->win_height)
	{
		i = -1;
		if (k < cube->win_height / 2)
		{
			while (i++ != cube->win_width)
				// cube->win_addr[cube->win_width * k + i] = rgb_to_hex(100, 255, 191, 255);
				cube->win_addr[cube->win_width * k + i] = rgb_to_hex(0, cube->c_color[0], cube->c_color[1], cube->c_color[2]);
		}
		else
		{
			while (++i != cube->win_width)
				// cube->win_addr[cube->win_width * k + i] = rgb_to_hex(0, 120, 0, 0);
				cube->win_addr[cube->win_width * k + i] = rgb_to_hex(0, cube->f_color[0], cube->f_color[1], cube->f_color[2]);
		}
		k++;
	}
	// k = 0;

	// tran.
	// while (k != cube->map_s.map_height)
	// {
	// 	i = -1;
	// 	while (++i < cube->map_s.map_width)
	// 		cube->win_addr[cube->win_width * k + i] = rgb_to_hex(255, 0, 0, 0);
	// 	k++;
	// }
}

void	draw_img(t_cube *cube)
{
	//minimap
	draw_minimap(cube);
	draw_player(cube);
	draw_ray(cube);
}
