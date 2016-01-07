/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 12:58:15 by dolewski          #+#    #+#             */
/*   Updated: 2015/12/21 14:37:23 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALUM_H
# define ALUM_H

# include "libft.h"

# define BUFF_SIZE 1024

int			alum_error(int code);
int			alum_read(int fd, char **content);
int			**alum_tab(char *str);
void		alum_display(int *board);
void		alum_game(int **board);
int			alum_ia(int **board, int index);
void		alum_win(int win);

#endif
