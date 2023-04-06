#include "cub3d.h"

void	fill_g(t_cube *cube)
{
	int (i) = 0;
	int (j) = 0;
	while (cube->map[i])
	{
		while (cube->map[i][j] != '\0')
		{
			if (cube->map[i][j] != '1' && cube->map[i][j] != '0' && cube->map[i][j] <= 32)
				cube->map[i][j] = 'G';
			j++;
		}
		j = 0;
		i++;
	}
}

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
			while (index < cube->map_long - 1)
				new_str[index++] = 'G';
			new_str[index] = '\0';
			cube->map[i] = ft_strdup(new_str);
		}
		i++;
	}
	fill_g(cube);
	// i = 0;
	// j = 0;
	// //Map Cizme
	// while (cube->map[i])
	// {
	// 	printf("%s\n", cube->map[i]);
	// 	i++;
	// }
	// pause();
}

void	find_map_size(t_cube *cube)
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

	cube->map_height = i - 1;
	cube->map_long = longest;
}

// void	check_map_size(t_cube *cube)
// {
// 	find_map_size(cube);
// 	//G yi kontrol etmek icin buraya tasindi
// 	cube->map_s.map_width = (cube->map_long - 1) * CUBE_W;
// 	printf("mw: %d\n", cube->map_s.map_width);
// 	fill_map_spaces(cube);

// 	if (!map_check(cube))
// 	{
// 		ft_putstr_fd("Map Error !", 2);\
// 		exit(0);
// 	}

// 	cube->win_height = (cube->map_height - 1) * (CUBE_H * 4);
// 	printf("wh: %d\n", cube->win_height);
// 	cube->win_width = cube->map_long * (CUBE_W * 4);
// 	printf("ww: %d\n", cube->win_width);

// 	cube->map_s.map_height = (cube->map_height - 1) * CUBE_H;
// 	printf("mh: %d\n", cube->map_s.map_height);

// 	cube->x = cube->player_x * CUBE_W;
// 	cube->y = cube->player_y * CUBE_H;
// }

void    check_map_size(t_cube *cube)
{
    int i;
    int longest;
    int len;
    longest = 0;
    i = 0;
    while (cube->map[i] != NULL)
    {
        len = ft_strlen(cube->map[i]);
        if (len > longest)
            longest = len;
        i++;
    }
    cube->map_height = i - 1;
    cube->map_long = longest;
    //G yi kontrol etmek icin buraya tasindi
    cube->map_s.map_width = (longest - 1) * CUBE_W;
    printf("mw: %d\n", cube->map_s.map_width);
    fill_map_spaces(cube);
    if (!map_check(cube))
    {
        ft_putstr_fd("Map Error !", 2);\
        exit(0);
    }
    cube->win_height = i * (CUBE_H * 4);
    printf("wh: %d\n", cube->win_height);
    cube->win_width = (longest) * (CUBE_W * 4);
    printf("ww: %d\n", cube->win_width);
    cube->map_s.map_height = i * CUBE_H;
    printf("mh: %d\n", cube->map_s.map_height);
    cube->x = cube->player_x * CUBE_W;
    cube->y = cube->player_y * CUBE_H;
    printf("cube->d:%d\n cube->a:%d\n", cube->d, cube->a);
    // printf("bir kup genislik %d yukseklik %d\n", cube->map_s.mini_cub_w, cube->map_s.mini_cub_h);
}
