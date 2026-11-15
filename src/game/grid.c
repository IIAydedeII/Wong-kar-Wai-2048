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

t_grid	*new_grid(size_t dimension)
{
	t_grid	*grid;

	grid = ft_calloc(1, sizeof(t_grid));

	if (!grid)
		return (NULL);

	grid->dimension = dimension;

	if (!initialize_grid(grid))
	{
		// free_grid(grid);
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

void	iterate_grid(t_grid grid, void (*fn)(t_cell *, t_direction))
{
	t_cell	*head_row;

	head_row = grid.head;
	while (head_row)
	{
		iterate_line(head_row, EAST, fn);
		head_row = head_row->south;
		ft_putchar_fd('\n', 1);
	}
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
