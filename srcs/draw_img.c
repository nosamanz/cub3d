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

	int x  = cube->map_s.mini_cub_w;
	int y = cube->map_s.mini_cub_h;

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
			i += x;
			d++;
		}
		d = 0;
		i = 0;
		l = y + l;
		c++;
		k++;
	}
	// int m = 0;
	// while (cube->map[c])
	// {
	// 	while (cube->map[c][d])
	// 	{
	// 		if (cube->map[c][d] == '1')
	// 		{
	// 			printf("duvar %d\n", c);
	// 			while (k != cube->map_s.mini_cub_h)
	// 			{
	// 				while (l != cube->map_s.mini_cub_w)
	// 				{
	// 					cube->map_s.addr[MINIMAP_WIDTH * (c * cube->map_s.mini_cub_h + k) + l] = rgb_to_hex(0,0,0,0);
	// 					l++;
	// 				}
	// 				l = 0;
	// 				k++;
	// 			}
	// 		}
	// 		d++;
	// 	}
	// 	d = 0;
	// 	c++;
	// }
}

void	draw_player(t_cube *cube)
{
	int k = 0;
	int l = 0;

	while (k < cube->map_s.mini_cub_h)
	{
		while (l++ < cube->map_s.mini_cub_w)
		{
			cube->map_s.addr[MINIMAP_WIDTH * (k + (int)cube->y) + (int)cube->x + l] = rgb_to_hex(200, 0, 0, 255);
		}
		l = 0;
		k++;
	}

}

void draw_ray(t_cube *cube)
{
	int k = 0;
	int l = 0;
	int i = 0;
	int tmp = cube->map_s.map_height - (cube->y / cube->map_s.mini_cub_h);
	printf("%d\n", tmp);

	int x = cube->x;
	int y = cube->y;
	// while (1)
	// {
	// 	cube->map_s.addr[y * MINIMAP_WIDTH + x - (MINIMAP_WIDTH * i)] = rgb_to_hex(200, 0, 0, 255);
	// }
	k = cube->y;
	while (1)
	{
		if (cube->map[k / cube->map_s.mini_cub_h][x / cube->map_s.mini_cub_w] == '1')
			break;
		while (k > 0)
		{
			if (cube->map[k / cube->map_s.mini_cub_h][x / cube->map_s.mini_cub_w] == '1')
				break;
			cube->map_s.addr[MINIMAP_WIDTH * k + (x + cube->map_s.mini_cub_w / 2)] = rgb_to_hex(200, 0, 0, 255);
			k--;
		}
	}
	// while (k < cube->map_s.mini_cub_h)
	// {
	// 	i = -1;
	// 	while (l++ < cube->map_s.mini_cub_w)
	// 	{
	// 		cube->map_s.addr[MINIMAP_WIDTH * (k + (int)cube->y) + (int)cube->x + l] = rgb_to_hex(200, 0, 0, 255);
	// 	}
	// 	l = 0;
	// 	k++;
	// }
}
