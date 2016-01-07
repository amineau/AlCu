/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 12:58:33 by dolewski          #+#    #+#             */
/*   Updated: 2015/12/21 17:08:43 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"
#include <stdlib.h>

int	alum_rows(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 1;
	while (str[i])
	{
		if (str[i] == '\n')
			nb++;
		i++;
	}
	return (nb);
}

int	alum_bol(int **board, int i)
{
	if (i == 0)
		return (0);
	else if ((board[0][i - 1] % 4 != 1 && board[1][i - 1] == 0)
			|| (board[0][i - 1] % 4 != 0 && board[1][i - 1] == 1))
		return (0);
	return (1);
}

int	**alum_board(char *str)
{
	int	**board;

	board = ft_memalloc(sizeof(*board) * 2);
	board[0] = ft_memalloc(sizeof(board) * alum_rows(str));
	board[1] = ft_memalloc(sizeof(board) * alum_rows(str));
	return (board);
}

int	alum_road(int ***board, char *str, int i, int j)
{
	if ((str[i] == '\n' && str[i + 1] == '\n')
			|| !(ft_isdigit(str[i]) == 1 || str[i] == '\n'))
	{
		alum_error(5);
		return (0);
	}
	if (i == 0 || str[i - 1] == '\n')
	{
		(*board)[0][j] = ft_atoi(&str[i]);
		if ((*board)[0][j] < 1 || (*board)[0][j] > 10000)
		{
			alum_error(5);
			return (0);
		}
		(*board)[1][j] = alum_bol(*board, j);
		j++;
	}
	return (j);
}

int	**alum_tab(char *str)
{
	int	i;
	int	j;
	int	**board;

	if (str == NULL || str[0] == '\n')
	{
		alum_error(5);
		return (0);
	}
	board = alum_board(str);
	i = 0;
	j = 0;
	while (str[i])
	{
		j = alum_road(&board, str, i, j);
		if (j == 0)
			return (0);
		i++;
	}
	board[0][j] = 0;
	return (board);
}
