#include "so_long.h"
#include  "minilibx-linux/mlx.h"

void pixeltoimage(t_map *mapdata, t_img *img)
{
    int i;
    int j;
    int x = 0;
    int y = 0;


    j = 0;
    img->win = mlx_new_window(img->mlx, 1920, 1080, "Hello world!");
    while (mapdata->copymap[j])
    {
        i = 0;
        x = 0;
        while (mapdata->copymap[j][i] && mapdata->copymap[j][i] != '\n')
        {
            if (mapdata->copymap[j][i] == '0')
            {
                printf("0\n");
                img = mlx_xpm_file_to_image(img->mlx, "./textures/floor.xpm", &img->img_width, &img->img_height);
                mlx_put_image_to_window(img->mlx, img->win, img->img, x*65, y*65);
            }
            if (mapdata->copymap[j][i] == '1')
            {
                img = mlx_xpm_file_to_image(img->mlx, "./textures/wall.xpm", &img->img_width, &img->img_height);
                printf("1\n");
                mlx_put_image_to_window(img->mlx, img->win, img->img, x*65, y*65);
            }            
            if (mapdata->copymap[j][i] == 'E')
            {
                printf("e\n");
                img = mlx_xpm_file_to_image(img->mlx, "./textures/exit.xpm", &img->img_width, &img->img_height);
                mlx_put_image_to_window(img->mlx, img->win, img->img, x*65, y*65);
            }            
            if (mapdata->copymap[j][i] == 'C')
            {
                printf("c\n");
                img = mlx_xpm_file_to_image(img->mlx, "./textures/star.xpm", &img->img_width, &img->img_height);
                mlx_put_image_to_window(img->mlx, img->win, img->img, x*65, y*65);
            }
            if (mapdata->copymap[j][i] == 'P')
            {
                printf("p\n");
                img = mlx_xpm_file_to_image(img->mlx, "./textures/plyr.xpm", &img->img_width, &img->img_height);
                mlx_put_image_to_window(img->mlx, img->win, img->img, x*65, y*65);
            }
            x++;
            i++;
        }
        y++;
        j++;
    }
}

int moveplyr(t_map *mapdata, t_img *img)
{
    ft_lookforP(mapdata, mapdata->copymap);
    printf("%d\n", mapdata->x);
    printf("%d\n", mapdata->y);
    if(img->keycode == keyD || img->keycode == keyright)
    {
        if (mapdata->copymap[mapdata->y][mapdata->x+1] != '1')
        {
            mapdata->copymap[mapdata->y][mapdata->x] = '0';
            mapdata->copymap[mapdata->y][mapdata->x + 1] = 'P';
        }
    }
    if(img->keycode == keyA || img->keycode == keyleft)
    {
        if (mapdata->copymap[mapdata->y][mapdata->x-1] != '1')
        {
            mapdata->copymap[mapdata->y][mapdata->x] = '0';
            mapdata->copymap[mapdata->y][mapdata->x-1] = 'P';
        }
    }
    if(img->keycode == keyS || img->keycode == keydown)
    {
        if (mapdata->copymap[mapdata->y+1][mapdata->x] != '1')
        {
            mapdata->copymap[mapdata->y][mapdata->x] = '0';
            mapdata->copymap[mapdata->y+1][mapdata->x] = 'P';
        }
    }
    if(img->keycode == keyW || img->keycode == keyup)
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


