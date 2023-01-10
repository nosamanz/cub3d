/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:07:58 by osarihan          #+#    #+#             */
/*   Updated: 2023/01/10 17:16:11 by oozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	take_map(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cube->map_file[i][0] != '1' && cube->map_file[i][0] != '0')
		i++;
	cube->map = malloc(sizeof(char **) * 10000);
	while (cube->map_file[i])
	{
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
	take_map(cube);
	return (1);
}

// int	map_check(char *av, t_cube *cube)
// {
// 	char	*str;
// 	int		i;
// }
