/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawscene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 17:43:30 by ltesson           #+#    #+#             */
/*   Updated: 2017/05/09 19:13:19 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_lancerayon(t_scene *s, t_env *e, int i, int j)
{
	e->addr[j * 4 + i * 4 * s->cam->xres] = 255;
}

void	ft_drawscene(t_scene *s, t_env *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < s->cam->yres)
	{
		j = 0;
		while (j < s->cam->xres)
		{
			ft_lancerayon(s, e, i, j);
			j++;
		}
		i++;
	}
}
