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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

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
    int y;
    int x;
    int i;
    int j;
    void   *imgs[TOTAL];
    int lookx;
    int looky;
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
    t_readmap *readdata;
    t_img *img;
} t_map;



char	*get_next_line(int fd);
char	*extract_line(char *aux_read);
char	*remove_first_line(char *statica);
int		mystrlen(char *str);
char	*mystrjoin(char *statica, char *aux_read);
char	*get_read(int fd, char *statica);
char	*aux_get_read(int fd, char *statica, char *aux_read);
char **ft_readmap(char **argv, t_map *mapdata);
int main(int argc,char **argv);
int ft_checkmap(t_map *mapdata);
int	mystrchr(const char *src, int c);
int ft_cheakmatrix(t_map *mapdata, size_t linesnum);
void ft_lookforP(t_map *mapdata, char **mape);
void ft_flood_fill(t_map *mapdata, int x, int y);
void printmap(char **map);
int cheakprintmap(t_map *mapdata);
void copymap(t_map *mapdata, t_readmap *readdata);
int ft_cheakwalls(t_map *mapdata, t_readmap *readdata);
void pixeltoimage(t_map *mapdata);
int moveplyr(int keycode,t_map *mapdata);
int saveimg(t_img *img);
void ft_lookP(char **copymap, t_img *img);
void moveup(t_map *mapdata);
void movedown(t_map *mapdata);
void moveright(t_map *mapdata);
void moveleft(t_map *mapdata);
int checkallmap(char **argv, t_map *mapdata, int i);
int closewin(t_img *img);
int moves (t_map *mapdata);

#endif
