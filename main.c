/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:33:36 by ltesson           #+#    #+#             */
/*   Updated: 2017/05/03 19:04:46 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libft/libft.h"

int		main(int ac, char **av)
{
	t_scene		*s;

	if (ac != 2)
	{
		ft_endl("usage: ./rt <filepath>");
		return (0);
	}
	ft_readfile(s, av[2]);
	if (s == NULL)
	{
		ft_endl("file not found");
		return (0);
	}
	ft_draw(s);
	return (0);
}
