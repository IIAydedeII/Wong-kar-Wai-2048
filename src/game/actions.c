/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 18:00:45 by adede             #+#    #+#             */
/*   Updated: 2026/11/15 18:02:43 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static t_direction	opposite_direction(t_direction dir)
{
	return ((dir + 2) % 4);
}

void	compress(t_cell *head, t_direction direction)
{
	t_cell	*neighbor;

	while (head)
	{
		if (!head->value)
		{
			neighbor = get_neighbor(head, opposite_direction(direction));

			while (neighbor && !neighbor->value)
				neighbor = get_neighbor(neighbor, opposite_direction(direction));

			if (neighbor)
			{
				head->value = neighbor->value;
				neighbor->value = 0;
			}
		}
		head = get_neighbor(head, opposite_direction(direction));
	}
}

void	swipe_line(t_cell *head, t_direction direction)
{
	compress(head, direction);
}

void	swipe_grid(t_grid *grid, t_direction direction)
{
	t_cell		*line;

	line = grid->head;

	if (direction == EAST)
		line = column_end(line);
	else if (direction == SOUTH)
		line = row_end(line);

	iterate_line(line, direction, swipe_line);

	// while (line)
	// {
	// 	compress(line, direction);
	// 	line = get_neighbor(line, traversal);
	// }
}


void	push_cell(t_cell *cell, t_direction direction)
{
	size_t	value = cell->value;
	t_cell	*target;

	target = NULL;
	switch (direction)
	{
		case NORTH:
			target = cell->north;
		break ;
		case EAST:
			target = cell->east;
		break ;
		case SOUTH:
			target = cell->south;
		break ;
		case WEST:
			target = cell->west;
		break ;
		default :
			return ;
		break ;
	}


	ft_printf("cell: %p, value: %d\n", cell, cell->value);
	ft_printf("target: %p", target);
	if (target)
		ft_printf(", value: %d", target->value);
	ft_printf("\n");

	if (target)
	{
		target->value += value;
		cell->value = 0;
	}
}
