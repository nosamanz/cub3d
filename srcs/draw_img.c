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
			cube->map_s.addr[cube->map_s.map_width * (k + (int)cube->y) + (int)cube->x + l] = rgb_to_hex(255, 0, 255, 255);
		}
		k++;
	}
}

void duvar_ciz(int x, double line, t_cube* cube)
{
	double l_begin = ((double)cube->win_height / 2.0) - line / 2.0;
	double l_end = ((double)cube->win_height / 2.0) + line / 2.0;

	while(l_begin <= l_end)
	{
		cube->win_addr[cube->win_width * (int)l_begin + (int)x] = rgb_to_hex(0, 155, 155, 0);
		l_begin++;
	}
}

// void func(int x, double dist, t_cube *cube)
// {
// 	// double line = cube->win_height * 10 / dist * 2;
// 	double line = (double)cube->win_height * 10.0 / dist * 2.0;

// 	//printf("line:%lf\n", line);
// 	if (line > 700.0) // yakinlasinca seg almasin diye
// 		line = 700.0;
// 	duvar_ciz(x, line, cube);
// }

void c3D(double dist, t_cube *cube, int i)
{
	int	direction;
	dist = (dist * 8.0 * (double)cube->win_height) / (double)cube->win_width;
	int	img_loc = (cube->win_height / 2) * cube->win_width + i;
	//double l_begin = ((double)cube->win_height / 2.0) - line / 2.0;
	int		l_begin = 0;
	double	l_end = (((double)cube->win_height / 2.0) / dist) * 8.0;
	if (cube->hit_h)
	{
		if (cube->ray_dir_y == 1)
			direction = 0x0e0f01 * M_LN10;
		else
			direction = 0xff000F * M_PI;
	}
	else if (cube->hit_v)
	{
		if (cube->ray_dir_x == 1)
			direction = 0xe0ff0e / 2;
		else
			direction = 0xeeeeee;
	}
	while(l_begin < l_end)
	{
		if (img_loc - (l_begin * cube->win_width) > 0)
			cube->win_addr[img_loc - (l_begin * cube->win_width)] = direction;
		if (img_loc + (l_begin * cube->win_width) < cube->win_height * cube->win_width)
			cube->win_addr[img_loc + (l_begin * cube->win_width)] = direction;
			// cube->win_addr[img_loc + (l_begin * cube->win_width)] = (int)direction * i / dist;
		l_begin++;
	}
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

void	horizontal_while(t_cube *cube, double angle)
{
	while (cube->p_x + cube->hdx * cube->ray_dir_x >= 0 && cube->p_x + cube->hdx
		* cube->ray_dir_x <= (cube->map_s.map_width - 1)
		&& cube->p_y + cube->hdy * cube->ray_dir_y - 0.0001 >= 0
		&& cube->p_y + cube->hdy * cube->ray_dir_y - 0.0001 <= cube->map_s.map_height)
	{
		cube->hdy = cube->hdy + 0.0001;
		if (is_wall2(cube->p_x + cube->hdx * cube->ray_dir_x,
				cube->p_y + cube->hdy * cube->ray_dir_y, cube))
		{
			cube->hit_h = true;
			cube->tmp2_x = cube->hdx * cube->ray_dir_x;
			cube->tmp2_y = cube->hdy * cube->ray_dir_y;
			cube->ray_x_h = cube->p_x + cube->tmp2_x;
			cube->ray_y_h = cube->p_y + cube->tmp2_y;
			break ;
		}
		cube->hdy = cube->hdy + 1.0 - 0.0001;
		cube->hdx = fabs(cube->hdy / tan(angle * (M_PI / 180)));
	}
}

double	horizontal(t_cube *cube, double angle)
{
	double	distance;

	distance = 10000;
	if (cube->ray_dir_y == -1)
		cube->hdy = cube->p_y - floor(cube->p_y);
	else
		cube->hdy = ceil(cube->p_y) - cube->p_y;
	cube->hdx = fabs(cube->hdy / tan(angle * (M_PI / 180)));
	cube->tmp2_x = cube->hdx * cube->ray_dir_x;
	cube->tmp2_y = cube->hdy * cube->ray_dir_x;
	horizontal_while(cube, angle);
	if (cube->hit_h == true)
		distance = sqrt((cube->tmp2_x * cube->tmp2_x) \
			+ (cube->tmp2_y * cube->tmp2_y));
	return (distance);
}

void	vertical_while(t_cube *cube, double angle)
{
	while (cube->p_x + cube->vdx * cube->ray_dir_x - 0.0001 >= 0
		&& cube->p_x + cube->vdx * cube->ray_dir_x - 0.0001 <= (cube->map_s.map_width - 1)
		&& cube->p_y + cube->vdy * cube->ray_dir_y >= 0
		&& cube->p_y + cube->vdy * cube->ray_dir_y <= cube->map_s.map_height)
	{
		cube->vdx = cube->vdx + 0.0001;
		if (is_wall2(cube->p_x + (cube->vdx
				* cube->ray_dir_x), cube->p_y + (cube->vdy * cube->ray_dir_y), cube))
		{
			cube->hit_v = true;
			cube->tmp_x = cube->vdx * cube->ray_dir_x;
			cube->tmp_y = cube->vdy * cube->ray_dir_y;
			cube->ray_x_v = cube->p_x + cube->tmp_x;
			cube->ray_y_v = cube->p_y + cube->tmp_y;
			break ;
		}
		cube->vdx = cube->vdx + 1.0 - 0.0001;
		cube->vdy = fabs(tan(angle * (M_PI / 180)) * cube->vdx);
	}
}

double	vertical(t_cube *cube, double angle)
{
	double	distance;

	distance = 10000;
	if (cube->ray_dir_x == -1) // x i izgaraya cek
		cube->vdx = cube->p_x - floor(cube->p_x);
	else
		cube->vdx = ceil(cube->p_x) - cube->p_x;

	cube->vdy = fabs(tan(angle * (M_PI / 180)) * cube->vdx);
	cube->tmp_x = cube->vdx * cube->ray_dir_x;
	cube->tmp_y = cube->vdy * cube->ray_dir_y;
	vertical_while(cube, angle);
	if (cube->hit_v == true)
		distance = sqrt((cube->tmp_x * cube->tmp_x) + (cube->tmp_y * cube->tmp_y));
	return (distance);
}

void	ray_dda(t_cube *cube, double angle, int i)
{
	double	h_dis;
	double	v_dis;
	double	distance;

	cube->p_x = cube->x / (double)CUBE_W;
	cube->p_y = cube->y / (double)CUBE_H;

	cube->hit_h = false;
	cube->hit_v = false;
	// cube->ray_dir_x = ((cos(angle * (M_PI / 180)) > 0) * 2) - 1;
	// cube->ray_dir_y = ((sin(angle * (M_PI / 180)) > 0) * -2) + 1;
	if (cos(angle * (M_PI / 180)) > 0)
		cube->ray_dir_x = 1.0;
	else
		cube->ray_dir_x = -1.0;
	if (sin(angle * (M_PI / 180)) > 0)
		cube->ray_dir_y = -1.0;
	else
		cube->ray_dir_y = 1.0;
	v_dis = vertical(cube, angle);
	h_dis = horizontal(cube, angle);
	if (v_dis < h_dis)
	{
		distance = v_dis;
		cube->hit_h = false;
		cube->hit_v = true;
	}
	else
	{
		distance = h_dis;
		cube->hit_v = false;
		cube->hit_h = true;
	}
	//distance *= fabs(cos(((cube->player_angle * (180.0 /M_PI)) - angle) * (M_PI / 180)));
	c3D(distance, cube, i);
}
