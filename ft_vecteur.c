/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecteur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 18:40:17 by ltesson           #+#    #+#             */
/*   Updated: 2017/05/13 16:24:26 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

t_vecteur	ft_normalizevecteur(t_vecteur v)
{
	double	norme;

	norme = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	v.x /= norme;
	v.y /= norme;
	v.z /= norme;
	return (v);
}

t_vecteur	ft_getvecteur(t_point a, t_point b)
{
	t_vecteur	v;

	v.x = b.x - a.x;
	v.y = b.y - a.y;
	v.z = b.z - a.z;
	return (v);
}

t_vecteur	ft_multvecteur(t_vecteur v, double t)
{
	v.x *= t;
	v.y *= t;
	v.z *= t;
	return (v);
}

t_vecteur	ft_addvecteur(t_vecteur v, t_vecteur w)
{
	v.x += w.x;
	v.y += w.y;
	v.z += w.z;
	return (v);
}

t_point		ft_translation(t_point p, t_vecteur v)
{
	p.x += v.x;
	p.y += v.y;
	p.z += v.z;
	return (p);
}
