#include "so_long.h"
#include  "minilibx-linux/mlx.h"

int moves (t_map *mapdata)
{
    mapdata->img->countmoves = 1;
    mapdata->img->mlx = mlx_init();
    if (saveimg(mapdata->img) == 1)
    {
        printf("error de saveimg\n"), 
        exit(EXIT_FAILURE);
    }
    mapdata->img->win = mlx_new_window(mapdata->img->mlx, (strlen(mapdata->copymap[0]) -1)*TEXTURE_SIZE,  mapdata->readdata->lines*TEXTURE_SIZE, "so_long paula");
    pixeltoimage(mapdata);
    ft_lookP(mapdata);
    mlx_hook(mapdata->img->win, CLOSEWIN, 0, closewin, mapdata->img);
    mlx_key_hook(mapdata->img->win, moveplyr, mapdata);
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
    mapdata->img->j = 0;
    while (mapdata->copymap[mapdata->img->j])
    {
        mapdata->img->i = 0;
        while (mapdata->copymap[mapdata->img->j][mapdata->img->i]  && mapdata->copymap[mapdata->img->j][mapdata->img->i] != '\n')
        {
            if (mapdata->copymap[mapdata->img->j][mapdata->img->i] == '0')
                mlx_put_image_to_window(mapdata->img->mlx, mapdata->img->win, mapdata->img->imgs[FLOOR], mapdata->img->i*TEXTURE_SIZE, mapdata->img->j*TEXTURE_SIZE);
            if (mapdata->copymap[mapdata->img->j][mapdata->img->i] == '1')
                mlx_put_image_to_window(mapdata->img->mlx, mapdata->img->win, mapdata->img->imgs[WALL], mapdata->img->i*TEXTURE_SIZE, mapdata->img->j*TEXTURE_SIZE);          
            if (mapdata->copymap[mapdata->img->j][mapdata->img->i] == 'E')
                mlx_put_image_to_window(mapdata->img->mlx, mapdata->img->win, mapdata->img->imgs[EXIT] , mapdata->img->i*TEXTURE_SIZE + 10, mapdata->img->j*TEXTURE_SIZE);
            if (mapdata->copymap[mapdata->img->j][mapdata->img->i] == 'C')
                mlx_put_image_to_window(mapdata->img->mlx, mapdata->img->win, mapdata->img->imgs[STAR], mapdata->img->i*TEXTURE_SIZE, mapdata->img->j*TEXTURE_SIZE);
            if (mapdata->copymap[mapdata->img->j][mapdata->img->i] == 'P')
                mlx_put_image_to_window(mapdata->img->mlx, mapdata->img->win, mapdata->img->imgs[PLYR] , mapdata->img->i*TEXTURE_SIZE + 2, mapdata->img->j*TEXTURE_SIZE);
            mapdata->img->i++;
        }
        mapdata->img->j++;
    }
}

void ft_lookP(t_map *mapdata)
{
    while (mapdata->copymap[mapdata->img->findy])
    {
        mapdata->img->findx = 0;
        while (mapdata->copymap[mapdata->img->findy][mapdata->img->findx])
        {
            if (mapdata->copymap[mapdata->img->findy][mapdata->img->findx] == 'P')
                return ;
            mapdata->img->findx++;;
        }
        mapdata->img->findy++;
    }
    printf("%d\n", mapdata->img->findy);
}

int closewin(t_img *img)
{
    mlx_destroy_window(img->mlx, img->win);
    exit(EXIT_SUCCESS);
}
