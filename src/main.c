/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 18:56:41 by adede             #+#    #+#             */
/*   Updated: 2026/11/15 19:44:56 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong_kar_wai.h"

int	main(void)
{
	t_grid *const	grid = new_grid(BOARD_SIZE);

	if (!grid)
	{
		ft_printf("Error: Failed to create grid.\n");
		return (1);
	}

	get_cell(grid->head, 1, 0)->value = 2;
	get_cell(grid->head, 3, 0)->value = 2;

	get_cell(grid->head, 0, 1)->value = 2;
	get_cell(grid->head, 1, 1)->value = 2;
	get_cell(grid->head, 2, 1)->value = 2;
	get_cell(grid->head, 3, 1)->value = 2;

	get_cell(grid->head, 1, 2)->value = 2;
	get_cell(grid->head, 3, 2)->value = 4;

	get_cell(grid->head, 0, 3)->value = 4;
	get_cell(grid->head, 1, 3)->value = 4;
	get_cell(grid->head, 2, 3)->value = 4;
	get_cell(grid->head, 3, 3)->value = 4;

	initializeWindow(grid);

	return (0);
}


