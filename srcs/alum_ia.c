/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum_ia.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 12:58:26 by dolewski          #+#    #+#             */
/*   Updated: 2015/12/21 12:58:30 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"

int	alum_ia(int **board, int index)
{
	if (board[0][index] == 1)
		return (1);
	else if (board[0][index] < 5 && board[1][index] == 0)
		return (board[0][index] - 1);
	else if (board[0][index] < 4 && board[1][index] == 1)
		return (board[0][index]);
	else if (board[0][index] % 4 != 1 && board[1][index] == 0)
		return ((board[0][index] + 3) % 4);
	else if (board[0][index] % 4 != 0 && board[1][index] == 1)
		return (board[0][index] % 4);
	return (1);
}
