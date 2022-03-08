#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "../so_long/gnl/get_next_line.h"
#include "../so_long/gnl/get_next_line.c"
#include "../so_long/gnl/get_next_line_utils.c"

typedef struct s_data {
	char	**table;
	void	*mlx;
	void	*win;
	void	*img;
	void	*obstacle;
	void	*floor;
	int		img_width;
	int		img_height;
	int		pos_y;
	int		pos_x;
	int		win_width;
	int		win_height;
	
}	t_data;

#endif