/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wong_kar_wai.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 18:46:57 by adede             #+#    #+#             */
/*   Updated: 2026/11/14 19:56:48 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WONG_KAR_WAI_H
# define WONG_KAR_WAI_H

# include "libft.h"
# include <ncurses.h>
# include <stdbool.h>

# define BOARD_SIZE 4
# define SCREEN_PADDING 5
# define KEY_ESCAPE 27

enum e_const
{
	WIN_VALUE = 2048
};

typedef struct t_window
{
	int	screenWidth;
	int	screenHeight;
	int	boardSize;
	int	boxSize;
	int	offsetX;
	int	offsetY;
}	t_window;

void	initializeWindow();

#endif
