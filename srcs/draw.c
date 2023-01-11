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
			while (i++ != WINDOW_WIDTH)
				cube->win_addr[WINDOW_WIDTH * k + i] = rgb_to_hex(0, 120, 0, 0);
		}
		k++;
	}
}

void	draw_img(t_cube *cube)
{
	int	i;
	int i2;
	int	k;
	int j;

	//minimap
	int x  = MINIMAP_WIDTH / cube->map_s.map_width;
	printf("x%d = WIDTH:%d / %d\n", x ,MINIMAP_WIDTH, cube->map_s.map_width);
	int y = MINIMAP_HEIGHT / cube->map_s.map_height;
	printf("y%d = HEIGHT:%d / %d\n", y, MINIMAP_HEIGHT, cube->map_s.map_height);
	//printf("x:%d y:%d\n", x,y);
	k = 0;
	j = 0;
	i = 0;
	while (k != MINIMAP_HEIGHT)
	{
		i = -1;
		while (i++ < MINIMAP_WIDTH)
			cube->map_s.addr[MINIMAP_WIDTH * k + i] = rgb_to_hex(255, 0, 0, 0);
		k++;
	}
	i = 0;
	k = 0;
	int a = 0;


	int i3 = 0;
	// while (cube->map[i])
	// {
		j = 0;
		// while (cube->map[i][j])
		// {
			while (k != x * y)
			{
				i2 = -1;
				while (i2++ < x)
				{
					if (cube->map[i][j] == '1')
					{
						while ()
						cube->map_s.addr[x * k + i2] = rgb_to_hex(0, 0, 190, 0);
						j++;
					}
					else
					{
						cube->map_s.addr[x * k + i2] = rgb_to_hex(0, 255, 0, 0);
						j++;
					}
					i3 = 0;
				}
				k++;
				if (k % x == 0)
					i++;
			}
		//}
		i++;
	//}
}
