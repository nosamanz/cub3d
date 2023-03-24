/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:07:58 by osarihan          #+#    #+#             */
/*   Updated: 2023/03/24 18:13:45 by oozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int find_angle(int way, t_cube *cube)
{
	cube->map[(int)cube->player_y][(int)cube->player_x] = '0'; // baslangic yerini zemin yapiyoruz.
	if (!way)
		return(0);
	else
	{
		if (way == 'N')
			cube->player_angle = 90.0;
		if (way == 'S')
			cube->player_angle = 270.0;
		if (way == 'E')
			cube->player_angle = 0;
		if (way == 'W')
			cube->player_angle = 180.0;
	}
	return (1);
}

int	find_player(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cube->map[i])
	{
		while (cube->map[i][j])
		{
			if (cube->map[i][j] == 'N' || cube->map[i][j] == 'E' || cube->map[i][j] == 'W' || cube->map[i][j] == 'S')
			{
				cube->player_x = j;
				cube->player_y = i;
				return (cube->map[i][j]);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

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
	int i = 0;

	char **tmp;
	char **tmp2;

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

void	take_map(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cube->map_file[i][0] != '1' && cube->map_file[i][0] != '0' && cube->map_file[i][0] != 32)
		i++;
	cube->map = malloc(sizeof(char **) * 10000);
	while (cube->map_file[i] != NULL)
	{
		if (cube->map_file[i][0] != '1' && cube->map_file[i][0] != 32)
			break;
		cube->map[j] = ft_strdup(cube->map_file[i]);
		j++;
		i++;
	}
}

int	name_chck(char **av)
{
	int i = 0;

	while (check_char(&av[1][i], '.'))
		i++;
	if (!ft_strcmp(&av[1][i], "cub"))
		return (1);
	return (0);
}

int	map_init(char **av, t_cube *cube)
{
	int i = 0;
	char *str;
	int fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		write(2, "Map error\n", 11);
	cube->map_file = malloc(sizeof(char **) * 10000);
	while (1)
	{
		str = get_next_line(fd);
		if (str != NULL)
			cube->map_file[i] = ft_strdup(str);
		else
			break;
		free(str);
		i++;
	}
	take_color(cube);
	take_map(cube);
	if (!find_angle(find_player(cube), cube))
	{
		printf("Player Error !\n");
		exit(0);
		//return (0);
	}
	return (1);
}
