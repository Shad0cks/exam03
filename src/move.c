#include "../inc/cub3D.h"


void move_down(t_mlx *mlx_st)
{
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

	if(worldMap[(int)(mlx_st->player->x - mlx_st->player->pdx * mlx_st->player->speed)][(int)(mlx_st->player->y)] == 0) mlx_st->player->x -= mlx_st->player->pdx * mlx_st->player->speed;
    if(worldMap[(int)(mlx_st->player->x)][(int)(mlx_st->player->y - mlx_st->player->pdy * mlx_st->player->speed)] == 0) mlx_st->player->y -= mlx_st->player->pdy * mlx_st->player->speed;
    print_background(mlx_st, 0x000, 0x000);
	raycasting(mlx_st);
	mlx_put_image_to_window(mlx_st->mlx, mlx_st->window, mlx_st->image->img, 0, 0);
}

void move_right (t_mlx *mlx_st)
{
      double oldDirX = mlx_st->player->pdx;
      mlx_st->player->pdx = mlx_st->player->pdx * cos(mlx_st->player->rotSpeed) - mlx_st->player->pdy * sin(mlx_st->player->rotSpeed);
      mlx_st->player->pdy = oldDirX * sin(mlx_st->player->rotSpeed) + mlx_st->player->pdy * cos(mlx_st->player->rotSpeed);
      double oldPlaneX = mlx_st->player->planeX;
      mlx_st->player->planeX = mlx_st->player->planeX * cos(mlx_st->player->rotSpeed) - mlx_st->player->planeY * sin(mlx_st->player->rotSpeed);
      mlx_st->player->planeY = oldPlaneX * sin(mlx_st->player->rotSpeed) + mlx_st->player->planeY * cos(mlx_st->player->rotSpeed);
	print_background(mlx_st, 0x000, 0x000);
	raycasting(mlx_st);
    mlx_put_image_to_window(mlx_st->mlx, mlx_st->window, mlx_st->image->img, 0, 0);
}

void move_left(t_mlx *mlx_st)
{
	double oldDirX = mlx_st->player->pdx;
    mlx_st->player->pdx = mlx_st->player->pdx * cos(-mlx_st->player->rotSpeed) - mlx_st->player->pdy * sin(-mlx_st->player->rotSpeed);
    mlx_st->player->pdy = oldDirX * sin(-mlx_st->player->rotSpeed) + mlx_st->player->pdy * cos(-mlx_st->player->rotSpeed);
    double oldPlaneX = mlx_st->player->planeX;
    mlx_st->player->planeX = mlx_st->player->planeX * cos(-mlx_st->player->rotSpeed) - mlx_st->player->planeY * sin(-mlx_st->player->rotSpeed);
    mlx_st->player->planeY = oldPlaneX * sin(-mlx_st->player->rotSpeed) + mlx_st->player->planeY * cos(-mlx_st->player->rotSpeed);
    print_background(mlx_st, 0x000, 0x000);
	raycasting(mlx_st);
	mlx_put_image_to_window(mlx_st->mlx, mlx_st->window, mlx_st->image->img, 0, 0);
}

void move_up(t_mlx *mlx_st)
{
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

	if(worldMap[(int)(mlx_st->player->x + mlx_st->player->pdx * mlx_st->player->speed)][(int)(mlx_st->player->y)] == 0) mlx_st->player->x += mlx_st->player->pdx * mlx_st->player->speed;
    if(worldMap[(int)(mlx_st->player->x)][(int)(mlx_st->player->y + mlx_st->player->pdy * mlx_st->player->speed)] == 0) mlx_st->player->y += mlx_st->player->pdy * mlx_st->player->speed;
	print_background(mlx_st, 0x000, 0x000);
	raycasting(mlx_st);
    mlx_put_image_to_window(mlx_st->mlx, mlx_st->window, mlx_st->image->img, 0, 0);
}