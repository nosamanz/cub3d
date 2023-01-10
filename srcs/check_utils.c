/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:07:58 by osarihan          #+#    #+#             */
/*   Updated: 2023/01/10 13:37:29 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	cube->map = malloc(sizeof(char **) * 100);
	while (1)
	{
		str = get_next_line(fd);
		if (str != NULL)
			cube->map[i] = ft_strdup(str);
		else
			break;
		free(str);
		i++;
	}
	return (1);
}

// int	map_check(char *av, t_cube *cube)
// {
// 	char	*str;
// 	int		i;
// }
