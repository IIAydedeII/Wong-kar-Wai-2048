/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 23:12:52 by emyildir          #+#    #+#             */
/*   Updated: 2026/11/15 23:12:53 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong_kar_wai.h"

void initializeWindow(t_grid *grid)
{
    int	key;
	int	gameEnded;

    initscr();
	keypad(stdscr, TRUE);
	cbreak();
	noecho();

	drawBoard(grid);
	while (true)
    {
		gameEnded = false;
        key = getch();
		if (key == KEY_UP)
			gameEnded = do_action(grid, NORTH);
		else if (key == KEY_DOWN)
			gameEnded = do_action(grid, SOUTH);
		else if (key == KEY_LEFT)
			gameEnded = do_action(grid, WEST);
		else if (key == KEY_RIGHT)
			gameEnded = do_action(grid, EAST);
		else if (key == KEY_ESCAPE)
			break;
		
		drawBoard(grid);
		if (gameEnded)
			break;
    }
	endwin();
	ft_printf("You %s Your score was: %d\n", grid->won ? "WON!" : "lost.", grid->score);
}

void drawBoard(t_grid *grid)
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
		mvprintw(window->offsetY + (window->boardSize / 2) + 1, window->offsetX, "Score: %zu\n", grid->score);
		if (grid->won)
			mvprintw(window->offsetY - 1, window->offsetX, "You WON!");
		drawBorders(window);
		drawNumbers(window, grid);
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

void drawNumbers(t_window *window, t_grid *grid)
{
	int		num;
	int		len;
	int		x;
	int		y;

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			t_cell *cell = get_cell(grid, i, j);
			getBoxCoordinates(window, i, j, &x, &y);
			num = cell->value;
			if (num == 0)
				continue;
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






