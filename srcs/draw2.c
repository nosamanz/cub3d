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
				ft_draw_small_square(cube, CUBE_H, j * CUBE_W, i * CUBE_H, rgb_to_hex(255, 0, 0, 0)); // map disi vb icin trans.
			// k += CUBE_W;
			j++;
		}
		// l += CUBE_H;
		i++;
		j = 0;
	}
}

void draw_trans_map(t_cube *cube)
{
	int	i;
	int j;

	i = 0;
	j = 0;

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
	int k = 0;
	int l = 0;

	printf("cube->x:%0.2f cube->y %0.2f\n", cube->x, cube->y);
	k = 0;
	l = 0;
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

// void duvar_ciz(int x, double line, t_cube* cube)
// {
// 	double l_begin = ((double)cube->win_height / 2.0) - line / 2.0;
// 	double l_end = ((double)cube->win_height / 2.0) + line / 2.0;

// 	while(l_begin <= l_end)
// 	{
// 		cube->win_addr[cube->win_width * (int)l_begin + (int)x] = rgb_to_hex(0, 155, 155, 0);
// 		l_begin++;
// 	}
// }

// void func(int x, double dist, t_cube *cube)
// {
// 	// double line = cube->win_height * 10 / dist * 2;
// 	double line = (double)cube->win_height * 10.0 / dist * 2.0;

// 	//printf("line:%lf\n", line);
// 	if (line > 700.0) // yakinlasinca seg almasin diye
// 		line = 700.0;
// 	duvar_ciz(x, line, cube);
// }

void draw_ray(t_cube *cube)
{
	int i = 0;
	double ray_angle;

	double x = cube->x + (CUBE_W / 2);
	double y = cube->y + (CUBE_W / 2);
	double tmp_x = x;
	double tmp_y = y;

	// double ray_x = cos(cube->player_angle * (M_PI / 180.0));
	// double ray_y = sin(cube->player_angle * (M_PI / 180.0)) * -1;
	ray_angle = cube->player_angle + 33.0;
	while (cube->player_angle >= 360)
		cube->player_angle -= 360;
	while (cube->player_angle < 0)
		cube->player_angle += 360;
	double ray_x = cos(ray_angle * (M_PI / 180.0));
	double ray_y = -sin(ray_angle * (M_PI / 180.0));
	//printf("rayx:%f rayy%f\n", ray_x, ray_y);
	//printf("------------------>%d\n", cube->win_width);
	while (i < cube->win_width)
	{
		while (cube->map[(int)(y / 8.0)][(int)(x / 8.0)] != '1')
		{
			x += ray_x;
			y += ray_y;
			if (cube->map[(int)(y / 8.0)][(int)(x / 8.0)] == '1')
				break;
			cube->map_s.addr[cube->map_s.map_width * (int)y + (int)x] = rgb_to_hex(0, 0, 255, 0);
		}
		// x = fabs(x - cube->x);
		// y = fabs(y - cube->y);
		// double (dist) = sqrt((x * x) + (y * y));
		// func(dist, cube); //  winheight / dist // duvar_ciz(duvar_uzunluğu); (winheigt / 2) - duvar_uzunluğu / 2
		ray_dda(cube, ray_angle, i);
		x = tmp_x;
		y = tmp_y;
		ray_angle -= 66.0 / cube->win_width;
		// while (ray_angle >= 360.0)
		// 	ray_angle -= 360.0;
		// while (ray_angle < 0.0)
		// 	ray_angle += 360.0;
		ray_x = cos(ray_angle * (M_PI / 180.0));
		ray_y = -sin(ray_angle * (M_PI / 180.0));
		// if (ray_angle < cube->player_angle - 33)
		// 	break;
		i += 1;
	}
}


