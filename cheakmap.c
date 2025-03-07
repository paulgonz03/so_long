#include "so_long.h"

int checkallmap(char **argv, t_map *mapdata, int i)
{
    if (i > 4 && argv[1][i - 4] == '.' && argv[1][i - 3] == 'b' &&  argv[1][i - 2] == 'e' && argv[1][i - 1] == 'r')
    {
        mapdata->mape = ft_readmap(argv, mapdata);
        if (mapdata->mape == NULL)
            return (printf("salto de linea o vacio\n"), 1);
        if (ft_checkmap(mapdata) == 1)
            return(ft_free(mapdata->mape), printf("error de cheakmap\n"), 1);
        if (ft_cheakmatrix(mapdata, mapdata->readdata->lines) == 1)
            return(ft_free(mapdata->mape), printf("error de cheakmatrix\n"), 1);
        if (ft_cheakwalls(mapdata, mapdata->readdata) == 1)
            return(ft_free(mapdata->mape), printf("error de cheakwalls\n"), 1);
        ft_lookforP(mapdata, mapdata->mape);
        copymap(mapdata, mapdata->readdata);
        ft_flood_fill(mapdata, mapdata->x, mapdata->y);
        if (cheakprintmap(mapdata) == 1)
            return(ft_free(mapdata->mape), ft_free (mapdata->copymap), printf("error de cheakprintmap\n"), 1);
    }
    else
        return(printf("no hay .ber\n"), 1);
    return(0);
}   

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
                ;
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
    auxlines = readdata->lines -1;
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
