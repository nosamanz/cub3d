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

// void	ft_draw_small_square(t_cube *cube, int x, int y, int i1, int k1, unsigned long color)
// {
// 	int i;
// 	static int	k;

// 	i = 0;
// 	i1++;
// 	k1++;
// 	while (k1 != y)
// 	{
// 		while (i < x)
// 		{
// 			cube->map_s.addr[k * MINIMAP_WIDTH + i] = color;
// 			i++;
// 		}
// 		i = 0;
// 		k++;
// 	}
// }

void ft_draw_small_square2(t_cube *cube, int x, int y, int a, int z, int color)
{
	int k = 0;
	int i;
	int temp;
	int tempz;

	tempz = z;
	temp = a;
	x = temp + x;
	y = z + y;
	i = 0;
	while (z <= y)
	{
		while (temp <= x)
		{
			if (tempz == z)
				cube->map_s.addr[z * MINIMAP_WIDTH + temp] = rgb_to_hex(0, 255, 0, 255);
			else if (temp + 1 != x)
				cube->map_s.addr[z * MINIMAP_WIDTH + temp] = color;
			else
				cube->map_s.addr[z * MINIMAP_WIDTH + temp] = rgb_to_hex(0, 255, 0, 255);
			i++;
			temp++;
		}
		i = 0;
		temp = a;
		z++;
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
	int c = 0;
	int d = 0;
	int l = 0;
	while (k != MINIMAP_HEIGHT)
	{
		while (i < MINIMAP_WIDTH)
		{
			if (cube->map[c] == NULL)
				break;
			if (cube->map[c][d] == '1')
			{
				ft_draw_small_square2(cube, x, y, i, l, GREEN_PIXEL);
			}
			else if (cube->map[c][d] == '0')
			{
				ft_draw_small_square2(cube, x, y, i, l, rgb_to_hex(0,255,255,255));
			}
			else if (cube->map[c][d] != '\n' && cube->map[c][d] != '\0')
			{
				ft_draw_small_square2(cube, x, y, i, l, rgb_to_hex(0,255,255,255));
			}
			i += x;
			d++;
		}
		d = 0;
		i = 0;
		l = y + l;
		c++;
		k++;
	}
}
