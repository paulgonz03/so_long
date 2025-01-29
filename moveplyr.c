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
    if (keycode == KEYESC)
        closewin(mapdata->img);
    pixeltoimage(mapdata);
    return(0);
}

void moveup(t_map *mapdata)
{
    if (mapdata->copymap[mapdata->img->findy-1][mapdata->img->findx] == '1')
        return ;
    if (mapdata->copymap[mapdata->img->findy-1][mapdata->img->findx] != '1')
    {
        if (mapdata->copymap[mapdata->img->findy-1][mapdata->img->findx] == 'E')
        {
            if (mapdata->countC != 0)
                return ;
            if (mapdata->countC == 0)
                exit(EXIT_SUCCESS);
        }
        if (mapdata->copymap[mapdata->img->findy-1][mapdata->img->findx] == 'C')
            mapdata->countC--;
        mapdata->copymap[mapdata->img->findy][mapdata->img->findx] = '0';
        mapdata->copymap[mapdata->img->findy-1][mapdata->img->findx] = 'P';
    }
    mapdata->img->findy--;
    printf("%d\n", mapdata->img->countmoves);
    mapdata->img->countmoves++;
    return ;
}

void movedown(t_map *mapdata)
{
    if (mapdata->copymap[mapdata->img->findy+1][mapdata->img->findx] == '1')
        return ;
    if (mapdata->copymap[mapdata->img->findy+1][mapdata->img->findx] != '1')
    {
        if (mapdata->copymap[mapdata->img->findy+1][mapdata->img->findx] == 'E')
        {
            if (mapdata->countC != 0)
                return ;
            if (mapdata->countC == 0)
                exit(EXIT_SUCCESS);
        }
        if (mapdata->copymap[mapdata->img->findy+1][mapdata->img->findx] == 'C')
            mapdata->countC--;
        mapdata->copymap[mapdata->img->findy][mapdata->img->findx] = '0';
        mapdata->copymap[mapdata->img->findy+1][mapdata->img->findx] = 'P';
    }
    mapdata->img->findy++;
    printf("%d\n", mapdata->img->countmoves);
    mapdata->img->countmoves++;
    return ;
}

void moveright(t_map *mapdata)
{
    if (mapdata->copymap[mapdata->img->findy][mapdata->img->findx + 1] == '1')
        return ;
    if (mapdata->copymap[mapdata->img->findy][mapdata->img->findx + 1] != '1')
    {
        if (mapdata->copymap[mapdata->img->findy][mapdata->img->findx + 1] == 'E')
        {
            if (mapdata->countC != 0)
                return ;
            if (mapdata->countC == 0)
                exit(EXIT_SUCCESS);
        }
        if (mapdata->copymap[mapdata->img->findy][mapdata->img->findx + 1] == 'C')
            mapdata->countC--;
        mapdata->copymap[mapdata->img->findy][mapdata->img->findx] = '0';
        mapdata->copymap[mapdata->img->findy][mapdata->img->findx + 1] = 'P';
    }
    mapdata->img->findx++;
    printf("%d\n", mapdata->img->countmoves);
    mapdata->img->countmoves++;
    return ;
}

void moveleft(t_map *mapdata)
{
    if (mapdata->copymap[mapdata->img->findy][mapdata->img->findx-1] == '1')
        return ;
    if (mapdata->copymap[mapdata->img->findy][mapdata->img->findx-1] != '1')
    {
        if (mapdata->copymap[mapdata->img->findy][mapdata->img->findx-1] == 'E')
        {
            if (mapdata->countC != 0)
                return ;
            if (mapdata->countC == 0)
                exit(EXIT_SUCCESS);
        }
        if (mapdata->copymap[mapdata->img->findy][mapdata->img->findx-1] == 'C')
            mapdata->countC--;
        mapdata->copymap[mapdata->img->findy][mapdata->img->findx] = '0';
        mapdata->copymap[mapdata->img->findy][mapdata->img->findx-1] = 'P';
    }
    mapdata->img->findx--;
    printf("%d\n", mapdata->img->countmoves);
    mapdata->img->countmoves++;
    return ;
}
