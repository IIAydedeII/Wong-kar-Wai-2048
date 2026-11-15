/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 17:45:43 by adede             #+#    #+#             */
/*   Updated: 2026/11/15 17:57:26 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"


t_cell	*new_cell(size_t value)
{
	t_cell	*cell;

	cell = ft_calloc(1, sizeof(t_cell));

	if (!cell)
		return (NULL);

	cell->value = value;

	return (cell);
}

t_cell	*get_neighbor(t_cell *cell, t_direction dir)
{
	if (!cell)
		return (NULL);

	switch (dir)
	{
		case NORTH: return (cell->north);
		case EAST:  return (cell->east);
		case SOUTH: return (cell->south);
		case WEST:  return (cell->west);
	}
	return (NULL);
}


void	initialize_grid(t_grid *grid, size_t dimension)
{
	t_cell	*cell;
	t_cell	*row_head;
	t_cell	*prev;
	t_cell	*above;

	above = NULL;
	for (size_t i = 0; i < dimension; i++)
	{
		row_head = NULL;
		prev = NULL;
		for (size_t j = 0; j < dimension; j++)
		{
			cell = new_cell((i + j) % 2);
			if (!cell)
				return ;

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
		if (i == 0)
			above = grid->head;
		else
			above = row_head;
	}
}


t_grid	*new_grid(size_t dimension)
{
	t_grid	*grid;

	grid = ft_calloc(1, sizeof(t_grid));

	if (!grid)
		return (NULL);

	initialize_grid(grid, dimension);

	return (grid);
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


void	iterate_line(t_cell *head, t_direction direction, void (*fn)(t_cell *, t_direction))
{
	t_direction	traversal;

	if (direction == EAST || direction == WEST)
		traversal = SOUTH;
	else
		traversal = EAST;

	while (head)
	{
		if (fn)
			fn(head, direction);
		head = get_neighbor(head, traversal);
	}
}


void	iterate_grid(t_grid grid, void (*fn)(t_cell *))
{
	t_cell	*head_column;
	t_cell	*head_row;

	head_row = grid.head;
	head_column = head_row;
	while (head_row)
	{
		while (head_column)
		{
			fn(head_column);
			head_column = head_column->east;
		}
		head_row = head_row->south;
		head_column = head_row;
		ft_putchar_fd('\n', 1);
	}
}
