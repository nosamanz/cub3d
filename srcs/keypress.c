#include "cub3d.h"

void	handle_keypress(int keysym, t_cube *cube)
{
	if (keysym == D && cube->i < MINIMAP_WIDTH)
			cube->i += 1;
	else if (keysym == A && cube->i - 1 > 0)
		cube->i -= 1;
	else if (keysym == S && cube->y + 1 < MINIMAP_HEIGHT)
		cube->y += 1;
	else if (keysym == W && cube->y - 1 > 0)
		cube->y -= 1;
	printf("cube->i:%d\n cube->y:%d\n", cube->i, cube->y);
}
