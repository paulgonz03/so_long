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
    else if (moves(&mapdata) ==  1)
        return(printf("error de moves\n"), 1);
}
