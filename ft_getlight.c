/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlight.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 17:59:26 by ltesson           #+#    #+#             */
/*   Updated: 2017/05/31 16:21:58 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdio.h>

void	ft_getlight(t_scene *s, t_rayon *ray)
{
	t_vecteur	norm;
	t_spot		*spot;
	t_rayon		light;
	double		scal;

	ray->power = 0;
	light.pos = ft_translation(ray->pos, ft_multvecteur(ray->vec, ray->t));
	norm = ft_getnormale(light.pos, ray->objet);
//	if (ray->objet->type != PLAN)
//		printf("%p\n", (void*)ray->objet);
	if (ft_produitscalaire(norm, ray->vec) > 0)
		norm = ft_multvecteur(norm, -1);
	spot = s->spot;
	while (spot)
	{
		light.vec = ft_getvecteur(light.pos, spot->pos);
		light.t = ft_getnormevecteur(light.vec);
		light.vec = ft_normalizevecteur(light.vec);
		if (!ft_intercheck(&light, s))
		{
			scal = ft_produitscalaire(norm, light.vec);
			if (scal > 0)
				ray->power += scal * spot->power;
//			printf("pos = %f, %f, %f\n", light.pos.x, light.pos.y, light.pos.z);
//			printf("vec = %f, %f, %f\n", light.vec.x, light.vec.y, light.vec.z);
//			printf("norm = %f, %f, %f\n", norm.x, norm.y, norm.z);
//			printf("spot->power = %f\n", spot->power);
//			printf("scalaire = %f\n", ft_produitscalaire(norm, light.vec));
		}
		spot = spot->next;
	}
//	printf("%f\n", ray->lumi);
	if (ray->power > 1)
		ray->power = 1;
}
