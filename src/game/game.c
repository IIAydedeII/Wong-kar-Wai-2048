/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 22:42:23 by adede             #+#    #+#             */
/*   Updated: 2026/11/15 18:02:31 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#define DIMENSION 5

void	print_value(t_cell *cell)
{
	ft_printf("%4d", cell->value);
}

int	main_game(void)
{
	t_grid	*grid;

	grid = new_grid(DIMENSION);

	iterate_grid(*grid, print_value);
	ft_printf("---------\n");


	swipe_grid(grid, EAST);
	ft_printf("---------\n");
	iterate_grid(*grid, print_value);
	swipe_grid(grid, WEST);
	ft_printf("---------\n");
	iterate_grid(*grid, print_value);
	swipe_grid(grid, NORTH);
	ft_printf("---------\n");
	iterate_grid(*grid, print_value);
	swipe_grid(grid, SOUTH);
	ft_printf("---------\n");
	iterate_grid(*grid, print_value);


	// swipe(grid, direction)
	// swipe{
	// 	head
	// 	if direction = north, south
	// 		for  every column
	// 			compress(head, direction)
	// 			merge(head, direction)
	// 			compress(head, direction)

	// 			head = head.east
	// 	if direction = east, west
	// 		for every row
	// 			compress(head, direction)
	// 			merge(head, direction)
	// 			compress(head, direction)

	// 			head = head.south
	// }

	return (0);
}
