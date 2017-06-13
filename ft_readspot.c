/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readspot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 19:50:03 by ltesson           #+#    #+#             */
/*   Updated: 2017/06/08 20:25:15 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_spotdata(t_spot *spot, char *line)
{


void	ft_readspot(t_scene *s, int fd, char *line, int *i)
{
	t_spot		*spot;

	spot = (t_spot*)malloc(sizeof(t_spot));
	if (spot == NULL)
	{
		s->error = 1;
		return ;
	}
	spot->pos.x = 0;
	spot->pos.y = 0;
	spot->pos.z = 0;
	spot->power = 1;
	spot->next = s->spot;
	s->spot = spot;
	while (ft_strlen(line) && *i == 1)
	{
		*i = get_next_line(fd, &line);
		if (ft_strlen(line))
			ft_spotdata(spot, line);
	}
}
