#include "so_long.h"

int ft_checkmap(t_map *mapdata)
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
                mapdata->countP++;
            else if (mapdata->mape[i][j] == 'E')
                mapdata->countE++;
            else if (mapdata->mape[i][j] == 'C')
                mapdata->countC++;
            else if (mapdata->mape[i][j] == '0' || mapdata->mape[i][j] == '1' || mapdata->mape[i][j] == '\n')
                i=i;
            else
                return(1);
            j++;
        }
    }
    if (mapdata->countP != 1 || mapdata->countE != 1 || mapdata->countC == 0)
        return(1);
    return (0);
}

int ft_cheakmatrix(t_map *mapdata, size_t linesnum)
{
    size_t y;
    int compare;
    int i;

    y = 1;
    linesnum--;
    compare = strlen (mapdata->mape[0]);
    while (mapdata->mape[y])
    {
        i = strlen(mapdata->mape[y]);
        if (y == linesnum)
            compare--;
        if (i != compare)
                return (1);
        y++;
    }
    return (0);
}
int ft_cheakwalls(t_map *mapdata, t_readmap *readdata)
{
    int i;
    int j;
    int lastcolum;
    int auxlines;

    i = 0;
    j = 0;
    auxlines = readdata->lines;
    auxlines--;
    lastcolum = strlen(mapdata->mape[auxlines]) - 1;
    while (mapdata->mape[j++][i] && j <= auxlines)
        if (mapdata->mape[j][i] && mapdata->mape[j][i] != '\n' &&mapdata->mape[j][i] != '1')
            return (printf("muro izquierda\n"), 1);
    j = 0;
    while (mapdata->mape[j++][lastcolum] && j <= auxlines)
        if (mapdata->mape[j][lastcolum] && mapdata->mape[j][lastcolum] != '\n' && mapdata->mape[j][lastcolum] != '1')
            return (printf("muro derecha\n"), 1);
    j = 0;
    while (mapdata->mape[j][i++] != '\0')
        if (mapdata->mape[j][i] && mapdata->mape[j][i] != '\n' && mapdata->mape[j][i] != '1')
            return (printf("muro arriba\n"), 1);
    i = 0;
    while (mapdata->mape[auxlines][i++])
        if (mapdata->mape[j][i] && mapdata->mape[j][i] != '\n' && mapdata->mape[auxlines][i] != '1')
            return (printf("muro abajo\n"), 1);
    return(0);
}


void ft_lookforP(t_map *mapdata, char **mape)
{
    while (mape[mapdata->y])
    {
        while (mape[mapdata->y][mapdata->x])
        {
            if (mape[mapdata->y][mapdata->x] == 'P')
                return ;
            mapdata->x++;
        }
        mapdata->x = 0;
        mapdata->y++;
    }
}

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
