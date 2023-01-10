/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:40:43 by osarihan          #+#    #+#             */
/*   Updated: 2023/01/10 13:44:06 by osarihan         ###   ########.fr       */
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
		while (cube.map[i] != NULL)
		{
			printf ("%s", cube.map[i]);
			i++;
		}
		printf("\nvalid map bro\n");
	}
	else
		write (2, "Error\n", 6);
}