#include "cub3d.h"

int	is_wall(unsigned int x, unsigned int y, t_cube *cube)
{
	if (cube->map[y / CUBE_H][x / CUBE_W] == '1')
		return (1);
	return (0);
}

void move(t_cube *cube)
{
	double x = cube->x;
	double y = cube->y;
	if (cube->w)
	{
		x += cos(cube->player_angle * (M_PI / 180.0));
		y += sin(cube->player_angle * (M_PI / 180.0) * -1);

		if (!is_wall(x + (CUBE_W / 2), cube->y + (CUBE_W / 2),cube))
			cube->x = x;
		if (!is_wall(cube->x + (CUBE_W / 2), y,cube))
			cube->y = y;
	}
	if (cube->s)
	{
		x += cos(cube->player_angle * (M_PI / 180.0)) * -1;
		y += sin(cube->player_angle * (M_PI / 180.0));

		if (!is_wall(x + (CUBE_W / 2), cube->y + (CUBE_W / 2),cube))
			cube->x = x;
		if (!is_wall(cube->x + (CUBE_W / 2), y,cube))
			cube->y = y;
	}
	if (cube->a)
	{
		x += sin(cube->player_angle * (M_PI / 180.0)) * -1;
		y += cos(cube->player_angle * (M_PI / 180.0)) * -1;
		if (!is_wall(x + (CUBE_W / 2), cube->y + (CUBE_W / 2),cube))
			cube->x = x;
		if (!is_wall(cube->x + (CUBE_W / 2), y,cube))
			cube->y = y;
	}
	if (cube->d)
	{
		x += sin(cube->player_angle * (M_PI / 180.0));
		y += cos(cube->player_angle * (M_PI / 180.0));

		if (!is_wall(x + (CUBE_W / 2), cube->y + (CUBE_W / 2),cube))
			cube->x = x;
		if (!is_wall(cube->x + (CUBE_W / 2), y,cube))
			cube->y = y;
	}
	if (cube->ra)
	{
		cube->player_angle -= AN;
		if (cube->player_angle < 0)
			cube->player_angle = 360;
	}
	if (cube->la)
	{
		cube->player_angle += AN;
		if (cube->player_angle >= 360)
			cube->player_angle = 0;
	}
	printf("player angle:%0.2f\n", cube->player_angle);
}

int key_press(int key, t_cube *cube)
{
	if (key == W)
		cube->w = true;
	if (key == S)
		cube->s = true;
	if (key == D)
		cube->d = true;
	if (key == A)
		cube->a = true;
	if (key == RA)
		cube->ra = true;
	if (key == LA)
		cube->la = true;
	return (1);
}

int key_release(int key, t_cube *cube)
{
	if (key == W)
		cube->w = false;
	if (key == S)
		cube->s = false;
	if (key == D)
		cube->d = false;
	if (key == A)
		cube->a = false;
	if (key == RA)
		cube->ra = false;
	if (key == LA)
		cube->la = false;
	return (1);
}


void	handle_keypress(t_cube *cube)
{
	move(cube);
}
