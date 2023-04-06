#ifndef CUB3D_H
#define CUB3D_H

#define CUBE_H 8
#define CUBE_W 8

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00

// # define ESC	53
// # define W	13
// # define A	0
// # define S	1
// # define D	2
// # define LA	123
// # define RA	124
// # define M	46


//FOR WINDOWS
# define ESC 65307
# define W	 119
# define A	 97
# define S	 115
# define D	 100
# define LA	 65361
# define RA	 65363
# define M	 109

# define AN 5

#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include <math.h>
#include <fcntl.h>
#include <stdbool.h>
#include <string.h>


typedef struct s_map
{
	int		map_width;
	int		map_height;
	void	*img_ptr;
	void	*img_ptr_player;
	int		*addr;
	int		*player_addr;
} t_map;


typedef struct s_cube
{
	t_map	map_s;
	int		win_width;
	int		win_height;
	char	**map_file;
	char	**map;
	int		map_long;
	int		map_height;
	void	*mlx;
	void	*win;
	int		*win_addr;
	void	*win_img_ptr;
	double y;
	double x;

	bool w;
	bool a;
	bool s;
	bool d;
	bool ra;
	bool la;
	bool m;
	double player_x;
	double player_y;
	double player_angle;
	//new
	double p_x;
	double p_y;
	double ray_x_v;
	double ray_y_v;
	double ray_x_h;
	double ray_y_h;
	double ray_dir_x;
	double ray_dir_y;
	bool	hit_h;
	bool	hit_v;
	double vdx;
	double vdy;
	double hdx;
	double hdy;
	double tmp_x;
	double tmp_y;
	double tmp2_x;
	double tmp2_y;

	int f_color[3];
	int c_color[3];

	bool map_status;
	bool is_wall;
} t_cube;

int	key_press(int key, t_cube *cube);
int	key_release(int key, t_cube *cube);

int		name_chck(char **av);
int		map_init(char **av, t_cube *cube);
int		map_check(t_cube *cube);
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
void	draw_trans_map(t_cube *cube);
void	draw_player(t_cube *cube);
void	draw_ray(t_cube *cube);
unsigned long	rgb_to_hex(int transparent ,int r, int g, int b);

//void	handle_keypress(t_cube *cube);
void	handle_keypress(t_cube *cube);
//void	handle_esc(t_cube *cube);

void	ray_dda(t_cube *cube, double angle, int i);
int	is_wall(unsigned int x, unsigned int y, t_cube *cube);
int	is_wall2(double x, double y, t_cube *cube);


#endif
