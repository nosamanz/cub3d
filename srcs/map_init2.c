#include "cub3d.h"

void color_code_init(t_cube *cube, int *arry, char *str)
{
	int i = 0;
	int j = 0;
	char **tmp;

	tmp = ft_split(str, ',');
	while (i < 3)
	{
		arry[i] = ft_atoi(tmp[i]);
		i++;
	}
}

void take_color(t_cube *cube)
{
	char **tmp;
	char **tmp2;

	int (i) = 0;
	while (cube->map_file[i][0] != 'F' && cube->map_file[i][0] != 'C')
		i++;

	tmp = ft_split(cube->map_file[i], 32);
	tmp2 = ft_split(cube->map_file[++i], 32);

	if (tmp[0][0] == 'F')
	{
		color_code_init(cube, cube->f_color, tmp[1]);
		color_code_init(cube, cube->c_color, tmp2[1]);
	}
	else if (tmp[0][0] == 'C')
	{
		color_code_init(cube, cube->c_color, tmp2[1]);
		color_code_init(cube, cube->f_color, tmp[1]);
	}
}

void assign_path(t_cube *cube, char ***texture, int i)
{
	*texture = ft_split(cube->map_file[i], 32);
	(*texture)[1] = ft_strtrim((*texture)[1], "\n");
}

void	take_texture(t_cube *cube)
{
	int (i) = 0;
	int (j) = 0;
	while (cube->map_file[i][j] <= 32 || cube->map_file[i][j] == 13)
		i++;
	while (cube->map_file[i] != NULL)
	{
		if (!ft_strncmp(cube->map_file[i], "NO", 2))
			assign_path(cube, &cube->NO, i);
		else if (!ft_strncmp(cube->map_file[i], "SO", 2))
			assign_path(cube, &cube->SO, i);
		else if (!ft_strncmp(cube->map_file[i], "WE", 2))
			assign_path(cube, &cube->WE, i);
		else if (!ft_strncmp(cube->map_file[i], "EA", 2))
			assign_path(cube, &cube->EA, i);
		i++;
	}
}
