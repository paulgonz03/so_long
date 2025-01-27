#include "so_long.h"

char **ft_readmap(char **argv, t_map *mapdata)
{
    int fd;
    int i;
    int f;

    i = 0;
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
    mapdata->readdata->map = calloc ((mapdata->readdata->lines + 1), sizeof(char *));
    if(!mapdata->readdata->map)
        return(NULL);
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        return (NULL);
    mapdata->readdata->map[i] = get_next_line(fd);
    while (mapdata->readdata->map[i++] != NULL)
    {
        mapdata->readdata->map[i] = get_next_line(fd);
        if (mapdata->readdata->map[i] == NULL)
            break;
        if (mapdata->readdata->map[i][0] == '\n')
        {
            f = 0;
            while (f <= mapdata->readdata->lines)
                free (mapdata->readdata->map[f++]);
            free (mapdata->readdata->map);
            return (NULL);
        }
    }
    return (mapdata->readdata->map);
}

void printmap(char **map)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (map[y])
    {
        while (map[y][x])
        {
            printf("%c", map[y][x]);
            x++;
        }
        x = 0;
        y++;
    }
    printf("\n");
    return ;
}
void copymap(t_map *mapdata, t_readmap *readdata)
{
    int j;

    j = 0;
    mapdata->copymap = calloc(readdata->lines + 1,  sizeof(char *));
    while (mapdata->mape[j])
    {
        mapdata->copymap[j] = calloc(strlen(mapdata->mape[j]) + 1, sizeof (char));
        j++;
    }
    j = 0;
    while (mapdata->mape[j])
    {
       strcpy (mapdata->copymap[j], mapdata->mape[j]);
        j++;
    }
    return ;
}
