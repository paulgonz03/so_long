#include "so_long.h"
#include  "minilibx-linux/mlx.h"

int main(int argc,char **argv)
{
    int i;
    t_map mapdata;
    t_readmap readdata;

    i= 0;
    if (argc != 2)
        return (1);
    while (argv[1][i] != '\0')
        i++;
    bzero(&mapdata, sizeof(mapdata));
    bzero(&readdata, sizeof(readdata));
    if (i > 4 && argv[1][i - 4] == '.' && argv[1][i - 3] == 'b' &&  argv[1][i - 2] == 'e' && argv[1][i - 1] == 'r')
    {
        mapdata.mape = ft_readmap(argv, &readdata);
        if (mapdata.mape == NULL)
            return (1);
        if (ft_checkmap(&mapdata) == 1)
            return(printf("error de cheakmap\n"), 1);//if ft_checkmap == 1 beacause if the map is not valid its gonna give you leaks
        if (ft_cheakmatrix(&mapdata, readdata.lines) == 1)
            return(printf("error de cheakmatrix\n"), 1);
        if (ft_cheakwalls(&mapdata, &readdata) == 1)
            return(printf("error de cheakwalls\n"), 1);
        ft_lookforP(&mapdata);
        copymap(&mapdata, &readdata);
        ft_flood_fill(&mapdata, mapdata.x, mapdata.y);
        // printmap(mapdata.mape);
        if (cheakprintmap(&mapdata) == 1)
            return(1);
    }
    	
    // void	*mlx;
	// void *img;
    // char	*relative_path = "./test.xpm";
	// int		img_width;
	// int		img_height;

	// mlx = mlx_init();
    // img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	// mlx_loop(mlx);
    // (void)img;
}
