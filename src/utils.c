#include "../inc/cub3D.h"

void print_background(t_mlx *mlx_st, unsigned int ciel, unsigned int sol)
{

	int x;
	int y;

	y = 0;
	while (y < mlx_st->height_wind)
	{
		x = 0;
		while (x < mlx_st->width_wind)
		{
			if (y < mlx_st->height_wind / 2)
				put_pxl_to_img(mlx_st, x, y, ciel);
			else
				put_pxl_to_img(mlx_st, x, y, sol);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx_st->mlx, mlx_st->window, mlx_st->image->img, 0, 0);
}

void setImageData(t_mlx *mlx_st, t_image *imageStuc, void * img)
{
	imageStuc = malloc(sizeof(t_image));
	imageStuc->img = mlx_new_image(mlx_st->mlx, 64, 64);
	imageStuc->addr = mlx_get_data_addr(img, &imageStuc->bits_per_pixel, &imageStuc->line_length,
								&imageStuc->endian);
}

void put_pxl_to_img(t_mlx *mlx_st, int x, int y, unsigned int color)
{
	char	*dst;

	dst = mlx_st->image->addr + (y * mlx_st->image->line_length + x * (mlx_st->image->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_line(t_mlx *mlx_st, int x, int beginY, int endY, int color)
{
	int	i;

	i = beginY;
	while (i < endY)
	{
		put_pxl_to_img(mlx_st, x, i, color);
		i++;
	}
}

unsigned int mlx_img_pixel_get(t_image *image, int x, int y)
{
	char	*dst;
	int		color;

	dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
	color = *(unsigned int *)dst;

	return (color);
}

void raycasting(t_mlx *mlx_st)
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


	int w = mlx_st->width_wind;
	 for(int x = 0; x < w; x++)
    {
      //calculate ray position and direction
      double cameraX = 2 * x / (double)(w) - 1; //x-coordinate in camera space
      double rayDirX = mlx_st->player->pdx + mlx_st->player->planeX * cameraX;
      double rayDirY = mlx_st->player->pdy + mlx_st->player->planeY * cameraX;


      //which box of the map we're in
      int mapX = (int)(mlx_st->player->x);
      int mapY = (int)(mlx_st->player->y);

      //length of ray from current position to next x or y-side
      double sideDistX;
      double sideDistY;

       //length of ray from one x or y-side to next x or y-side
      double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
      double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
      double perpWallDist;

      //what direction to step in x or y-direction (either +1 or -1)
      int stepX;
      int stepY;

      int hit = 0; //was there a wall hit?
      int side; //was a NS or a EW wall hit?

      //calculate step and initial sideDist
      if (rayDirX < 0)
      {
        stepX = -1;
        sideDistX = (mlx_st->player->x - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - mlx_st->player->x) * deltaDistX;
      }
      if (rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (mlx_st->player->y - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - mlx_st->player->y) * deltaDistY;
      }

      //perform DDA
      while (hit == 0)
      {
        //jump to next map square, either in x-direction, or in y-direction
        if (sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        //Check if ray has hit a wall
        if (worldMap[mapX][mapY] > 0)
			hit = 1;
      } 
	    if(side == 0) perpWallDist = (sideDistX - deltaDistX);
      else          perpWallDist = (sideDistY - deltaDistY);

	        //Calculate height of line to draw on screen
      int lineHeight = (int)(screenHeight / perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
      int drawStart = -lineHeight / 2 + screenHeight / 2;
      if(drawStart < 0)drawStart = 0;
      int drawEnd = lineHeight / 2 + screenHeight / 2;
      if(drawEnd >= screenHeight)drawEnd = screenHeight - 1;

	  
      int color;
      switch(worldMap[mapX][mapY])
      {
        case 1:  color = 0xFF0000;  break; //red
        case 2:  color = 0x00FF00;  break; //green
        case 3:  color = 0x0000FF;   break; //blue
        case 4:  color = 0xFFFFFF;  break; //white
        default: color = 0xFFFF00; break; //yellow
      }

      //give x and y sides different brightness
      if (side == 1) {color = color / 2;}

      draw_line(mlx_st, x, drawStart, drawEnd, color);
    }
}


void	generate_texture(t_mlx *mlx_st)
{
	int	height;
	int	width;

	width = 64;
	height = 64;
	
	setImageData(mlx_st, mlx_st->map->murest, mlx_xpm_file_to_image(mlx_st->mlx,
			"./test/texture_est.xpm", &width, &height));
	setImageData(mlx_st, mlx_st->map->murnord, mlx_xpm_file_to_image(mlx_st->mlx,
			"./test/texture_nord.xpm", &width, &height));
	setImageData(mlx_st, mlx_st->map->murwest, mlx_xpm_file_to_image(mlx_st->mlx,
			"./test/texture_ouest.xpm", &width, &height));
	setImageData(mlx_st, mlx_st->map->mursud,  mlx_xpm_file_to_image(mlx_st->mlx,
			"./test/texture_sud.xpm", &width, &height));
}