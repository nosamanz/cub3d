#include "cub3d.h"

void ft_draw_small_square(t_cube *cube, int y, int w, int h, int color)
{
	int k = 0;
	int i;
	int temp = 0;
	i = 0;
//	temp = w;
	int temp2 = 0;

	//temp2 = h + 8;
	//if (temp2 > cube->map_s.map_height)
	//	return;
	//printf("H: %d\n", h);
	//printf("temp: %d\n", temp2);
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
			if (cube->map[i][j] == '1')
			{
				// ft_draw_small_square(cube, CUBE_H, k, l, rgb_to_hex(0, 255, 0, 0));
				ft_draw_small_square(cube, CUBE_H, j * CUBE_W, i * CUBE_H, rgb_to_hex(0, 255, 0, 0));
			}
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
	while (k < 4)
	{
		l = -1;
		while (++l < 4)
		{
			cube->map_s.addr[cube->map_s.map_width * (k + (int)cube->y) + (int)cube->x + l] = rgb_to_hex(200, 0, 0, 255);
		}
		k++;
	}

}

// void draw_ray(t_cube *cube)
// {
// 	int k = 0;
// 	int l = 0;
// 	int i = 0;
// 	int tmp = cube->map_s.map_height - (cube->y / cube->map_s.mini_cub_h);
// 	printf("%d\n", tmp);

// 	int x = cube->x;
// 	int y = cube->y;
// 	// while (1)
// 	// {
// 	// 	cube->map_s.addr[y * MINIMAP_WIDTH + x - (MINIMAP_WIDTH * i)] = rgb_to_hex(200, 0, 0, 255);
// 	// }
// 	k = cube->y;
// 	while (1)
// 	{
// 		if (cube->map_s[k / cube->map_s.mini_cub_h][x / cube->map_s.mini_cub_w] == '1')
// 			break;
// 		while (k > 0)
// 		{
// 			if (cube->map_s[k / cube->map_s.mini_cub_h][x / cube->map_s.mini_cub_w] == '1')
// 				break;
// 			cube->map_s.addr[cube->map_s.mini_cub_w * k + (x + cube->map_s.mini_cub_w / 2)] = rgb_to_hex(200, 0, 0, 255);
// 			k--;
// 		}
// 	}
// }
