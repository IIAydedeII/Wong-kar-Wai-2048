/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 18:00:45 by adede             #+#    #+#             */
/*   Updated: 2026/11/15 20:04:06 by adede            ###   ########.fr       */
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

void	merge(t_cell *head, t_direction direction)
{
	t_cell	*neighbor;

	while (head)
	{
		neighbor = get_neighbor(head, opposite_direction(direction));

		if (!neighbor)
			break ;

		if (head->value && head->value == neighbor->value)
		{
			head->value += neighbor->value;
			neighbor->value = 0;
		}
		head = neighbor;
	}
}

void	swipe_line(t_cell *head, t_direction direction)
{
	compress(head, direction);
	merge(head, direction);
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
}
