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

void ft_draw_small_square2(t_cube *cube, int x, int y, int a, int z, int color)
{
	int k = 0;
	int i;
	int temp;
	int tempz;

	tempz = z;
	temp = a;
	if (temp + x <= MINIMAP_WIDTH)
		x = temp + x;
	else
		return;
	if (z + y <= MINIMAP_HEIGHT)
		y = z + y;
	else
		return;
	i = 0;
	while (z < y)
	{
		while (temp <= x)
		{
			if (temp != x)
				cube->map_s.addr[z * MINIMAP_WIDTH + temp] = color;
			temp++;
		}
		temp = a;
		z++;
	}
	i = 0;
	// if (z + cube->map_s.mini_cub_h >= MINIMAP_HEIGHT && a + cube->map_s.mini_cub_w >= MINIMAP_WIDTH)
	// {
	// 	printf("slm\n");
	// 	z--;
	// 	while (i <= MINIMAP_WIDTH)
	// 	{
	// 		printf("aaaaaaa%d\n", i);
	// 		cube->map_s.addr[z * MINIMAP_WIDTH + temp] = rgb_to_hex(0, 0, 0, 0);
	// 		i++;
	// 	}
	// }
}

void	draw_img(t_cube *cube)
{
	int	i;
	int i2;
	int	k;
	int j;

	//minimap
	int x  = MINIMAP_WIDTH / cube->map_s.map_width;
	cube->map_s.mini_cub_w = x;
	printf("x%d = WIDTH:%d / %d\n", x ,MINIMAP_WIDTH, cube->map_s.map_width);
	int y = MINIMAP_HEIGHT / cube->map_s.map_height;
	cube->map_s.mini_cub_h = y;
	printf("y%d = HEIGHT:%d / %d\n", y, MINIMAP_HEIGHT, cube->map_s.map_height);
	k = 0;
	j = 0;
	i = 0;
	while (k != MINIMAP_HEIGHT)
	{
		i = -1;
		while (++i < MINIMAP_WIDTH)
			cube->map_s.addr[MINIMAP_WIDTH * k + i] = rgb_to_hex(255, 0, 0, 0);
		k++;
	}
	i = 0;
	k = 0;
	int c = 0;
	int d = 0;
	int l = 0;
	while (l < MINIMAP_HEIGHT)
	{
		while (d < cube->map_s.map_width)
		{
			if (cube->map[c] == NULL)
				break;
			if (cube->map[c][d] == '1')
			{
				ft_draw_small_square2(cube, x, y, i, l, rgb_to_hex(0,0,0,0));
			}
			else if (cube->map[c][d] == '0')
			{
				ft_draw_small_square2(cube, x, y, i, l, rgb_to_hex(0,255,255,255));
			}
			else if (cube->map[c][d] != '\n' && cube->map[c][d] != '\0')
			{
				ft_draw_small_square2(cube, x, y, i, l, rgb_to_hex(0,255,255,255));
			}
			//cube->map_s.addr[k * MINIMAP_WIDTH + i] = rgb_to_hex(0, 0, 0, 255);
			i += x;
			//i++;
			d++;
		}
		d = 0;
		i = 0;
		l = y + l;
		c++;
		k++;
	}
}
