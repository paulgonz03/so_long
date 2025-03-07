#include "so_long.h"

char **auxreadmapa(t_map *mapdata, char **argv, int fd, int j)
{
    int i;

    i = 0;
    mapdata->readdata->map = calloc ((mapdata->readdata->lines + 1), sizeof(char *));
    if(!mapdata->readdata->map)
        return(NULL);
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        return (free(mapdata->readdata->map), NULL);
    mapdata->readdata->map[i] = get_next_line(fd);
    i = 0;
    while (mapdata->readdata->map[i++] != NULL)
    {
        mapdata->readdata->map[i] = get_next_line(fd);
        if (mapdata->readdata->map[i] == NULL)
            break;
        if (mapdata->readdata->map[i][0] == '\n')
        {
            j = 0;
            while (j <= mapdata->readdata->lines)
                free (mapdata->readdata->map[j++]);
            free (mapdata->readdata->map);
            return (NULL);
        }
    }
    return (mapdata->readdata->map);
}

char **readmap(char **argv, t_map *mapdata)
{
    int fd;
    int j;

    j = 0;
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        return (NULL);
    mapdata->readdata->temp = get_next_line(fd);
    while (mapdata->readdata->temp != NULL)
    {
        free(mapdata->readdata->temp);
        mapdata->readdata->temp = get_next_line(fd);
        mapdata->readdata->lines++;
    }
    close (fd);
    return(auxreadmapa(mapdata, argv, fd, j));
}


// void printmap(char **map)
// {
//     int x;
//     int y;

//     x = 0;
//     y = 0;
//     while (map[y])
//     {
//         while (map[y][x])
//         {
//             printf("%c", map[y][x]);
//             x++;
//         }
//         x = 0;
//         y++;
//     }
//     printf("\n");
//     return ;
// }

int copymap(t_map *mapdata, t_readmap *readdata)
{
    int j;

    j = 0;
    mapdata->copymap = calloc(readdata->lines + 1,  sizeof(char *));
    if (!mapdata->copymap)
        return (free (mapdata->mape), 1);
    while (mapdata->mape[j])
    {
        mapdata->copymap[j] = calloc(strlen(mapdata->mape[j]) + 1, sizeof (char));
        if (!mapdata->copymap)
            return (ft_free(mapdata->mape), ft_free(mapdata->copymap), 1);
        j++;
    }
    j = 0;
    while (mapdata->mape[j])
    {
       strcpy(mapdata->copymap[j], mapdata->mape[j]);
        j++;
    }
    return (0);
}
void lookforP(t_map *mapdata, char **mape)
{
    while (mape[mapdata->y])
    {
        mapdata->x = 0;
        while (mape[mapdata->y][mapdata->x])
        {
            if (mape[mapdata->y][mapdata->x] == 'P')
            {
                mapdata->img->findx = mapdata->x;
                mapdata->img->findy = mapdata->y;
                return ;
            }
            mapdata->x++;
        }
        mapdata->y++;
    }
}

void ft_free(char **map)
{
    int j;

    j = 0;
    while (map[j])
    {
        free(map[j]);
        j++;
    }
    free(map);
    return ;
}
