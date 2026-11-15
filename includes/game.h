/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 20:04:09 by adede             #+#    #+#             */
/*   Updated: 2026/11/15 18:03:33 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include "libft.h"

typedef enum e_direction
{
	NORTH,
	EAST,
	SOUTH,
	WEST
}	t_direction;

typedef struct s_cell
{
	struct s_cell	*north;
	struct s_cell	*east;
	struct s_cell	*south;
	struct s_cell	*west;
	size_t			value;
}	t_cell;

typedef struct s_grid
{
	t_cell	*head;
	size_t	score;
}	t_grid;


//	ACTIONS
void	compress(t_cell *head, t_direction direction);
void	swipe_line(t_cell *head, t_direction direction);
void	swipe_grid(t_grid *grid, t_direction direction);
void	push_cell(t_cell *cell, t_direction direction);

//	UTILS

//		Cell
t_cell	*new_cell(size_t value);
t_cell	*get_neighbor(t_cell *cell, t_direction dir);

//		Grid
void	initialize_grid(t_grid *grid, size_t dimension);
t_grid	*new_grid(size_t dimension);
t_cell	*column_end(t_cell *head);
t_cell	*row_end(t_cell *head);
void	iterate_line(t_cell *head, t_direction direction, void (*fn)(t_cell *, t_direction));
void	iterate_grid(t_grid grid, void (*fn)(t_cell *));

#endif
