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
				cube->win_addr[cube->win_width * k + i] = rgb_to_hex(0, cube->c_color[0], cube->c_color[1], cube->c_color[2]);
		}
		else
		{
			while (++i != cube->win_width)
				cube->win_addr[cube->win_width * k + i] = rgb_to_hex(0, cube->f_color[0], cube->f_color[1], cube->f_color[2]);
		}
		k++;
	}
}

void	draw_img(t_cube *cube)
{
	//minimap
	if (cube->m == true)
		draw_trans_map(cube);
	else
	{
		draw_minimap(cube);
		draw_player(cube);
	}
	draw_ray_and_3d(cube);
}
