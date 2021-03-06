/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 10:41:39 by mschroed          #+#    #+#             */
/*   Updated: 2019/01/07 13:25:57 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include "fillit.h"

void	map_free(t_map *map)
{
	int	i;

	i = -1;
	if (!map)
		return ;
	while(++i < map->size)
		ft_strdel(&(map->map[i]));
	ft_memdel((void **)&map);
}
