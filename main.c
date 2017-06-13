/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 18:21:07 by ltesson           #+#    #+#             */
/*   Updated: 2017/06/08 19:07:42 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		main(int ac, char **av)
{
	t_scene		*s;

	if (ac < 2)
		return (ft_error(2));
	s = ft_initscene();
	if (s == NULL || s->error = 1)
		return (ft_error(1));
	ft_readfile(av[1], s);
	if (s->error)
		return (ft_error(s->error));
	ft_initcam(s->cam);
	ft_mlx(s);
	return (0);
}
