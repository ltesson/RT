/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intercheck.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 18:46:35 by ltesson           #+#    #+#             */
/*   Updated: 2017/05/31 16:23:04 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	ft_intercheck(t_rayon *ray, t_scene *s)
{
	t_listobj	*list;

	list = s->list;
	while (list)
	{
		if (list->type == SPHERE)
		{
			if (ft_intersphere(ray, (t_sphere*)list->objet))
				return (1);
		}
		else if (list->type == PLAN)
		{
			if (ft_interplan(ray, (t_plan*)list->objet))
				return (1);
		}
		else if (list->type == CYLINDRE)
		{
			if (ft_intercylindre(ray, (t_cylindre*)list->objet))
				return (1);
		}
		else if (list->type == CONE)
		{
			if (ft_intercone(ray, (t_cone*)list->objet))
				return (1);
		}
		list = list->next;
	}
	return (0);
}
