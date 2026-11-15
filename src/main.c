#include "wong_kar_wai.h"
#include <stdlib.h>
#include <time.h>

bool isPowerOfTwo(int num)
{
	if (num < 2)
		return (false);
	while (num % 2 == 0)
		num /= 2;
	return (num == 1);
}

int	main(void)
{
	t_grid			*grid;

	if (!isPowerOfTwo(WIN_VALUE))
	{
		ft_printf("Error: WIN_VALUE must be a power of 2.\n");
		return (1);
	}
	grid = new_grid(BOARD_SIZE);
	if (!grid)
	{
		ft_printf("Error: Failed to create grid.\n");
		return (1);
	}
	srand(time(NULL));

	generate_random_tile(grid, 2);
	initializeWindow(grid);

	free_grid(grid);
	return (0);
}


