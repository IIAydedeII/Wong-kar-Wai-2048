#include "game.h"

bool do_action(t_grid *grid, t_direction dir)
{
	if (isMovePossible(grid, dir))
	{

		swipe_grid(grid, dir);
		
		if (isAnyMovePossible(grid))
			return (false);
	}
	return (true);
}
