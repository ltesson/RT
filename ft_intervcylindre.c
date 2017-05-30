/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intervcylindre.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 14:52:20 by ltesson           #+#    #+#             */
/*   Updated: 2017/05/30 14:49:43 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_intervcylindre(t_rayon *ray, t_vcylindre *vcylindre)
{
//Il faut d'abord trouver la definition d'un cylindre.
//Un cylindre est l'ensemble des points a distance R d'un axe donne
//L'equation d'un cylindre centree sur l'axe z serait :
//Ix * Ix + Iy * Iy - R * R = 0
//Si le cylindre est vertical, mais pas sur l'axe z :
//(Ix - Cx) * (Ix - Cx) + (Iy - Cy) * (Iy - Cy) - R * R = 0
//Comment faire une rotation a partir de la ?
//Bon, on va deja commencer avec ca.
//Cette fonction servira uniquement pour un cylindre vertical.
//equation du rayon :
//Ix = Ox + Dx * t, Iy = Oy + Dy * t
//Comme pour la sphere, notons P le point I - C
//(Px + Dx * t)^2 + (Py + Dy * t)^2 - R^2 = 0
//Px^2 + Dx^2 * t^2 + 2 * Px * Dx * t + Py^2 + Dy^2 * t^2 + 2 * Py * Dy * t + Px^2 + Py^2 - r^2
//(Dx * Dx + Dy * Dy) * t^2 + 2 * (Px * Dx + Py * Dy) * t + Px * Px + Py * Py - r * r = 0
//equation de 2nd degre
//a = Dx * Dx + Dy * Dy
//b = 2 * (Px * Dx + Py * Dy)
//c = Px * Px + Py * Py - R * R
	double	a;
	double	b;
	double	c;
	t_point	p;
	double	det;
	double	t1;
	double	t2;

	p.x = ray->pos.x - vcylindre->pos.x;
	p.y = ray->pos.y - vcylindre->pos.y;
	a = ray->vec.x * ray->vec.x + ray->vec.y * ray->vec.y;
	b = 2 * (ray->vec.x * p.x + ray->vec.y * p.y);
	c = p.x * p.x + p.y * p.y - vcylindre->r * vcylindre->r;
	det = b * b - 4 * a * c;
	if (det < 0)
		return;
	t1 = (-b + sqrt(det)) / (2 * a);
	t2 = (-b - sqrt(det)) / (2 * a);
	if (t1 > 0 && t2 > 0)
		ray->t = fmin(fmin(t1, t2), ray->t);
	else if (t1 <= 0 && t2 <= 0)
		return;
	else
		ray->t = fmin(fmax(t1, t2), ray->t);
	if (ray->t == t1 || ray->t == t2)
		ray->color = vcylindre->color;
}
