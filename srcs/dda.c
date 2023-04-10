#include "cub3d.h"

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

void	new_c3d(t_cube *cube, double distance, int raycount, t_xpm xpm)
{
	distance = (distance * (double)CUBE_H * ((double)cube->win_height / 2) / (double)cube->win_width);
	// double	l_end = (((double)cube->win_height) / distance) * (double)CUBE_H;
	double l_end = (((double)cube->win_height / 2.0) / distance) * (double)CUBE_H;

	if (cube->hit_h)
		cube->find_pixel = (cube->ray_x - floor(cube->ray_x)) * xpm.width;
	else if (cube->hit_v)
		cube->find_pixel = (cube->ray_y - floor(cube->ray_y)) * xpm.width;

	int img_loc = (xpm.width * (xpm.height / 2)) + cube->find_pixel;

	// if ((l_end >= 4000))
	// 	l_end = 4000;
	int color;
	int (l_begin) = 0;
	while (l_begin < l_end && l_begin <= (int)(cube->win_height / 2.0))
	{
		color = xpm.img.addr[img_loc + xpm.width * (int)((double)l_begin * ((double)xpm.width / (double)(l_end * 2)))];
		cube->win_addr[((cube->win_height / 2) * cube->win_width + raycount)
			+ (cube->win_width * l_begin)] = color;
		color = xpm.img.addr[img_loc - xpm.width * (int)((double)l_begin * ((double)xpm.width / (double)(l_end * 2)))];
		cube->win_addr[((cube->win_height / 2) * cube->win_width + raycount)
			- (cube->win_width * l_begin)] = color;
		l_begin++;
	}
}

void	ray(double distance, t_cube *cube, int i)
{
	if (cube->hit_h)
	{
		cube->ray_x = cube->ray_x_h;
		cube->ray_y = cube->ray_y_h;
		if (cube->ray_dir_y == 1)
			cube->xpm_number = 1;
		else
			cube->xpm_number = 0;
	}
	else if (cube->hit_v)
	{
		cube->ray_x = cube->ray_x_v;
		cube->ray_y = cube->ray_y_v;
		if (cube->ray_dir_x == 1)
			cube->xpm_number = 2;
		else
			cube->xpm_number = 3;
	}
	new_c3d(cube, distance, i, cube->xpm[cube->xpm_number]);
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
	// distance *= fabs(cos(((cube->player_angle * (180.0 /M_PI)) - angle) * (M_PI / 180)));
	ray(distance, cube, i);
}
