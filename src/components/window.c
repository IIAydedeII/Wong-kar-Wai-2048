#include "wong_kar_wai.h"

void 	drawBoard(void);

void initializeWindow()
{
    int	key;	

    initscr();

	drawBoard();
	while (true)
    {
        key = getch();
        if (key == KEY_RESIZE)
            drawBoard();
    }
}

void drawBoard(void)
{
    int screenWidth;
    int screenHeight;
	int boxSize;
	int offsetX = 0;
	int offsetY = 0;
	int	padding = 5;

    getmaxyx(stdscr, screenHeight, screenWidth);

	screenWidth -= padding;
	screenHeight -= padding;
	boxSize = (screenWidth < screenHeight * 2) ? screenWidth : screenHeight * 2;

	offsetX = (screenWidth - boxSize) / 2 + padding / 2; 
	offsetY = (screenHeight - boxSize / 2) / 2 + padding / 2;

	clear();
	
	for (int i = 0; i <= BOARD_SIZE; i++)
	{
		mvwvline(stdscr, (i != 0) + offsetY, i * boxSize / BOARD_SIZE + offsetX, '|', boxSize / 2 - (i == BOARD_SIZE));
		mvwhline(stdscr, i * boxSize / 2 / BOARD_SIZE + offsetY, 0 + offsetX, '-', boxSize);
	}

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			int cellX = (j * boxSize / BOARD_SIZE) + offsetX + (boxSize / BOARD_SIZE / 2);
			int cellY = (i * (boxSize / BOARD_SIZE /2)) + offsetY + (boxSize / BOARD_SIZE / 4);
			mvprintw(cellY, cellX, "sa");
		}
	}


    move(0, 0);

    refresh();
}

//mvwvline(stdscr, 0 + offsetY, index + offsetX, '|', size / 2 * padding);
//mvwhline(stdscr, index + offsetY, 0 + offsetX, '-', size * padding);


