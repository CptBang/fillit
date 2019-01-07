/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solved.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 14:17:28 by jgabelho          #+#    #+#             */
/*   Updated: 2019/01/07 14:38:30 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "fillit.h"
#include <stdlib.h>

int		recurse(t_mino *mino, t_map *mappie, int size)
{
	int x;
	int y;

	if (mino == NULL)
		return (1);
	y = 0;
	while (y < mappie->size)
	{
		x = 0;
		while (x < mappie->size)
		{
			if (placer(mappie, mino, x, y))
			{
				if (recurse(mino->next, mappie, mappie->size))
					return (1);
				else
					piece_reset(mappie, mino, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int		solved(t_mino *minos)
{
	t_map	*mappie;

	mappie = map_new(2);
	while (!recurse(minos, mappie, mappie->size))
	{
		mappie->size++;
		if (mappie->size > 16)
			return (0);
	}
	printn2d(mappie->map, mappie->size);
	map_free(mappie);
	del_minos(&minos);
	return (1);
}
