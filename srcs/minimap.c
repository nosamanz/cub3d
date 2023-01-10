#include "cub3d.h"

void	check_map_size(t_cube *cube)
{
	int	i;
	int	longest;
	int	len;

	longest = 0;
	i = 0;
	while (cube->map[i] != NULL)
	{
		len = ft_strlen(cube->map[i]);
		if (len > longest)
			longest = len;
		i++;
	}
	cube->map_s.map_width = longest - 1;
	cube->map_s.map_height = i;
}
