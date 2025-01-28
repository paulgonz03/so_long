#include "so_long.h"
#include  "minilibx-linux/mlx.h"

int moves (t_map *mapdata)
{
    mapdata->img->countmoves = 1;
    mapdata->img->mlx = mlx_init();
    if (saveimg(mapdata->img) == 1)
        return(printf("error de saveimg\n"), 1);
    mapdata->img->win = mlx_new_window(mapdata->img->mlx, (strlen(mapdata->copymap[0]) -1)*TEXTURE_SIZE,  mapdata->readdata->lines*TEXTURE_SIZE, "so_long paula");
    pixeltoimage(mapdata);
    ft_lookP(mapdata->copymap, mapdata->img);
    mlx_hook(mapdata->img->win, CLOSEWIN, 0, closewin, mapdata->img);
    mlx_key_hook(mapdata->img->win, moveplyr, &mapdata);
    mlx_loop(mapdata->img->mlx);
    return(0);
}

int saveimg(t_img *img)
{
    img->imgs[FLOOR] = mlx_xpm_file_to_image(img->mlx, FLOOR_TEXTURE, &img->img_width, &img->img_height);
    img->imgs[WALL] = mlx_xpm_file_to_image(img->mlx, WALL_TEXTURE, &img->img_width, &img->img_height);
    img->imgs[EXIT]= mlx_xpm_file_to_image(img->mlx, EXIT_TEXTURE, &img->img_width, &img->img_height);
    img->imgs[STAR] = mlx_xpm_file_to_image(img->mlx, STAR_TEXTURE, &img->img_width, &img->img_height);
    img->imgs[PLYR] = mlx_xpm_file_to_image(img->mlx, PLYR_TEXTURE, &img->img_width, &img->img_height);
    if (!img->imgs[FLOOR] || !img->imgs[WALL] || !img->imgs[EXIT] || !img->imgs[STAR] || !img->imgs[PLYR])
        return(1);
    return(0);
}
void pixeltoimage(t_map *mapdata) 
{
    mapdata->img->y = 0;
    while (mapdata->copymap[mapdata->img->y])
    {
        mapdata->img->x = 0;
        while (mapdata->copymap[mapdata->img->y][mapdata->img->x]  && mapdata->copymap[mapdata->img->y][mapdata->img->x] != '\n')
        {
            if (mapdata->copymap[mapdata->img->y][mapdata->img->x] == '0')
                mlx_put_image_to_window(mapdata->img->mlx, mapdata->img->win, mapdata->img->imgs[FLOOR], mapdata->img->x*TEXTURE_SIZE, mapdata->img->y*TEXTURE_SIZE);
            if (mapdata->copymap[mapdata->img->y][mapdata->img->x] == '1')
                mlx_put_image_to_window(mapdata->img->mlx, mapdata->img->win, mapdata->img->imgs[WALL], mapdata->img->x*TEXTURE_SIZE, mapdata->img->y*TEXTURE_SIZE);          
            if (mapdata->copymap[mapdata->img->y][mapdata->img->x] == 'E')
                mlx_put_image_to_window(mapdata->img->mlx, mapdata->img->win, mapdata->img->imgs[EXIT] , mapdata->img->x*TEXTURE_SIZE, mapdata->img->y*TEXTURE_SIZE);
            if (mapdata->copymap[mapdata->img->y][mapdata->img->x] == 'C')
                mlx_put_image_to_window(mapdata->img->mlx, mapdata->img->win, mapdata->img->imgs[STAR], mapdata->img->x*TEXTURE_SIZE, mapdata->img->y*TEXTURE_SIZE);
            if (mapdata->copymap[mapdata->img->y][mapdata->img->x] == 'P')
                mlx_put_image_to_window(mapdata->img->mlx, mapdata->img->win, mapdata->img->imgs[PLYR] , mapdata->img->x*TEXTURE_SIZE + 15, mapdata->img->y*TEXTURE_SIZE);
            mapdata->img->x++;
        }
        mapdata->img->y++;
    }
}

void ft_lookP(char **copymap, t_img *img)
{
    while (copymap[img->looky])
    {
        while (copymap[img->looky][img->lookx])
        {
            if (copymap[img->looky][img->lookx] == 'P')
                return ;
            img->lookx++;;
        }
        img->lookx = 0;
        img->looky++;
    }
}
int closewin(t_img *img)
{
    mlx_destroy_window(img->mlx, img->win);
    exit(EXIT_SUCCESS);
}



