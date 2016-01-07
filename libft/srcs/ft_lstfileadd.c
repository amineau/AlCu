/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfileadd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 14:17:38 by dolewski          #+#    #+#             */
/*   Updated: 2015/12/19 19:04:42 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lstfileadd(t_file **lstfile, t_file *new)
{
	t_file *tmp;

	tmp = *lstfile;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
