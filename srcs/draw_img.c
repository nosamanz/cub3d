#include "cub3d.h"

void ft_draw_small_square(t_cube *cube, int x, int y, int a, int z, int color)
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
}

void ft_draw_small_square2(t_cube *cube, int x, int y, int a, int z, int color)
{
	int k = 0;
	int i;
	int temp;
	int tempz;

	tempz = z;
	temp = a;
	if (temp + x <= MINIMAP_WIDTH / 4)
		x = temp + x;
	else
		return;
	if (z + y <= MINIMAP_HEIGHT / 4)
		y = z + y;
	else
		return;
	i = 0;
	while (z < y)
	{
		while (temp <= x)
		{
			if (temp != x)
				cube->map_s.player_addr[z * MINIMAP_WIDTH + temp] = color;
			temp++;
		}
		temp = a;
		z++;
	}
}

void	draw_minimap(t_cube *cube)
{
	int	i;
	int	k;
	int j;
	int x  = MINIMAP_WIDTH / cube->map_s.map_width;
	cube->map_s.mini_cub_w = x;
	//printf("x%d = WIDTH:%d / %d\n", x ,MINIMAP_WIDTH, cube->map_s.map_width);
	int y = MINIMAP_HEIGHT / cube->map_s.map_height;
	cube->map_s.mini_cub_h = y;
	//printf("y%d = HEIGHT:%d / %d\n", y, MINIMAP_HEIGHT, cube->map_s.map_height);
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
				ft_draw_small_square(cube, x, y, i, l, rgb_to_hex(0,0,0,0));
			}
			else if (cube->map[c][d] == '0')
			{
				ft_draw_small_square(cube, x, y, i, l, rgb_to_hex(0,255,255,255));
			}
			else if (cube->map[c][d] != '\n' && cube->map[c][d] != '\0')
			{
				ft_draw_small_square(cube, x, y, i, l, rgb_to_hex(0,255,255,255));
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

	// while (cube->map[c])
	// {
	// 	while (cube->map[c][d])
	// 	{
	// 		k = 0;
	// 		if (cube->map[c][d] == '1')
	// 		{
	// 			while (k != cube->map_s.mini_cub_h)
	// 			{
	// 				i = -1;
	// 				while (i < cube->map_s.mini_cub_w)
	// 				{
	// 					cube->map_s.addr[MINIMAP_WIDTH * k + i] = rgb_to_hex(0,255,255,255);
	// 				}
	// 				//k += cube->map_s.mini_cub_h;
	// 				k++;
	// 			}
	// 		}
	// 	}
	// 	c++;
	// }
}

void	draw_player(t_cube *cube)
{
	int k = 0;
	int l = 0;
	int	i = 0;

	k = 0;
	i = 0;
	l = 0;
	while (k < cube->map_s.mini_cub_h / 2)
	{
		i = -1;
		while (l++ < cube->map_s.mini_cub_w / 2)
		{
			cube->map_s.addr[MINIMAP_WIDTH * (k + cube->y) + cube->i + l] = rgb_to_hex(0, 255, 0, 255);
		}
		l = 0;
		k++;
	}
}
