#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <limits.h>
#include <strings.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>




#define KEYA 97
#define KEYS 115
#define KEYD 100
#define KEYW 119
#define KEYUP 65362
#define KEYRIGHT 65363
#define KEYDOWN 65364
#define KEYLEFT 65361
#define KEYESC 65307
#define CLOSEWIN 17

#define TEXTURE_SIZE 60

#define FLOOR_TEXTURE "./textures/floor.xpm"
#define WALL_TEXTURE "./textures/wall.xpm"
#define EXIT_TEXTURE "./textures/exit.xpm"
#define STAR_TEXTURE "./textures/star.xpm"
#define PLYR_TEXTURE "./textures/plyr.xpm"

enum {
    FLOOR = 0,
    WALL,
    EXIT,
    STAR,
    PLYR,
    TOTAL
};

typedef struct	s_img {
	void	*mlx;
	void	*win;
    void	*img;
    int     keycode;
	int		img_width;
	int		img_height;
    int j;
    int i;
    void   *imgs[TOTAL];
    int findx;
    int findy;
    int countmoves;
} t_img;

typedef struct s_readmap
{
    int lines;
    char *temp;
    char **map;
} t_readmap;


typedef struct s_map
{
    char **mape;
    int countP;
    int countE;
    int countC;
    int x;
    int y;
    char **copymap;
    t_img *img;
    t_readmap *readdata;
} t_map;

char **readmap(char **argv, t_map *mapdata);
int main(int argc,char **argv);
int checkmap(t_map *mapdata);
int	mystrchr(const char *src, int c);
int cheakmatrix(t_map *mapdata, size_t linesnum);
void lookforP(t_map *mapdata, char **mape);
void ft_flood_fill(t_map *mapdata, int x, int y);
void printmap(char **map);
int cheakprintmap(t_map *mapdata);
int copymap(t_map *mapdata, t_readmap *readdata);
int cheakwalls(t_map *mapdata, t_readmap *readdata);
void pixeltoimage(t_map *mapdata);
int moveplyr(int keycode,t_map *mapdata);
int saveimg(t_img *img);
void lookP(t_map *mapdata);
void moveup(t_map *mapdata);
void movedown(t_map *mapdata);
void moveright(t_map *mapdata);
void moveleft(t_map *mapdata);
int checkallmap(char **argv, t_map *mapdata, int i);
int closewin(t_img *img);
int moves (t_map *mapdata);
void ft_free(char **map);
char **auxreadmapa(t_map *mapdata, char **argv, int fd, int f);

#endif
