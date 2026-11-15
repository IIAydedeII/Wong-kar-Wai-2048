#include "game.h"

static t_direction	opposite_direction(t_direction dir)
{
	return ((dir + 2) % 4);
}

void	compress(t_cell *head, t_direction dir)
{
	t_cell	*neighbor;

	while (head)
	{
		if (!head->value)
		{
			neighbor = get_neighbor(head, opposite_direction(dir));

			while (neighbor && !neighbor->value)
				neighbor = get_neighbor(neighbor, opposite_direction(dir));

			if (neighbor)
			{
				head->value = neighbor->value;
				neighbor->value = 0;
			}
		}
		head = get_neighbor(head, opposite_direction(dir));
	}
}

size_t	merge(t_cell *head, t_direction dir)
{
	size_t	score;
	t_cell	*neighbor;

	score = 0;
	while (head)
	{
		neighbor = get_neighbor(head, opposite_direction(dir));

		if (!neighbor)
			break ;

		if (head->value && head->value == neighbor->value)
		{
			head->value += neighbor->value;
			score += head->value;
			neighbor->value = 0;
		}
		head = neighbor;
	}

	return (score);
}

size_t	swipe_line(t_cell *head, t_direction dir)
{
	size_t	score;

	compress(head, dir);
	score = merge(head, dir);
	compress(head, dir);

	return (score);
}

void	swipe_grid(t_grid *grid, t_direction dir)
{
	t_cell		*line;

	line = grid->head;

	if (dir == EAST)
		line = column_end(line);
	else if (dir == SOUTH)
		line = row_end(line);

	grid->score += iterate_line(line, dir, swipe_line);
}
