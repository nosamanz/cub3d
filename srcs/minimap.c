#include "cub3d.h"

void	fill_map_spaces(t_cube *cube)
{
	int			i;
	int			j;
	int		index;
	char	*new_str;

	i = 0;
	j = 0;
	while (cube->map[i])
	{
		if (ft_strlen(cube->map[i]) < cube->map_s.map_width)
		{
			new_str = malloc(sizeof(char) * cube->map_s.map_width + 100);
			index = ft_strlen(cube->map[i]);
			ft_strlcpy(new_str, cube->map[i], ft_strlen(cube->map[i]));
			index--;
			while (index <= cube->map_s.map_width)
				new_str[index++] = 32;
			new_str[index] = '\0';
			cube->map[i] = ft_strdup(new_str);
		}
		i++;
	}
}

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
