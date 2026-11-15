#include "game.h"
#include <stdlib.h>

bool do_action(t_grid *grid, t_direction dir)
{
	if (isMovePossible(grid, dir))
	{

		swipe_grid(grid, dir);
		generate_random_tile(grid, 1);
		

		if (isAnyMovePossible(grid))
			return (false);
	}
	return (true);
}


size_t	count_empty_cells(t_grid *grid)
{
	size_t	empty;

	empty = 0;
	for (size_t i = 0; i < grid->dimension; i++)
		for (size_t j = 0; j < grid->dimension; j++)
			if (get_cell(grid, i, j)->value == 0)
				empty++;
	return (empty);
}

t_cell	*get_nth_empty_cell(t_grid *grid, size_t n)
{
	t_cell	*cell;

	for (size_t i = 0; i < grid->dimension; i++)
	{
		for (size_t j = 0; j < grid->dimension; j++)
		{
			cell = get_cell(grid, i, j);
			if (cell->value == 0 && n-- == 0)
				return (cell);
		}
	}
	return (NULL);
}

int	generate_random_tile(t_grid *grid, int count)
{
	t_cell	*cell;
	size_t	empty;
	int		placed;

	placed = 0;
	while (placed < count)
	{
		empty = count_empty_cells(grid);
		if (empty == 0)
			break ;
		cell = get_nth_empty_cell(grid, rand() % empty);
		cell->value = (rand() % 10 == 0) ? 4 : 2;
		placed++;
	}
	return (placed);
}
