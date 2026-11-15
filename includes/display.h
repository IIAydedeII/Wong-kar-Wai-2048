#ifndef DISPLAY_H
# define DISPLAY_H
# include "libft.h"
# include <ncurses.h>
# include <stdbool.h>

# define SCREEN_PADDING 5
# define KEY_ESCAPE 27

typedef struct s_window
{
	int	screenWidth;
	int	screenHeight;
	int	boardSize;
	int	boxSize;
	int	offsetX;
	int	offsetY;
}	t_window;

int		getNumLen(int num);
void	initializeWindow(t_grid *grid);
void 	drawBoard(t_grid *grid);
void 	drawBorders(t_window *window);
void	drawNumbers(t_window *window, t_grid *grid);
void 	getBoxCoordinates(t_window *window, int x, int y, int *boxX, int *boxY);

#endif
