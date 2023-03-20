#ifndef CUB3D_H
#define CUB3D_H

#define CUBE_H 8
#define CUBE_W 8

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00

# define ESC 53
# define W	 13
# define A	 0
# define S	 1
# define D	 2
# define RA	 123
# define LA	 124

#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include <math.h>
#include <fcntl.h>
#include <stdbool.h>

// typedef struct s_mlx
// {
// 	void	*mlx;
// 	void	*win;
// 	void	*ptr_minimap_img;
// } t_mlx;

typedef struct s_map
{
	int		map_width;
	int		map_height;
	void	*img_ptr;
	void	*img_ptr_player;
	int		*addr;
	int		*player_addr;
	int		mini_cub_h;
	int		mini_cub_w;
	double		p_movement_mm;
} t_map;


typedef struct s_cube
{
	int		win_width;
	int		win_height;
	char	**map_file;
	char	**map;
	int		map_long;
	int		count;
	void	*mlx;
	void	*win;
	int		*win_addr;
	void	*win_img_ptr;
	t_map	map_s;
	double y;
	double x;
	int m_i;
	int m_j;
	bool d;

	bool a;
	bool w;
	bool s;
	bool ra;
	bool la;
	double player_x;
	double player_y;
	double player_angle;

	int angle;
} t_cube;

int	key_press(int key, t_cube *cube);
int	key_release(int key, t_cube *cube);

int		name_chck(char **av);
int		map_init(char **av, t_cube *cube);
void	check_map_size(t_cube *cube);
void	fill_map_spaces(t_cube *cube);
//////////render//////////
int	render(t_cube *cube);

void	init(t_cube *cube);
void	init_win(t_cube *cube);
void	init_img(t_cube *cube);

void	draw_win(t_cube *cube);
void	draw_img(t_cube *cube);
void	draw_minimap(t_cube *cube);
void	draw_player(t_cube *cube);
void	draw_ray(t_cube *cube);
unsigned long	rgb_to_hex(int transparent ,int r, int g, int b);

//void	handle_keypress(t_cube *cube);
void	handle_keypress(t_cube *cube);
//void	handle_esc(t_cube *cube);

#endif
