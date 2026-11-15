#ifndef GAME_H
# define GAME_H
# include "libft.h"
# include <stdbool.h>

# define BOARD_SIZE 4

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
	size_t	dimension;
	size_t	score;
	bool	won;
}	t_grid;


void	compress(t_cell *head, t_direction dir);
size_t	merge(t_cell *head, t_direction dir);
size_t	swipe_line(t_cell *head, t_direction dir);
void	swipe_grid(t_grid *grid, t_direction dir);
bool 	isAnyMovePossible(t_grid *grid);
bool 	isMovePossible(t_grid *grid, t_direction dir);
bool 	do_action(t_grid *grid, t_direction dir);
int		generate_random_tile(t_grid *grid, int count);

t_cell	*new_cell(size_t value);
t_cell	*get_neighbor(t_cell *cell, t_direction dir);
t_cell	*get_cell(t_grid *grid, size_t x, size_t y);

int		initialize_grid(t_grid *grid);
t_grid	*new_grid(size_t dimension);
void	free_grid(t_grid *grid);
t_cell	*column_end(t_cell *head);
t_cell	*row_end(t_cell *head);
size_t	iterate_line(t_cell *head, t_direction dir, size_t (*fn)(t_cell *, t_direction));
bool	isAnyTileWinnable(t_grid *grid);



#endif
