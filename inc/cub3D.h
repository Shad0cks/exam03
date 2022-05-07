/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeshaye <pdeshaye@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 06:28:33 by abelache          #+#    #+#             */
/*   Updated: 2022/05/07 12:43:20 by pdeshaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#   define CUB3D_H


# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
#include <math.h>

# include "../libs/libft/libft.h"
# include "../libs/minilibx/mlx.h"

#define mapWidth 24
#define mapHeight 24
#define screenWidth 1600
#define screenHeight 900

typedef struct	s_player {
	double	x;
	double	y;
	double 	pdx;
	double 	pdy;
	double 	planeX;
	double 	planeY;
	double 	speed;
	double 	rotSpeed;
	
}				t_player;


typedef struct	s_image {
	void	* img;
	char	* addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct 	s_map{
	int		sol;
	int		plafond;
	t_image	*murnord;
	t_image	*mursud;
	t_image	*murest;
	t_image	*murwest;
}				t_map;

typedef struct 	s_mlx{

    void 			*mlx;
    void			*window;
    char			**buffer;
	int				compteur;
	int 			height_wind;
	int 			width_wind;
	int 			prop_size;
	
	t_map			*map;
	t_image			*image;
	t_player		*player;
}				t_mlx;

void 	print_background(t_mlx *mlx_st, unsigned int ciel, unsigned int sol);
void 	put_pxl_to_img(t_mlx *mlx_st, int x, int y, unsigned int color);
void 	draw_line(t_mlx *mlx_st, int x, int beginY, int endY, int color);
void	raycasting(t_mlx *mlx_st);

void 	move_left(t_mlx *mlx_st);
void 	move_right(t_mlx *mlx_st);
void 	move_down(t_mlx *mlx_st);
void 	move_up(t_mlx *mlx_st);

void	generate_texture(t_mlx *mlx_st);

#endif