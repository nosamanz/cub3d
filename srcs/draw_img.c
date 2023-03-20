#include "cub3d.h"

void ft_draw_small_square(t_cube *cube, int y, int w, int h, int color)
{
	int k = 0;
	int i;
	int temp = 0;
	i = 0;
	int temp2 = 0;

	while (temp2 < 8)
	{
		while (temp < 8)
		{
			cube->map_s.addr[(h + temp2) * cube->map_s.map_width + (temp + w)] = color;
			temp++;
		}
		temp = 0;
		temp2++;
	}
}

// void ft_pixel_put(t_cub3d *main, int x, int y, unsigned long color)
// {
//     int i;
//     int k;
//     i = -1;
//     while (++i < main->mini_map->map_img_size_y)
//     {
//         k = -1;
//         while (++k < main->mini_map->map_img_size_x)
//         {
//             main->mini_map_img_adress[(int)(MINI_MAP_WIDTH * (y + i) + (x + k))] = color;
//         }
//     }
// }


void draw_minimap(t_cube *cube)
{
	int	i;
	int j;
	int	k;
	int l;

	k = 0;
	l = 0;
	i = 0;
	j = 0;


	while (cube->map[i])
	{
		while (cube->map[i][j])
		{
			if (cube->map[i][j] == '0')
				ft_draw_small_square(cube, CUBE_H, j * CUBE_W, i * CUBE_H, rgb_to_hex(0, 255, 255, 255));
			else if (cube->map[i][j] == '1')
				ft_draw_small_square(cube, CUBE_H, j * CUBE_W, i * CUBE_H, rgb_to_hex(0, 255, 0, 255));
			else
				ft_draw_small_square(cube, CUBE_H, j * CUBE_W, i * CUBE_H, rgb_to_hex(0, 255, 255, 0));
			// k += CUBE_W;
			j++;
		}
		// l += CUBE_H;
		i++;
		j = 0;
	}



	// bu doru
	// int d;
	// while (l < cube->map_s.map_height)
	// {
	// 	d = -1;
	// 	while (++d <= cube->map_s.map_width)
	// 	{
	// 		cube->map_s.addr[cube->map_s.map_width * l + d] = rgb_to_hex(0, 0, 255, 0);
	// 	}
	// 	l++;
	// }
}


void	draw_player(t_cube *cube)
{
	int k = 0;
	int l = 0;

	printf("cube->x:%f cube->y %f\n", cube->x, cube->y);
	while (k < CUBE_H - 1)
	{
		l = -1;
		while (++l < CUBE_W - 1)
		{
			cube->map_s.addr[cube->map_s.map_width * (k + (int)cube->y) + (int)cube->x + l] = rgb_to_hex(125, 0, 0, 255);
		}
		k++;
	}

}

void draw_ray(t_cube *cube)
{
	int k = 0;
	int i = 0;

	double x = cube->x + (CUBE_W / 2) - 1;
	double y = cube->y;

	double ray_x = cos(cube->player_angle);
	double ray_y = sin(cube->player_angle);


	// k = cube->y;
	while (1)
	{
		// if (x < 0 || x >= cube->map_s.map_width || y < 0 || y >= cube->map_s.map_height)
		// 	break;
		// if (cube->map[k / 8][x / 8] == '1')
		// 	break;
		// while (k < cube->map_s.map_height)
		// {
		// 	if (cube->map[k / 8][x / 8] == '1')
		// 		break;
		// 	cube->map_s.addr[cube->map_s.map_width * k + x] = rgb_to_hex(0, 0, 0, 0);
		// 	k--;
		// }
		x += ray_x;
		y += ray_y;
		if (cube->map[(int)(y / 8)][(int)(x / 8)] == '1')
			break;
		cube->map_s.addr[cube->map_s.map_width * (int)y + (int)x] = rgb_to_hex(0, 0, 0, 0);
	}
}
