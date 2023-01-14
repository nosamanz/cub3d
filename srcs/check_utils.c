/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:07:58 by osarihan          #+#    #+#             */
/*   Updated: 2023/01/14 17:57:17 by oozcan           ###   ########.fr       */
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
	while (cube->map_file[i] != NULL)
	{
		printf("slm\n");
		if (cube->map_file[i][0] != '1')
			break;
		cube->map[j] = ft_strdup(cube->map_file[i]);
		j++;
		i++;
	}
	printf("sa\n");
	i = 0;
	while(cube->map[i] != NULL)
	{
		ft_putstr_fd("MAP", 1);
		ft_putstr_fd(cube->map[i], 1);
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
