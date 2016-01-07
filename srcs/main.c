/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 12:58:35 by dolewski          #+#    #+#             */
/*   Updated: 2015/12/21 16:37:24 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int		alum_error(int code)
{
	if (code == 1)
		ft_putendl_fd("1: Nombre d'arguments invalide", 2);
	else if (code == 2)
		ft_putendl_fd("2: Impossible d'ouvrire le fichier donne", 2);
	else if (code == 3)
		ft_putendl_fd("3: Erreur a la lecture du fichier", 2);
	else if (code == 4)
		ft_putendl_fd("4: Alocation", 2);
	else if (code == 5)
		ft_putendl_fd("5: ERROR", 2);
	return (-1);
}

int		main(int ac, char **av)
{
	int		fd;
	int		err;
	char	*content;
	int		**tab;

	err = 0;
	fd = 0;
	if (ac == 2)
		fd = open(av[1], O_RDONLY);
	else if (ac != 1)
		err = alum_error(1);
	if (fd != -1 && err == 0)
	{
		if ((err = alum_read(fd, &content)) == 0)
		{
			tab = alum_tab(content);
			free(content);
			if (tab != 0)
				alum_game(tab);
		}
	}
	else if (fd == -1)
		alum_error(2);
	close(fd);
	return (0);
}
