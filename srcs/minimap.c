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

	cube->win_height = i * (CUBE_H * 4);
	printf("wh: %d\n", cube->win_height);
	cube->win_width = (longest - 1) * (CUBE_W * 4);
	printf("ww: %d\n", cube->win_width);

	cube->map_s.map_height = i * CUBE_H;
	printf("mh: %d\n", cube->map_s.map_height);

	cube->map_s.map_width = (longest - 1) * CUBE_W;
	printf("mw: %d\n", cube->map_s.map_width);

	cube->map_s.p_movement_mm = 2;

	cube->m_i = cube->player_y;
	cube->m_j = cube->player_x;

	cube->map_s.mini_cub_h = CUBE_H;
	cube->map_s.mini_cub_w = CUBE_W;
	
	cube->x = cube->player_x * CUBE_W;
	cube->y = cube->player_y * CUBE_H;


	cube->a = (cube->player_x * cube->map_s.mini_cub_w);
	cube->d = (cube->player_x * cube->map_s.mini_cub_w) + cube->map_s.mini_cub_w;
	cube->w = (cube->player_y * cube->map_s.mini_cub_h);
	cube->s = (cube->player_y * cube->map_s.mini_cub_h) + cube->map_s.mini_cub_h;

	printf("cube->d:%d\n cube->a:%d\n", cube->d, cube->a);
	printf("bir kup genislik %d yukseklik %d\n", cube->map_s.mini_cub_w, cube->map_s.mini_cub_h);
}
