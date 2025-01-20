#include "so_long.h"
#include  "minilibx-linux/mlx.h"

int main(int argc,char **argv)
{
    int i;
    t_map mapdata;
    t_readmap readdata;

    i = 0;
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
            return (printf("salto de linea o vacio\n"), 1);
        if (ft_checkmap(&mapdata) == 1)
            return(printf("error de cheakmap\n"), 1);//if ft_checkmap == 1 beacause if the map is not valid its gonna give you leaks
        if (ft_cheakmatrix(&mapdata, readdata.lines) == 1)
            return(printf("error de cheakmatrix\n"), 1);
        if (ft_cheakwalls(&mapdata, &readdata) == 1)
            return(printf("error de cheakwalls\n"), 1);
        ft_lookforP(&mapdata);
        copymap(&mapdata, &readdata);
        ft_flood_fill(&mapdata, mapdata.x, mapdata.y);
        if (cheakprintmap(&mapdata) == 1)
            return(printf("error de cheakprintmap"), 1);
    }
    else
        return(printf("no hay .ber\n"), 1);
    

	// t_vars	vars;

	// vars.mlx = mlx_init();
	// vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	// mlx_key_hook(vars.win, key_hook, &vars);
	// mlx_loop(vars.mlx);
}

// int	key_hook(int keycode, t_vars *vars)
// {
// 	printf("Hello from key_hook!\n");
// 	return (0);
//     keycode = keycode;
//     vars = vars;



//     A = 38
//     s = 39
//     D = 40
//     W = 25
//     esc = 53
// }

