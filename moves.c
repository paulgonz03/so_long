#include "so_long.h"
#include  "minilibx-linux/mlx.h"

void pixeltoimage(t_map *mapdata, void *mlx)
{
    int i;
    int j;
    void	*img;
	int		img_width;
	int		img_height;
    void	*mlx_win;
    int x = 0;
    int y = 0;


    j = 0;
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    while (mapdata->copymap[j])
    {
        i = 0;
        x = 0;
        while (mapdata->copymap[j][i] && mapdata->copymap[j][i] != '\n')
        {
            if (mapdata->copymap[j][i] == '0')
            {
                img = mlx_xpm_file_to_image(mlx, "./textures/floor.xpm", &img_width, &img_height);
                mlx_put_image_to_window(mlx, mlx_win, img, x*30, y*30);
            }
            if (mapdata->copymap[j][i] == '1')
            {
                img = mlx_xpm_file_to_image(mlx, "./textures/wall.xpm", &img_width, &img_height);
                mlx_put_image_to_window(mlx, mlx_win, img, x*30, y*30);
            }            
            if (mapdata->copymap[j][i] == 'E')
            {
                img = mlx_xpm_file_to_image(mlx, "./textures/exit.xpm", &img_width, &img_height);
                mlx_put_image_to_window(mlx, mlx_win, img, x*30, y*30);
            }            
            if (mapdata->copymap[j][i] == 'C')
            {
                img = mlx_xpm_file_to_image(mlx, "./textures/colle.xpm", &img_width, &img_height);
                mlx_put_image_to_window(mlx, mlx_win, img, x*30, y*30);
            }
            if (mapdata->copymap[j][i] == 'P')
            {
                img = mlx_xpm_file_to_image(mlx, "./textures/plyr.xpm", &img_width, &img_height);
                mlx_put_image_to_window(mlx, mlx_win, img, x*30, y*30);
            }
            x++;
            i++;
        }
        y++;
        j++;
    }
}

int moveplyr(t_map *mapdata, int keycode)
{
    ft_lookforP(mapdata, mapdata->copymap);
    printf("%d\n", mapdata->x);
    printf("%d\n", mapdata->y);
    if(keycode == keyD || keycode == keyright)
    {
        if (mapdata->copymap[mapdata->y][mapdata->x+1] != '1')
        {
            mapdata->copymap[mapdata->y][mapdata->x] = '0';
            mapdata->copymap[mapdata->y][mapdata->x + 1] = 'P';
        }
    }
    if(keycode == keyA || keycode == keyleft)
    {
        if (mapdata->copymap[mapdata->y][mapdata->x-1] != '1')
        {
            mapdata->copymap[mapdata->y][mapdata->x] = '0';
            mapdata->copymap[mapdata->y][mapdata->x-1] = 'P';
        }
    }
    if(keycode == keyS || keycode == keydown)
    {
        if (mapdata->copymap[mapdata->y+1][mapdata->x] != '1')
        {
            mapdata->copymap[mapdata->y][mapdata->x] = '0';
            mapdata->copymap[mapdata->y+1][mapdata->x] = 'P';
        }
    }
    if(keycode == keyW || keycode == keyup)
    {
        if (mapdata->copymap[mapdata->y-1][mapdata->x] != '1')
        {
            mapdata->copymap[mapdata->y][mapdata->x] = '0';
            mapdata->copymap[mapdata->y-1][mapdata->x] = 'P';
        }
    }
    printmap(mapdata->copymap);
    return(0);
}


