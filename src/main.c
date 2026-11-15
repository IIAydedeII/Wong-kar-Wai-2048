/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 18:56:41 by adede             #+#    #+#             */
/*   Updated: 2026/11/14 19:46:24 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong_kar_wai.h"

int	main(void)
{
	t_grid	*const grid = new_grid(BOARD_SIZE);

	if (!grid)
	{
		ft_printf("Error: Failed to create grid.\n");
		return (1);
	}

	initializeWindow(grid);

	return (0);
}


