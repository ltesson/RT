/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initscene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 18:45:10 by ltesson           #+#    #+#             */
/*   Updated: 2017/06/08 19:06:21 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdlib.h>

t_scene		*ft_initscene(void)
{
	t_scene		*s;

	s = (t_scene*)malloc(sizeof(t_scene));
	if (s == NULL)
		return (s);
	s->name = NULL;
	s->cam = (t_camera*)malloc(sizeof(t_camera));
	s->list = NULL;
	s->spot = NULL;
	if (s->cam == NULL)
		s->error = 1;
	else
		s->error = 0;
	return (s);
}
