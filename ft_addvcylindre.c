/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addvcylindre.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:54:00 by ltesson           #+#    #+#             */
/*   Updated: 2017/05/23 15:55:25 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdlib.h>

void	ft_addvcylindre(t_scene *s, t_point pos, double r, int color)
{
	t_vcylindre	*vcylindre;
	t_listobj	*newobj;

	vcylindre = (t_vcylindre*)malloc(sizeof(t_vcylindre));
	newobj = (t_listobj*)malloc(sizeof(t_listobj));
	if (vcylindre == NULL || newobj == NULL)
	{
		s->error = 1;
		return;
	}
	vcylindre->pos = pos;
	vcylindre->r = r;
	vcylindre->color = color;
	newobj->objet = vcylindre;
	newobj->type = VCYLINDRE;
	newobj->next = s->list;
	s->list = newobj;
}
