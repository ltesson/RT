/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 17:14:32 by ltesson           #+#    #+#             */
/*   Updated: 2017/05/19 17:14:39 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_intersphere(t_rayon ray, t_sphere *sphere, double *t, int *color)
{
//Le rayon part du point O (camera), part dans la direction D,
//et traverse une distance t inconnue avant de traverser la sphere au point I
//La sphere a pour centre C et pour rayon r
//Le point de la sphere qui est traverse par le rayon est I.
//L'equation de la sphere au point I est (I.x - C.x)^2 + (I.y - C.y)^2 + (I.z - C.z)^2 = r^2
//Il faut trouver les coordonnees du point I
//Les coordonnees du point I par rapport au rayon sont I.x = O.x + D.x * t, I.y = O.y + D.y * t, I.z = O.z + D.z * t
//Si on retourne sur l'equation de la sphere, on trouve :
//(O.x + D.x * t - C.x)^2 + (O.y + D.y * t - C.y)2 + (O.z + D.z * t - C.z)^2 = r^2
//Et maintenant ?
//Disons que O - C = P pour simplifier
//Px^2 + D.x^2 * t^2 + 2 * P.x * D.x * t
//(D.x^2 + D.y^2 + D.z^2 * t^2 + (P.x * D.x + P.y * D.y + P.z + D.z) * 2t + P.x^2 + P.y^2 + P.z^2 - r^2
//On tombe sur une equation de 2e degre a resoudre !
	double	a;
	double	b;
	double	c;
	t_point	p;
	double	det;
	double	t1;
	double	t2;

	p.x = ray.pos.x - sphere->pos.x;
	p.y = ray.pos.y - sphere->pos.y;
	p.z = ray.pos.z - sphere->pos.z;
	a = ray.vec.x * ray.vec.x + ray.vec.y * ray.vec.y + ray.vec.z * ray.vec.z;
	b = 2 * (ray.vec.x * p.x + ray.vec.y * p.y + ray.vec.z * p.z);
	c = p.x * p.x + p.y * p.y + p.z * p.z - sphere->r * sphere->r;
	det = b * b - 4 * a * c;
	if (det < 0)
		return (0);
	t1 = (-b + sqrt(det)) / (2 * a);
	t2 = (-b - sqrt(det)) / (2 * a);
	if (t1 > 0 && t2 > 0)
		*t = fmin(fmin(t1, t2), *t);
	else if (t1 <= 0 && t2 <= 0)
		return (0);
	*t = fmin(fmax(t1, t2), *t);
	if (*t == t1 || *t == t2)
		*color = sphere->color;
	return (1);
}
