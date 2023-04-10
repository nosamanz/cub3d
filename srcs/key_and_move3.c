#include "cub3d.h"

double check_wy(t_cube *cube)
{
	if (cube->player_angle > 180 || cube->player_angle < 0)
		return (CUBE_H / 2.0);
	return (0);
}

double check_wx(t_cube *cube)
{
	if (cube->player_angle < 90 || cube->player_angle > 270)
		return (CUBE_W / 2.0);
	return (0);
}

double check_sy(t_cube *cube)
{
	if (cube->player_angle < 180 || cube->player_angle > 0)
		return (CUBE_H / 2.0);
	return (0);
}

double check_sx(t_cube *cube)
{
	if (cube->player_angle > 90 || cube->player_angle < 270)
		return (CUBE_H / 2.0);
	return (0);
}

