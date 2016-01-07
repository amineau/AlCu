/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 12:58:30 by dolewski          #+#    #+#             */
/*   Updated: 2015/12/21 17:09:10 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"
#include <unistd.h>
#include <stdlib.h>

int			alum_read2(char **content, char *buff)
{
	char	*tmp;

	if ((tmp = ft_strjoin(*content, buff)) == NULL)
		return (alum_error(4));
	ft_strdel(content);
	if ((*content = ft_strdup(tmp)) == NULL)
		return (alum_error(4));
	ft_strdel(&tmp);
	return (0);
}

int			alum_read(int fd, char **content)
{
	char	*buff;
	int		ret;

	buff = ft_strnew(BUFF_SIZE);
	ret = 0;
	*content = NULL;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (buff[0] == 10)
			break ;
		if (*content == NULL)
		{
			if ((*content = ft_strdup(buff)) == NULL)
				return (alum_error(4));
		}
		else if (alum_read2(content, buff) == -1)
			return (-1);
	}
	free(buff);
	if (ret == -1)
		return (alum_error(3));
	return (0);
}
