

#include "so_long.h"
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


/*main para poner imagen*/
// int	main(void)
// {
// 	t_data test;
// 	void	*mlx;
// 	void	*win;
// 	int		img_width;
// 	int		img_height;

// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx,1920, 1080, "Hello world!");
// 	test.img = mlx_xpm_file_to_image(mlx, "image.xpm", &img_width, &img_height);
// 	test.addr = mlx_get_data_addr(test.img, &test.bits_per_pixel, &test.line_length, &test.endian);
// 	mlx_put_image_to_window(mlx, win, test.img, 0, 0);
// 	mlx_loop(mlx);
	
// }

void put_image(t_data *info)
{
	info->img = mlx_xpm_file_to_image(info->mlx, "image.xpm", &info->img_width, &info->img_height);
	info->addr = mlx_get_data_addr(info->img, &info->bits_per_pixel, &info->line_length, &info->endian);
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
	//mlx_loop(info->mlx);
}

int	choose_key(int key,t_data *vars)
{
	//escp : 53
	if(key == 53)
	{
		mlx_destroy_image(vars->mlx,vars->img);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	//a : 0
	//s : 1
	//d : 2
	//w : 13
	/*if(key )
	{

	}*/
	return (0);
}

int close(t_data *vars)
{
		mlx_destroy_image(vars->mlx,vars->img);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
}

int	main(void)
{
	t_data	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1080, 1080, "Hello world!");
	put_image(&vars);
	mlx_key_hook(vars.win, choose_key, &vars); //holdea las teclas 
	//mlx_hook(vars.win,5,1L<<5,close,vars.mlx);
	mlx_loop(vars.mlx);
}