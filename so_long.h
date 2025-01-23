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

#define keyA 97
#define keyS 115
#define keyD 100
#define keyW 119
#define keyup 65362
#define keyright 65363
#define keydown 65364
#define keyleft 65361
#define keyESC 65307


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
    int counterC;
    int x;
    int y;
    char **copymap;
} t_map;

typedef struct	s_img {
	void	*mlx;
	void	*win;
    void	*img;
    int     keycode;
	int		img_width;
	int		img_height;
} t_img;



char	*get_next_line(int fd);
char	*extract_line(char *aux_read);
char	*remove_first_line(char *statica);
int		mystrlen(char *str);
char	*mystrjoin(char *statica, char *aux_read);
char	*get_read(int fd, char *statica);
char	*aux_get_read(int fd, char *statica, char *aux_read);
char **ft_readmap(char **argv, t_readmap *readmap);
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
void pixeltoimage(t_map *mapdata, t_img *img);
int moveplyr(t_map *mapdata, t_img *img);

#endif