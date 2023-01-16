#ifndef CUB3D_H
#define CUB3D_H

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define MINIMAP_WIDTH	WINDOW_WIDTH / 4
# define MINIMAP_HEIGHT	WINDOW_HEIGHT / 4
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00

# define ESC 53
# define W	 13
# define A	 0
# define S	 1
# define D	 2

#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include <math.h>
#include <fcntl.h>

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
} t_map;


typedef struct s_cube
{
	char	**map_file;
	char	**map;
	int		count;
	void	*mlx;
	void	*win;
	int		*win_addr;
	void	*win_img_ptr;
	t_map	map_s;
	int i;
	int y;
} t_cube;


int		name_chck(char **av);
int		map_init(char **av, t_cube *cube);
void	check_map_size(t_cube *cube);
void	fill_map_spaces(t_cube *cube);
//////////render//////////
void	render(t_cube *cube);

void	init(t_cube *cube);
void	init_win(t_cube *cube);
void	init_img(t_cube *cube);

void	draw_win(t_cube *cube);
void	draw_img(t_cube *cube);
void	draw_minimap(t_cube *cube);
void	draw_player(t_cube *cube);
unsigned long	rgb_to_hex(int transparent ,int r, int g, int b);

void	handle_keypress(int keysym, t_cube *cube);

#endif
