#include "so_long.h"
#include  "minilibx-linux/mlx.h"

int moveplyr(int keycode, t_map *mapdata)
{
    if(keycode == KEYD || keycode == KEYRIGHT)
        moveright(mapdata);
    if(keycode == KEYA || keycode == KEYLEFT)
        moveleft(mapdata);
    if(keycode == KEYS || keycode == KEYDOWN)
        movedown(mapdata);
    if(keycode == KEYW || keycode == KEYUP)
        moveup(mapdata);
    printmap(mapdata->copymap);
    return(0);
}

void moveup(t_map *mapdata)
{
    if (mapdata->copymap[mapdata->img->looky-1][mapdata->img->lookx] == '1')
        return ;
    if (mapdata->copymap[mapdata->img->looky-1][mapdata->img->lookx] != '1')
    {
        if (mapdata->copymap[mapdata->img->looky-1][mapdata->img->lookx] == 'E')
        {
            if (mapdata->countC != 0)
                return ;
            if (mapdata->countC == 0)
                exit(EXIT_SUCCESS);
        }
        if (mapdata->copymap[mapdata->img->looky-1][mapdata->img->lookx] == 'C')
            mapdata->countC--;
        mapdata->copymap[mapdata->img->looky][mapdata->img->lookx] = '0';
        mapdata->copymap[mapdata->img->looky-1][mapdata->img->lookx] = 'P';
    }
    mapdata->img->looky--;
    return ;
}
void movedown(t_map *mapdata)
{
    if (mapdata->copymap[mapdata->img->looky+1][mapdata->img->lookx] == '1')
        return ;
    if (mapdata->copymap[mapdata->img->looky+1][mapdata->img->lookx] != '1')
    {
        if (mapdata->copymap[mapdata->img->looky+1][mapdata->img->lookx] == 'E')
        {
            if (mapdata->countC != 0)
                return ;
            if (mapdata->countC == 0)
                exit(EXIT_SUCCESS);
        }
        if (mapdata->copymap[mapdata->img->looky+1][mapdata->img->lookx] == 'C')
            mapdata->countC--;
        mapdata->copymap[mapdata->img->looky][mapdata->img->lookx] = '0';
        mapdata->copymap[mapdata->img->looky+1][mapdata->img->lookx] = 'P';
    }
    mapdata->img->looky++;
    return ;
}
void moveright(t_map *mapdata)
{
    if (mapdata->copymap[mapdata->img->looky][mapdata->img->lookx + 1] == '1')
        return ;
    if (mapdata->copymap[mapdata->img->looky][mapdata->img->lookx + 1] != '1')
    {
        if (mapdata->copymap[mapdata->img->looky][mapdata->img->lookx + 1] == 'E')
        {
            if (mapdata->countC != 0)
                return ;
            if (mapdata->countC == 0)
                exit(EXIT_SUCCESS);
        }
        if (mapdata->copymap[mapdata->img->looky][mapdata->img->lookx + 1] == 'C')
            mapdata->countC--;
        mapdata->copymap[mapdata->img->looky][mapdata->img->lookx] = '0';
        mapdata->copymap[mapdata->img->looky][mapdata->img->lookx + 1] = 'P';
    }
    mapdata->img->lookx++;
    return ;
}
void moveleft(t_map *mapdata)
{
    if (mapdata->copymap[mapdata->img->looky][mapdata->img->lookx-1] == '1')
        return ;
    if (mapdata->copymap[mapdata->img->looky][mapdata->img->lookx-1] != '1')
    {
        if (mapdata->copymap[mapdata->img->looky][mapdata->img->lookx-1] == 'E')
        {
            if (mapdata->countC != 0)
                return ;
            if (mapdata->countC == 0)
                exit(EXIT_SUCCESS);
        }
        if (mapdata->copymap[mapdata->img->looky][mapdata->img->lookx-1] == 'C')
            mapdata->countC--;
        mapdata->copymap[mapdata->img->looky][mapdata->img->lookx] = '0';
        mapdata->copymap[mapdata->img->looky][mapdata->img->lookx-1] = 'P';
    }
    mapdata->img->lookx--;
    return ;
}