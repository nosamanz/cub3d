#include "cub3d.h"

void	draw_win(t_cube *cube)
{
	int	k;
	int	i;

	k = 0;
	while (k != WINDOW_HEIGHT)
	{
		i = -1;
		if (k < WINDOW_HEIGHT / 2)
		{
			while (i++ != WINDOW_WIDTH)
				cube->win_addr[WINDOW_WIDTH * k + i] = rgb_to_hex(0, 255, 191, 255);
		}
		else
		{
			while (++i != WINDOW_WIDTH)
				cube->win_addr[WINDOW_WIDTH * k + i] = rgb_to_hex(0, 120, 0, 0);
		}
		k++;
	}
}

void	draw_img(t_cube *cube)
{
	//minimap
	draw_minimap(cube);
	draw_player(cube);
	draw_ray(cube);
}
