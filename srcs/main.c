/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:40:43 by osarihan          #+#    #+#             */
/*   Updated: 2023/01/24 19:04:17 by oozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
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
		//render(&cube);
		// mlx_hook(cube.win, 2, 1L << 0, &handle_keypress, &cube);
		// mlx_hook(cube.win, 3, 1L << 1, &handle_keypress2, &cube);
		cube.player_angle = 90.0;
		cube.w = false;
		cube.a = false;
		cube.s = false;
		cube.d = false;

		mlx_hook(cube.win, 3, 1L<<1, &key_release, &cube);
		mlx_hook(cube.win, 2, 1L<<0, &key_press, &cube);
		mlx_loop_hook(cube.mlx, &render, &cube);
		mlx_loop(cube.mlx);
	}
	else
		write (2, "Error\n", 6);
}
