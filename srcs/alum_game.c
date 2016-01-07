/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 12:58:23 by dolewski          #+#    #+#             */
/*   Updated: 2015/12/21 17:25:11 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"
#include <unistd.h>
#include <stdlib.h>

int			alum_remove(int ***board, int nb)
{
	int i;

	i = 0;
	while ((*board)[0][i] != 0)
	{
		if ((*board)[0][i + 1] == 0)
		{
			if ((*board)[0][i] < nb)
				return (-1);
			else
				(*board)[0][i] -= nb;
		}
		i++;
	}
	if ((*board)[0][i - 1] == 0)
		i--;
	return (--i);
}

int			alum_game_player2(int ***board, char **value)
{
	int ok;
	int nb;

	ok = 1;
	nb = 0;
	while (ok == 1)
	{
		ft_putstr("Please enter a value between 1 and 3\nPlayer : ");
		read(1, *value, BUFF_SIZE);
		if ((*value)[1] == 10 && (*value)[0] >= '1' && (*value)[0] <= '3')
		{
			ok = 0;
			nb = ft_atoi(*value);
			nb = alum_remove(board, nb);
			if (nb == -1 && (*board)[0][0] != 0)
			{
				ok = 1;
				ft_putstr("Please enter a lower value to the number of ");
				ft_putendl("remaining match");
			}
		}
	}
	return (nb);
}

int			alum_game_player(int ***board)
{
	int		ok;
	int		index;
	char	*value;

	ok = 1;
	index = 0;
	ft_putendl("\n\x1B[36m------------- Player ------------\x1B[0m");
	alum_display((*board)[0]);
	value = ft_strnew(2);
	index = alum_game_player2(board, &value);
	free(value);
	return (index);
}

void		alum_game(int **board)
{
	int		nb;
	int		index;

	index = 0;
	while (board[0][0] != 0)
	{
		index = alum_game_player(&board);
		if (board[0][0] != 0)
		{
			ft_putendl("\n\x1B[36m--------------- IA --------------\x1B[0m");
			alum_display(board[0]);
			nb = alum_ia(board, index);
			alum_remove(&board, nb);
			ft_putstr("IA : ");
			ft_putnbrendl(nb);
			if (board[0][0] == 0)
				alum_win(1);
		}
		else
			alum_win(0);
	}
}
