#include "cub3d.h"

int map_check(t_cube *cube)
{
	int i = 0;
	int j = 0;
	bool flag = false;
	bool flag2 = false;

	while (cube->map[i])
	{
		while (cube->map[i][j])
		{
			// if (cube->map[i][0] != 32 && cube->map[i][0] != '1')
			// 	return (0);
			else if (cube->map[i][j] == 32)
			{
				while (cube->map[i][j] == 32)
					j++;
				if (cube->map[i][j] != '1') // soldan ilk i duvar mi degil mi
					return (0);
			}
			// else if (cube->map[cube->map_height][j] == 32)
			// {
			// 	while (cube->map[cube->map_height][j] == 32)
			// 		j++;
			// 	if (cube->map[cube->map_height][j] != '1')
			// 		return (0);

			// }
			if (i == 0 && cube->map[i][j] == '0')
				return (0);
			if (i != 0 && cube->map[i - 1][j] == 32 && cube->map[i][j] == '0') // ustte bosluk olup kendisi duvar olmayan
				return (0);
			// exit(1);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
