/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 23:12:58 by emyildir          #+#    #+#             */
/*   Updated: 2026/11/15 23:12:59 by emyildir         ###   ########.fr       */
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
