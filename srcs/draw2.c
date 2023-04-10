#include "cub3d.h"

void ft_draw_small_square(t_cube *cube, int y, int w, int h, int color)
{
	int (temp) = 0;
	int (temp2) = 0;
	while (temp2 < CUBE_H)
	{
		while (temp < CUBE_W)
		{
			cube->map_s.addr[(h + temp2) * cube->map_s.map_width + (temp + w)] = color;
			temp++;
		}
		temp = 0;
		temp2++;
	}
}

void draw_minimap(t_cube *cube)
{
	int (i) = 0;
	int (j) = 0;
	while (cube->map[i])
	{
		while (cube->map[i][j])
		{
			if (cube->map[i][j] == '0')
				ft_draw_small_square(cube, CUBE_H, j * CUBE_W, i * CUBE_H, rgb_to_hex(0, 255, 255, 255));
			else if (cube->map[i][j] == '1')
				ft_draw_small_square(cube, CUBE_H, j * CUBE_W, i * CUBE_H, rgb_to_hex(0, 255, 0, 255));
			else
				ft_draw_small_square(cube, CUBE_H, j * CUBE_W, i * CUBE_H, rgb_to_hex(255, 0, 0, 0)); // map disi vb icin trans.
			j++;
		}
		i++;
		j = 0;
	}
}

void draw_trans_map(t_cube *cube)
{
	int	(i) = 0;
	int (j) = 0;
	while (cube->map[i])
	{
		while (cube->map[i][j])
		{
			ft_draw_small_square(cube, CUBE_H, j * CUBE_W, i * CUBE_H, rgb_to_hex(255, 0, 0, 0)); // map disi vb icin trans.
			j++;
		}
		i++;
		j = 0;
	}
}


void	draw_player(t_cube *cube)
{
	int (k) = 0;
	int (l) = 0;
	while (k < CUBE_H)
	{
		l = -1;
		while (++l < CUBE_W)
		{
			cube->map_s.addr[cube->map_s.map_width * (k + (int)cube->y) + (int)cube->x + l] = rgb_to_hex(0, 0, 255, 255);
		}
		k++;
	}
}

void draw_ray_and_3d(t_cube *cube)
{
	int (i) = 0;

	double x = cube->x + (CUBE_W / 2);
	double y = cube->y + (CUBE_W / 2);
	double (tmp_x) = x;
	double (tmp_y) = y;

	double (ray_angle) = cube->player_angle + 33.0;
	double ray_x = cos(ray_angle * (M_PI / 180.0));
	double ray_y = -sin(ray_angle * (M_PI / 180.0));
	while (i < cube->win_width)
	{
		if (cube->m == false)
		{
			while (cube->map[(int)(y / (double)CUBE_H)][(int)(x / (double)CUBE_W)] != '1')
			{
				x += ray_x;
				y += ray_y;
				if (cube->map[(int)(y / (double)CUBE_H)][(int)(x / (double)CUBE_W)] == '1')
					break;
				cube->map_s.addr[cube->map_s.map_width * (int)y + (int)x] = rgb_to_hex(125, 0, 255, 0);
			}
		}
		ray_dda(cube, ray_angle, i);
		x = tmp_x;
		y = tmp_y;
		ray_angle -= 66.0 / cube->win_width;
		ray_x = cos(ray_angle * (M_PI / 180.0));
		ray_y = -sin(ray_angle * (M_PI / 180.0));
		i += 1;
	}
}


