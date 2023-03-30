/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:40:43 by osarihan          #+#    #+#             */
/*   Updated: 2023/03/30 01:58:59 by oozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close(void)
{
	exit (0);
	return (0);
}

int main(int ac, char **av)
{
	t_cube cube;
	cube.map_status = true;
	cube.is_wall = false;

	if (ac == 2 && name_chck(av) && map_init(av, &cube))
	{
		check_map_size(&cube);
		// G yi kontrol edebilmek icin check map in icine yazildi
		// fill_map_spaces(&cube);
		init(&cube);

		mlx_hook(cube.win, 3, 1L<<1, &key_release, &cube);
		mlx_hook(cube.win, 2, 1L<<0, &key_press, &cube);
		mlx_hook(cube.win, 17, (0L), ft_close, main);
		mlx_loop_hook(cube.mlx, &render, &cube);
		mlx_loop(cube.mlx);
	}
	else
		write (2, "Error\n", 6);
}
