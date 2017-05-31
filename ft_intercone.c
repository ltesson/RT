/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intercone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 15:23:33 by ltesson           #+#    #+#             */
/*   Updated: 2017/05/31 16:28:46 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_intercone(t_rayon *ray, t_cone *cone)
{
//C'est comme le cylindre, mais le rayon depend de plusieurs parametres, dont t
//Le rayon depend de la difference de hauteur entre le point et le centre du cone
//multipliee par un coefficient
//r = (c.z - i.z) * coeff
//On connait c.z mais i.z va dependre de t, qui est a trouver
//i.z = ray2.pos.z + ray2.vec.z * t
//r = (c.z - ray2.pos.z - ray2.vec.z * t) * coeff
//Reprenons l'equation du cylindre :
//(Px + Dx * t) ^ 2 + (Py + Dy * t) ^ 2 - (coeff * (Pz + Dz * t)) ^ 2 = 0
	t_rayon		ray2;
	t_vecteur	v;
	double		a;
	double		b;
	double		c;
	double		det;
	double		t1;
	double		t2;

	v = ft_getvecteur(cone->pos, ray->pos);
	v = ft_rotatevecteur(v, -cone->a, -cone->b, 0);
	ray2.pos = ft_translation(cone->pos, v);
	ray2.vec = ft_rotatevecteur(ray->vec, -cone->a, -cone->b, 0);
	a = ray2.vec.x * ray2.vec.x + ray2.vec.y * ray2.vec.y
		- cone->c * cone->c * ray2.vec.z * ray2.vec.z;
	b = 2 * (ray2.vec.x * v.x + ray2.vec.y * v.y
			- cone->c * cone->c * ray2.vec.z * v.z);
	c = v.x * v.x + v.y * v.y - cone->c * cone->c * v.z * v.z;
	det = b * b - 4 * a * c;
	if (det < 0)
		return (0);
	t1 = (-b + sqrt(det)) / (2 * a);
	t2 = (-b - sqrt(det)) / (2 * a);
	if (t1 < 0.01 && t2 < 0.01)
		return (0);
	else if (t1 >= 0.01 && t2 >= 0.01)
		ray->t = fmin(fmin(t1, t2), ray->t);
	else
		ray->t = fmin(fmax(t1, t2), ray->t);
	if (ray->t == t1 || ray->t == t2)
		return (1);
	return (0);
}
