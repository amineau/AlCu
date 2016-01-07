/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 15:18:43 by amineau           #+#    #+#             */
/*   Updated: 2015/12/21 12:08:38 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"

void	alum_display(int *board)
{
	int i;
	int	j;

	i = 0;
	while (board[i] != 0)
	{
		j = 0;
		ft_putnbr(board[i]);
		ft_putstr("\t");
		while (j++ < board[i])
			ft_putchar('|');
		ft_putchar('\n');
		i++;
	}
}

void	alum_win(int win)
{
	if (win == 1)
	{
		ft_putendl("");
		ft_putendl("\x1B[32m*********************************\x1B[0m");
		ft_putendl("\x1B[32m            Player WIN\x1B[0m");
		ft_putendl("\x1B[32m*********************************\x1B[0m");
		ft_putendl("");
	}
	else
	{
		ft_putendl("");
		ft_putendl("\x1B[32m*********************************\x1B[0m");
		ft_putendl("\x1B[32m              IA WIN\x1B[0m");
		ft_putendl("\x1B[32m*********************************\x1B[0m");
		ft_putendl("");
	}
}
