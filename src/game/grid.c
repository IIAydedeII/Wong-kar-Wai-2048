/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 20:58:16 by adede             #+#    #+#             */
/*   Updated: 2026/11/15 21:37:26 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "game.h"

int	initialize_grid(t_grid *grid)
{
	t_cell	*cell;
	t_cell	*row_head;
	t_cell	*prev;
	t_cell	*above;

	above = NULL;
	for (size_t i = 0; i < grid->dimension; i++)
	{
		row_head = NULL;
		prev = NULL;
		for (size_t j = 0; j < grid->dimension; j++)
		{
			cell = new_cell(0);
			if (!cell)
				return (0);

			if (!grid->head)
				grid->head = cell;
			if (prev)
			{
				prev->east = cell;
				cell->west = prev;
			}
			else
				row_head = cell;
			if (above)
			{
				above->south = cell;
				cell->north = above;
				above = above->east;
			}
			prev = cell;
		}
		above = row_head;
	}
	return (1);
}

void	free_grid(t_grid *grid)
{
	t_cell	*row_head;
	t_cell	*cell;
	t_cell	*next;

	if (!grid)
		return ;
	row_head = grid->head;
	while (row_head)
	{
		cell = row_head;
		row_head = row_head->south;
		while (cell)
		{
			next = cell->east;
			free(cell);
			cell = next;
		}
	}
	free(grid);
}

t_grid	*new_grid(size_t dimension)
{
	t_grid	*grid;

	grid = ft_calloc(1, sizeof(t_grid));

	if (!grid)
		return (NULL);

	grid->dimension = dimension;

	if (!initialize_grid(grid))
	{
		free_grid(grid);
		return (NULL);
	}


	return (grid);
}

size_t	iterate_line(t_cell *head, t_direction dir, size_t (*fn)(t_cell *, t_direction))
{
	size_t		score;
	t_direction	traversal;

	if (dir == EAST || dir == WEST)
		traversal = SOUTH;
	else
		traversal = EAST;

	score = 0;
	while (head)
	{
		if (fn)
			score += fn(head, dir);
		head = get_neighbor(head, traversal);
	}

	return (score);
}

t_cell	*get_cell(t_grid *grid, size_t x, size_t y)
{
	t_cell	*temp;

	if (!(x < grid->dimension && y < grid->dimension))
		return (NULL);

	temp = grid->head;

	if (!temp)
		return (NULL);

	for (size_t i = 0; i < x; i++)
		temp = temp->east;
	for (size_t j = 0; j < y; j++)
		temp = temp->south;
	return (temp);
}

t_cell	*column_end(t_cell *head)
{
	if (!head)
		return (NULL);

	while (head->east)
		head = head->east;

	return (head);
}

t_cell	*row_end(t_cell *head)
{
	if (!head)
		return (NULL);

	while (head->south)
		head = head->south;

	return (head);
}


bool	isGridsSame(t_grid *grid1, t_grid *grid2)
{
	t_cell	*cell1;
	t_cell	*cell2;

	for (int i = 0; i < BOARD_SIZE; i++)
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			cell1 = get_cell(grid1, i, j);
			cell2 = get_cell(grid2, i, j);
			if (cell1->value != cell2->value)
				return (false);
		}
	return (true);
}

t_grid	*copy_grid(t_grid *original)
{
	t_grid	*grid;
	t_cell *orig_cell;
	t_cell *new_cell;

	grid = new_grid(BOARD_SIZE);
	if (!grid)
		return (NULL);

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			orig_cell = get_cell(original, i, j);
			new_cell = get_cell(grid, i, j);
			new_cell->value = orig_cell->value;
		}
	}
	return (grid);
}

bool	isMovePossible(t_grid *grid, t_direction dir)
{
	t_grid	*const tempGrid = copy_grid(grid);
	bool	movePossible = false;

	if (!tempGrid)
		return (false);

	swipe_grid(tempGrid, dir);
	movePossible = !isGridsSame(grid, tempGrid);

	free_grid(tempGrid);

	return (movePossible);
}

bool isAnyMovePossible(t_grid *grid)
{
	return (isMovePossible(grid, NORTH) || isMovePossible(grid, EAST) || isMovePossible(grid, SOUTH) || isMovePossible(grid, WEST));
}

