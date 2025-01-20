#include "so_long.h"

char **ft_readmap(char **argv, t_readmap *readdata)
{
    int fd;
    int i;
    int f;

    i = 0;
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        return (NULL);
    readdata->temp = get_next_line(fd);
    while (readdata->temp != NULL)
    {
        free(readdata->temp);
        readdata->temp = get_next_line(fd);
        readdata->lines++;
    }
    close (fd);
    readdata->map = calloc ((readdata->lines + 1), sizeof(char *));
    if(!readdata->map)
        return(NULL);
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        return (NULL);
    readdata->map[i] = get_next_line(fd);
    while (readdata->map[i++] != NULL)
    {
        readdata->map[i] = get_next_line(fd);
        if (readdata->map[i] == NULL)
            break;
        if (readdata->map[i][0] == '\n')
        {
            f = 0;
            while (f <= readdata->lines)
                free (readdata->map[f++]);
            free (readdata->map);
            return (NULL);
        }
    }
    return (readdata->map);
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
