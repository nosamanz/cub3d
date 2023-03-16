/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:40:43 by osarihan          #+#    #+#             */
/*   Updated: 2023/03/16 15:06:29 by oozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close(void)
{
	exit (0);
	return (0);
}

//&& map_init(av, &cube) && map_check(av, &cube)
int main(int ac, char **av)
{
	t_cube cube;

	int i = 0;
	if (ac == 2 && name_chck(av) && map_init(av, &cube))
	{
		check_map_size(&cube);
		fill_map_spaces(&cube);
		init(&cube);

		cube.player_angle = 90.0;
		cube.angle = 0;
		cube.w = false;
		cube.a = false;
		cube.s = false;
		cube.d = false;

		mlx_hook(cube.win, 3, 1L<<1, &key_release, &cube);
		mlx_hook(cube.win, 2, 1L<<0, &key_press, &cube);
		mlx_hook(cube.win, 2, 1L<<0, &key_press, &cube);
		mlx_hook(cube.win, 17, (0L), ft_close, main);
		mlx_loop_hook(cube.mlx, &render, &cube);
		mlx_loop(cube.mlx);
	}
	else
		write (2, "Error\n", 6);
}
