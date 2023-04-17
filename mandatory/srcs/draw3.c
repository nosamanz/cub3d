/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 23:18:21 by oozcan            #+#    #+#             */
/*   Updated: 2023/04/17 02:48:53 by oozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ray_and_3d(t_cube *cube)
{
	int (i) = 0;
	double (x) = cube->x + (CUBE_W / 2);
	double (y) = cube->y + (CUBE_W / 2);
	double (tmp_x) = x;
	double (tmp_y) = y;
	double (ray_angle) = cube->player_angle + 33.0;
	cube->rx = cos(ray_angle * (M_PI / 180.0));
	cube->ry = -sin(ray_angle * (M_PI / 180.0));
	while (i < cube->win_width)
	{
		ray_dda(cube, ray_angle, i);
		x = tmp_x;
		y = tmp_y;
		ray_angle -= 66.0 / cube->win_width;
		cube->rx = cos(ray_angle * (M_PI / 180.0));
		cube->ry = -sin(ray_angle * (M_PI / 180.0));
		i += 1;
	}
}
