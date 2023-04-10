#include "cub3d.h"

void	init(t_cube *cube)
{
	init_win(cube);
	init_img(cube);
	init_xpm(cube);

	cube->w = false;
	cube->a = false;
	cube->s = false;
	cube->d = false;
	cube->ra = false;
	cube->la = false;
	cube->m = false;
}

void	init_win(t_cube *cube)
{
	int	x;
	int	y;
	int	z;

	cube->mlx = mlx_init();
	cube->win = mlx_new_window(cube->mlx, cube->win_width, cube->win_height, "cub3d");
	cube->win_img_ptr = mlx_new_image(cube->mlx, cube->win_width, cube->win_height);
	cube->win_addr = (int *)mlx_get_data_addr(cube->win_img_ptr, &x, &y, &z);
}

void	init_img(t_cube *cube)
{
	int	x;
	int	y;
	int	z;

	cube->map_s.img_ptr = mlx_new_image(cube->mlx, cube->map_s.map_width, cube->map_s.map_height);
	cube->map_s.addr = (int *)mlx_get_data_addr(cube->map_s.img_ptr, &x, &y, &z);
}

void	init_xpm(t_cube *cube)
{
	int (i) = 0;
	cube->xpm[0].img.ptr = mlx_xpm_file_to_image(cube->mlx,
			cube->NO[1], &cube->xpm[0].height, &cube->xpm[0].width);
	cube->xpm[1].img.ptr = mlx_xpm_file_to_image(cube->mlx,
			cube->SO[1], &cube->xpm[1].height, &cube->xpm[1].width);
	cube->xpm[2].img.ptr = mlx_xpm_file_to_image(cube->mlx,
			cube->EA[1], &cube->xpm[2].height, &cube->xpm[2].width);
	cube->xpm[3].img.ptr = mlx_xpm_file_to_image(cube->mlx,
			cube->WE[1], &cube->xpm[3].height, &cube->xpm[3].width);
	while (i < 4)
	{
		cube->xpm[i].img.addr = (int *)mlx_get_data_addr(cube->xpm[i].img.ptr,
				&cube->xpm[i].img.bpp, &cube->xpm[i].img.line_size,
				&cube->xpm[i].img.endian);
		i++;
	}
}
