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
        return (1);
    while (argv[1][i] != '\0')
        i++;
    bzero(&mapdata, sizeof(mapdata));
    bzero(&readdata, sizeof(readdata));
    bzero(&img, sizeof(img));
    if (i > 4 && argv[1][i - 4] == '.' && argv[1][i - 3] == 'b' &&  argv[1][i - 2] == 'e' && argv[1][i - 1] == 'r')
    {
        mapdata.mape = ft_readmap(argv, &readdata);
        if (mapdata.mape == NULL)
            return (printf("salto de linea o vacio\n"), 1);
        if (ft_checkmap(&mapdata) == 1)
            return(printf("error de cheakmap\n"), 1);//if ft_checkmap == 1 beacause if the map is not valid its gonna give you leaks
        if (ft_cheakmatrix(&mapdata, readdata.lines) == 1)
            return(printf("error de cheakmatrix\n"), 1);
        if (ft_cheakwalls(&mapdata, &readdata) == 1)
            return(printf("error de cheakwalls\n"), 1);
        ft_lookforP(&mapdata, mapdata.mape);
        copymap(&mapdata, &readdata);
        ft_flood_fill(&mapdata, mapdata.x, mapdata.y);
        if (cheakprintmap(&mapdata) == 1)
            return(printf("error de cheakprintmap"), 1);
    }
    // else
    //     return(printf("no hay .ber\n"), 1);
    

	img.mlx = mlx_init();

    if (saveimg(&img) == 1)
        return(printf("error de saveimg\n"), 1);
    img.win = mlx_new_window(img.mlx, (strlen(mapdata.copymap[0]) -1)*TEXTURE_SIZE, readdata.lines*TEXTURE_SIZE, "so_long paula");
    pixeltoimage(&mapdata, &img);
    ft_lookP(mapdata.copymap, &img);
    mlx_key_hook(img.win, moveplyr, &img);
    mlx_loop(img.mlx);
}