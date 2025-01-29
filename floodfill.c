#include "so_long.h"

void ft_flood_fill(t_map *mapdata, int x, int y)
{   
    if (mapdata->mape[y][x] == 'x' || mapdata->mape[y][x] == '1')
        return ;
    mapdata->mape[y][x] = 'x';
    ft_flood_fill(mapdata, x, y+1);
    ft_flood_fill(mapdata, x, y-1);
    ft_flood_fill(mapdata, x+1, y);
    ft_flood_fill(mapdata, x-1, y);
}

int cheakprintmap(t_map *mapdata)
{
    int i;
    int j;

    i = -1;
    while (mapdata->mape[++i])
    {
        j = 0;
        while (mapdata->mape[i][j] != '\0')
        {
            if (mapdata->mape[i][j] == 'P')
                return(1);
            else if (mapdata->mape[i][j] == 'E')
                return(1);
            else if (mapdata->mape[i][j] == 'C')
                return(1);
            else if (mapdata->mape[i][j] == '0')
                return (1);
            else if (mapdata->mape[i][j] == 'x' || mapdata->mape[i][j] == '1' || mapdata->mape[i][j] == '\n')
                i=i;
            j++;
        }
    }
    return (0);
}