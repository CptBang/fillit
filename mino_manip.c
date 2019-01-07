/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mino_manip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 13:15:27 by jgabelho          #+#    #+#             */
/*   Updated: 2019/01/07 14:39:50 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdlib.h>

int		mino_len(t_mino *lst)
{
	int		i;

	if (!lst)
		return (0);
	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	del_minos(t_mino **list)
{
	t_mino		*tmp;
	int			i;

	if (!list || !*list)
		return ;
	i = 0;
	while (*list)
	{
		tmp = (*list)->next;
		while ((*list)->crd[i])
		{
			ft_strdel(&(*list)->crd[i]);
			i++;
		}
		free(*list);
		(*list) = tmp;
	}
	*list = NULL;
}
