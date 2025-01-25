#include "so_long.h"
#include  "minilibx-linux/mlx.h"

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
void pixeltoimage(t_map *mapdata, t_img *img) 
{
    img->j = 0;
    while (mapdata->copymap[img->j])
    {
        img->i = 0;
        img->x = 0;
        while (mapdata->copymap[img->j][img->i]  && mapdata->copymap[img->j][img->i] != '\n')
        {
            if (mapdata->copymap[img->j][img->i] == '0')
                mlx_put_image_to_window(img->mlx, img->win, img->imgs[FLOOR], img->x*TEXTURE_SIZE, img->y*TEXTURE_SIZE);
            if (mapdata->copymap[img->j][img->i] == '1')
                mlx_put_image_to_window(img->mlx, img->win, img->imgs[WALL], img->x*TEXTURE_SIZE, img->y*TEXTURE_SIZE);          
            if (mapdata->copymap[img->j][img->i] == 'E')
                mlx_put_image_to_window(img->mlx, img->win, img->imgs[EXIT] , img->x*TEXTURE_SIZE, img->y*TEXTURE_SIZE);
            if (mapdata->copymap[img->j][img->i] == 'C')
                mlx_put_image_to_window(img->mlx, img->win, img->imgs[STAR], img->x*TEXTURE_SIZE, img->y*TEXTURE_SIZE);
            if (mapdata->copymap[img->j][img->i] == 'P')
                mlx_put_image_to_window(img->mlx, img->win, img->imgs[PLYR] , img->x*TEXTURE_SIZE, img->y*TEXTURE_SIZE);
            img->x++;
            img->i++;
        }
        img->y++;
        img->j++;
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
int moveplyr(t_map *mapdata, t_img *img)
{
    if(img->keycode == KEYD || img->keycode == KEYRIGHT)
    {
        if (mapdata->copymap[img->looky][img->lookx+1] != '1')
        {
            mapdata->copymap[img->looky][img->lookx] = '0';
            mapdata->copymap[img->looky][img->lookx + 1] = 'P';
        }
    }
    if(img->keycode == KEYA || img->keycode == KEYLEFT)
    {
        if (mapdata->copymap[img->looky][img->lookx-1] != '1')
        {
            mapdata->copymap[img->looky][img->lookx] = '0';
            mapdata->copymap[img->looky][img->lookx-1] = 'P';
        }
    }
    if(img->keycode == KEYS || img->keycode == KEYDOWN)
    {
        if (mapdata->copymap[img->looky+1][img->lookx] != '1')
        {
            mapdata->copymap[img->looky][img->lookx] = '0';
            mapdata->copymap[img->looky+1][img->lookx] = 'P';
        }
    }
    if(img->keycode == KEYW || img->keycode == KEYUP)
    {
        if (mapdata->copymap[img->looky-1][img->lookx] != '1')
        {
            mapdata->copymap[img->looky][img->lookx] = '0';
            mapdata->copymap[img->looky-1][img->lookx] = 'P';
        }
    }
    printmap(mapdata->copymap);
    return(0);
}


