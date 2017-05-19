/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interplan.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:06:35 by ltesson           #+#    #+#             */
/*   Updated: 2017/05/19 19:04:42 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_interplan(t_rayon *ray, t_plan *plan)
{
//Je n'arrive pas a visualiser un plan par rapport a son equation, mais on va essayer quand meme
//L'equation d'un plan est de la forme Ax + By + Cz + D = 0
//Pour le rayon, on a I.x = O.x + D.x * t, I.y = O.y + D.y * t, I.z = O.z + D.z * t
//O est la position de la camera, point de depart du rayon
//I est le point d'intersection avec le plan
//D est le vecteur directeur
//t est la distance parcourue du point O au point I
//On retourne sur l'equation du plan, ce qui donne :
//A * (O.x + D.x * t) + B * (O.y + D.y * t) + C * (O.z + D.z * t) + D = 0
//j'espere que c'est pas trop confu avec D.x D.y D.z (vecteur directeur du rayon) et D (qui fait partie de l'equation du plan)
//On developpe
//A * O.x + t * A * D.x + B * O.y + t * B * D.y + C * O.z + t * C * D.z + D = 0
//t * (A * D.x + B * D.y + C * D.z) + A * O.x + B * O.y + C * O.z + D = 0
//t * (A * D.x + B * D.y + C * D.z) = -(A * O.x + B * O.y + C * O.z + D)
//t = -(A * O.x + B * O.y + C * O.z + D) / (A + D.x + B * D.y + C * D.z)
//Y a plus qu'a calculer !
	double	t1;

	t1 = -(plan->a * ray->pos.x + plan->b * ray->pos.y + plan->c * ray->pos.z 
			+ plan->d)
		/ (plan->a * ray->vec.x + plan->b * ray->vec.y + plan->c * ray->vec.z);
	if (t1 > 0 && t1 < ray->t)
	{
		ray->t = t1;
		ray->color = plan->color;
	}
}
