/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 18:00:45 by adede             #+#    #+#             */
/*   Updated: 2026/11/15 20:44:27 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	merge(t_cell *head, t_direction dir)
{
	t_cell	*neighbor;

	while (head)
	{
		neighbor = get_neighbor(head, opposite_direction(dir));

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

void	swipe_line(t_cell *head, t_direction dir)
{
	compress(head, dir);
	merge(head, dir);
	compress(head, dir);
}

void	swipe_grid(t_grid *grid, t_direction dir)
{
	t_cell		*line;

	line = grid->head;

	if (dir == EAST)
		line = column_end(line);
	else if (dir == SOUTH)
		line = row_end(line);

	iterate_line(line, dir, swipe_line);
}
