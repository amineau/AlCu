/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfilenew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 14:17:33 by dolewski          #+#    #+#             */
/*   Updated: 2015/12/19 19:36:59 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_file				*ft_lstfilenew(char *data, int fd)
{
	t_file *new;

	new = (t_file *)malloc(sizeof(t_file));
	if (new != NULL)
	{
		if (data == NULL)
			new->data = NULL;
		else
		{
			new->data = ft_strnew(ft_strlen(data));
			ft_memcpy(new->data, data, ft_strlen(data));
		}
		new->fd = fd;
	}
	return (new);
}
