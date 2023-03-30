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
			cube->map_s.addr[cube->map_s.map_width * (k + (int)cube->y) + (int)cube->x + l] = rgb_to_hex(255, 0, 255, 255);
		}
		k++;
	}
}

void duvar_ciz(int x, double line, t_cube* cube)
{
	double l_begin = (cube->win_height / 2) - line / 2;
	double l_end = (cube->win_height / 2) + line / 2;
	while(l_begin <= l_end)
	{
			cube->win_addr[cube->win_width * (int)l_begin + (int)x] = rgb_to_hex(0, 155, 155, 0);
			l_begin++;
	}

}

void func(int x,double dist, t_cube *cube)
{
	double line = cube->win_height * 10 / dist * 2;
	if (line > 700)
		line = 700;
	duvar_ciz(x, line, cube);
}

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
	ray_angle = cube->player_angle + 33;
	double ray_x = cos(ray_angle * (M_PI / 180.0));
	double ray_y = sin(ray_angle * (M_PI / 180.0)) * -1;

	while (i < 1500)
	{
		while (cube->map[(int)(y / 8)][(int)(x / 8)] != '1')
		{
			x += ray_x;
			y += ray_y;
			if (cube->map[(int)(y / 8)][(int)(x / 8)] == '1')
				break;
			cube->map_s.addr[cube->map_s.map_width * (int)y + (int)x] = rgb_to_hex(0, 0, 255, 0);
		}
		x = fabs(x - cube->x);
		y = fabs(y - cube->y);
		double (dist) = sqrt(x * x + y * y);
		// func(dist, cube); //  winheight / dist // duvar_ciz(duvar_uzunluğu); (winheigt / 2) - duvar_uzunluğu / 2
		func(i, dist, cube);
		x = tmp_x;
		y = tmp_y;
		ray_angle -= 0.02;
		if (ray_angle < cube->player_angle - 33)
			break;
		ray_x = cos(ray_angle * (M_PI / 180.0));
		ray_y = sin(ray_angle * (M_PI / 180.0)) * -1;
		i++;
	}
}

// void	draw_ray(int x, int y, double angle, t_cube *cube)
// {
// 	double	ray_x;
// 	double	ray_y;
// 	double	dx;
// 	double	dy;

// 	ray_x = cube->def_p_x;
// 	ray_y = cube->def_p_y;
// 	// dx = main->ray.distance * fabs(cos(angle_to_radyan(angle))) * x;
// 	// dy = main->ray.distance * fabs(sin(angle_to_radyan(angle))) * y;
// 	dx = 10 * fabs(cos(angle_to_radyan(angle))) * x;
// 	dy = 10 * fabs(sin(angle_to_radyan(angle))) * y;
// 	dx /= main->ray.distance;
// 	dy /= main->ray.distance;
// 	while (1)
// 	{
// 		// if (!is_wall_v2(main, ray_x, ray_y))
// 			put_to_ray_addr(main, ray_y, ray_x);
// 		// else
// 		// {
// 			// main->ray.pos_x = ray_x;
// 			// main->ray.pos_y = ray_y;
// 			// draw_3d(main, main->ray.distance, angle);
// 			// break ;
// 		// }
// 		ray_x += dx / 100;
// 		ray_y += dy / 100;
// 	}
// }

// void	ray_calculator(t_cube *cube, double angle)
// {
// 	// double	distance_v;
// 	// double	distance_h;
// 	int		x;
// 	int		y;

// 	x = ((cos(angle * (M_PI / 180)) > 0) * 2) - 1;
// 	y = ((sin(angle * (M_PI / 180)) > 0) * -2) + 1;
// 	// cube->ray_dir_x = x;
// 	// cube->ray_dir_y = y;
// 	// cube->ray_sp_ray = false;
// 	// distance_v = ray_vertical(cube, angle, x, y);
// 	// distance_h = ray_horizonal(cube, angle, x, y);
// 	// ray_calculator_c(main, distance_v, distance_h);
// 	// main->ray.o_distance = main->ray.distance;
// 	// main->ray.distance = main->ray.distance
// 	// 	* cos((main->player->angle - angle) * (M_PI / 180.0));
// 	draw_ray(x, y, angle, main);
// }

// void ray_casting(t_cube *cube)
// {
// 	double angle;

// 	cube->def_p_x = (cube->x + 8);
// 	cube->def_p_y =	(cube->y + 8);

// 	angle = cube->player_angle - (AN / 2);
// 	while (angle >= 360)
// 		angle -= 360;
// 	while (angle < 0)
// 		angle += 360;

// 	cube->ray_number = 0;
// 	while (cube->ray_number < cube->win_width)
// 	{
// 		//
// 		ray_calculator(cube, angle);
// 		angle += (double)AN / (double)cube->win_width;
// 		cube->ray_number++;
// 	}
// }

