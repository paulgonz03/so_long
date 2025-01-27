#include "so_long.h"
#include  "minilibx-linux/mlx.h"

int main(int argc,char **argv)
{
    int i;
    t_map mapdata;
    t_readmap readdata;
    t_img img;

    i = 0;
    if (argc != 2)
        return (printf("error de argc\n"), 1);
    while (argv[1][i] != '\0')
        i++;
    bzero(&mapdata, sizeof(mapdata));
    bzero(&readdata, sizeof(readdata));
    bzero(&img, sizeof(img));
    mapdata.readdata = &readdata;
    mapdata.img = &img;
    if (checkallmap(argv, &mapdata, i) == 1)
        return(printf("error de checkallmap\n"), 1);
    else
    {
        img.countmoves = 1;
        img.mlx = mlx_init();
        if (saveimg(&img) == 1)
            return(printf("error de saveimg\n"), 1);
        img.win = mlx_new_window(img.mlx, (strlen(mapdata.copymap[0]) -1)*TEXTURE_SIZE, readdata.lines*TEXTURE_SIZE, "so_long paula");
        pixeltoimage(&mapdata, &img);
        ft_lookP(mapdata.copymap, &img);
        mlx_hook(img.win, CLOSEWIN, 0, closewin, &img);
        mlx_key_hook(img.win, moveplyr, &mapdata);
        mlx_loop(img.mlx);
    }  
}
