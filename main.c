#include "so_long.h"
#include  "minilibx-linux/mlx.h"
#include "libft/libft.h"


int main(int argc,char **argv)
{
    t_map mapdata;
    t_readmap readdata;
    t_img img;
    int i;

    if (argc != 2)
        return (ft_printf("Error:\nArgument not found\n"), 1);
    i = 0;
    while (argv[1][i] != '\0')
        i++;
    bzero(&mapdata, sizeof(mapdata));
    bzero(&readdata, sizeof(readdata));
    bzero(&img, sizeof(img));
    mapdata.readdata = &readdata;
    mapdata.img = &img;
    if (checkallmap(argv, &mapdata, i) == 1)
        return(1);
    else if (moves(&mapdata) ==  1)
        return(1);
}
