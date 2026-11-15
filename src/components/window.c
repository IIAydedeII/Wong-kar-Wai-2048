#include "wong_kar_wai.h"

int		getNumLen(int num);
void 	drawBoard(void);
void 	drawBorders(t_window *window);
void	drawNumbers(t_window *window);
void 	getBoxCoordinates(t_window *window, int x, int y, int *boxX, int *boxY);

void initializeWindow()
{
    int	key;	

    initscr();
	keypad(stdscr, TRUE);	
	cbreak();
	noecho();

	drawBoard();
	while (true)
    {
        key = getch();
        if (key == KEY_RESIZE)
            drawBoard();
		else if (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT || key == KEY_RIGHT)
		{
			
		}
		else if (key == KEY_ESCAPE)
			break;
    }
}

void drawBoard(void)
{
	t_window	*window = &(t_window){0};

	getmaxyx(stdscr, window->screenHeight, window->screenWidth);

	window->screenWidth -= SCREEN_PADDING;
	window->screenHeight -= SCREEN_PADDING / 2;

	window->boardSize = (window->screenWidth < window->screenHeight * 2) ? window->screenWidth : window->screenHeight * 2;
	window->boxSize = window->boardSize / BOARD_SIZE;
	if (window->boxSize % 2)
		window->boxSize--;
	window->boardSize = window->boxSize * BOARD_SIZE;

	window->offsetX = (window->screenWidth - window->boardSize) / 2 + SCREEN_PADDING / 2;
	window->offsetY = (window->screenHeight - window->boardSize / 2) / 2 + SCREEN_PADDING / 4;


	
	clear();
	if (window->boxSize >= 5)
	{
		drawBorders(window);
		drawNumbers(window);
	}
	else
		mvprintw(window->screenHeight / 2, (window->screenWidth - 20) / 2, "Window is too small.");
	move(0,0);
	refresh();

}


void drawBorders(t_window *window)
{
	int	x;
	int	y;

	for (int i = 0; i <= BOARD_SIZE; i++)
	{
		getBoxCoordinates(window, 0, i, &x, &y);
		mvwhline(stdscr, y, x, '-', window->boardSize + (i == BOARD_SIZE || i == 0));
	}
	for (int i = 0; i <= BOARD_SIZE; i++)
	{
		getBoxCoordinates(window, i, 0, &x, &y);
		mvwvline(stdscr, y + 1, x, '|', window->boardSize / 2 - 1);
	}

}

void drawNumbers(t_window *window)
{
	int		num;
	int		len;
	int		x;
	int		y;	

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			getBoxCoordinates(window, i, j, &x, &y);
			num = 2 << (i * BOARD_SIZE + j);
			len = getNumLen(num);
			if (len > window->boxSize - 2)
				mvprintw(y + window->boxSize / 4, x + ((window->boxSize - 1) / 2), ".");
			else
				mvprintw(y + window->boxSize / 4, x + ((window->boxSize - len + 1) / 2), "%d", num);
			
			
		}
	}
}

int	getNumLen(int num)
{
	int	len;

	if (num == 0)
		return (1);
	len = 0;
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}

void getBoxCoordinates(t_window *window, int x, int y, int *boxX, int *boxY)
{
	*boxX = (x * window->boxSize) + window->offsetX;
	*boxY = (y * window->boxSize / 2) + window->offsetY;
}






