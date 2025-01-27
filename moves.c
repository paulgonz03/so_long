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
    img->y = 0;
    while (mapdata->copymap[img->y])
    {
        img->x = 0;
        while (mapdata->copymap[img->y][img->x]  && mapdata->copymap[img->y][img->x] != '\n')
        {
            if (mapdata->copymap[img->y][img->x] == '0')
                mlx_put_image_to_window(img->mlx, img->win, img->imgs[FLOOR], img->x*TEXTURE_SIZE, img->y*TEXTURE_SIZE);
            if (mapdata->copymap[img->y][img->x] == '1')
                mlx_put_image_to_window(img->mlx, img->win, img->imgs[WALL], img->x*TEXTURE_SIZE, img->y*TEXTURE_SIZE);          
            if (mapdata->copymap[img->y][img->x] == 'E')
                mlx_put_image_to_window(img->mlx, img->win, img->imgs[EXIT] , img->x*TEXTURE_SIZE, img->y*TEXTURE_SIZE);
            if (mapdata->copymap[img->y][img->x] == 'C')
                mlx_put_image_to_window(img->mlx, img->win, img->imgs[STAR], img->x*TEXTURE_SIZE, img->y*TEXTURE_SIZE);
            if (mapdata->copymap[img->y][img->x] == 'P')
                mlx_put_image_to_window(img->mlx, img->win, img->imgs[PLYR] , img->x*TEXTURE_SIZE + 15, img->y*TEXTURE_SIZE);
            img->x++;
        }
        img->y++;
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



