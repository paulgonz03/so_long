#include "so_long.h"
#include "libft/libft.h"

int checkallmap(char **argv, t_map *mapdata, int i)
{
    if (i > 4 && argv[1][i - 4] == '.' && argv[1][i - 3] == 'b' &&  argv[1][i - 2] == 'e' && argv[1][i - 1] == 'r')
    {
        mapdata->mape = readmap(argv, mapdata);
        if (mapdata->mape == NULL)
            return (ft_printf("Error:\nNew line or empty argument\n"), 1);
        if (checkmap(mapdata) == 1)
            return(ft_free(mapdata->mape), ft_printf("Error:\nCheakmap\n"), 1);
        if (cheakmatrix(mapdata, mapdata->readdata->lines) == 1)
            return(ft_free(mapdata->mape), ft_printf("Error:\nCheakmatrix\n"), 1);
        if (cheakwalls(mapdata, mapdata->readdata) == 1)
            return(ft_free(mapdata->mape), ft_printf("Error:\nCheakwalls\n"), 1);
        lookforP(mapdata, mapdata->mape);
        if (copymap(mapdata, mapdata->readdata) == 1)
            return(ft_printf("Error:\nCopymap\n"), 1);
        ft_flood_fill(mapdata, mapdata->x, mapdata->y);
        if (cheakprintmap(mapdata) == 1)
            return(ft_free(mapdata->mape), ft_free (mapdata->copymap), ft_printf("Error:\nCheakprintmap\n"), 1);
    }
    else
        return(ft_printf("Error:\n.ber not found\n"), 1);
    return(0);
}   

int checkmap(t_map *mapdata)
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

int cheakmatrix(t_map *mapdata, size_t linesnum)
{
    size_t y;
    int compare;
    int i;

    y = 1;
    linesnum--;
    compare = ft_strlen (mapdata->mape[0]);
    while (mapdata->mape[y])
    {
        i = ft_strlen(mapdata->mape[y]);
        if (y == linesnum)
            compare--;
        if (i != compare)
            return (1);
        y++;
    }
    return (0);
}
int cheakwalls(t_map *mapdata, t_readmap *readdata)
{
    int i;
    int j;
    int lastcolum;
    int auxlines;

    i = 0;
    j = 0;
    auxlines = readdata->lines -1;
    lastcolum = ft_strlen(mapdata->mape[auxlines]) - 1;
    while (mapdata->mape[j++][i] && j <= auxlines)
        if (mapdata->mape[j][i] && mapdata->mape[j][i] != '\n' &&mapdata->mape[j][i] != '1')
            return (1);
    j = 0;
    while (mapdata->mape[j++][lastcolum] && j <= auxlines)
        if (mapdata->mape[j][lastcolum] && mapdata->mape[j][lastcolum] != '\n' && mapdata->mape[j][lastcolum] != '1')
            return (1);
    j = 0;
    while (mapdata->mape[j][i++] != '\0')
        if (mapdata->mape[j][i] && mapdata->mape[j][i] != '\n' && mapdata->mape[j][i] != '1')
            return (1);
    i = 0;
    while (mapdata->mape[auxlines][i++])
        if (mapdata->mape[j][i] && mapdata->mape[j][i] != '\n' && mapdata->mape[auxlines][i] != '1')
            return (1);
    return(0);
}
