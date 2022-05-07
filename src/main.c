/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeshaye <pdeshaye@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 09:39:28 by abelache          #+#    #+#             */
/*   Updated: 2022/05/06 17:02:55 by pdeshaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"


int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int	key_listen(int keycode, t_mlx *params)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 126)
		move_up(params);
	if (keycode == 125)
		move_down(params);
	if (keycode == 123)
		move_right(params);
	if (keycode == 124)
		move_left(params);
	return (0);
}

void	mlx_init_t(t_mlx *mlx_st, t_map *map)
{
	mlx_st->map = map;
	
	mlx_st->height_wind = 900;
	mlx_st->width_wind = 1600;
	generate_texture(mlx_st);
	
	mlx_st->mlx = mlx_init();
	mlx_st->image->img = mlx_new_image(mlx_st->mlx, mlx_st->width_wind, mlx_st->height_wind);
	mlx_st->image->addr = mlx_get_data_addr(mlx_st->image->img, &mlx_st->image->bits_per_pixel, &mlx_st->image->line_length,
								&mlx_st->image->endian);

	if (mlx_st->mlx == NULL)
		exit(-1);
	mlx_st->window = mlx_new_window(mlx_st->mlx, mlx_st->width_wind,
			(mlx_st->height_wind), "CUBE 3D");
}

int main(int argc, char **argv)
{
	(void)argv;
	if (argc == 2)
		;//checkfile(argv[1]);
	else
		printf("Error\n");
		
		
	t_map			map;
	t_image			image;
	t_mlx			mlx_st;
	t_player		player;
	
	player.x = 12;
	player.y = 12;
	player.speed = 0.15;
	player.pdx = -1;
	player.pdy = 0;
	player.planeX = 0;
	player.planeY = 1.0;
	player.rotSpeed = 0.15;
		
	mlx_st.player = &player;
	mlx_st.image = &image;
	mlx_init_t(&mlx_st, &map);

	mlx_hook(mlx_st.window, 2, (1L << 13), key_listen, &mlx_st);
	print_background(&mlx_st, 0x000, 0x000);
	raycasting(&mlx_st);
	mlx_put_image_to_window(mlx_st.mlx, mlx_st.window, mlx_st.image->img, 0, 0);
	mlx_loop(mlx_st.mlx);
	return (0);
}