/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 12:02:40 by mschroed          #+#    #+#             */
/*   Updated: 2019/01/07 14:39:29 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "fillit.h"
#include <stdlib.h>

void	usage(void)
{
	ft_putstr("usage: fillit input_file\n");
	exit (-1);
}

int		error(t_mino *minos)
{
	ft_putstr("error\n");
	del_minos(&minos);
	exit (-1);
}

int		main(int argc, char **argv)
{
	t_mino	*minos;

	if (argc == 2)
	{
		if ((minos = mino_oc(argv[1])) == 0)
			return (error(minos));
		if (val_mino(minos) == -1)
			return (error(minos));
		if (solved(minos) == 0)
			return (error(minos));
	}
	else
		usage();
	return (0);
}
