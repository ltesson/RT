/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intercylindre.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 14:15:25 by ltesson           #+#    #+#             */
/*   Updated: 2017/05/31 16:29:01 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_intercylindre(t_rayon *ray, t_cylindre *cylindre)
{
	t_rayon		ray2;
	t_vecteur	v;
	double		a;
	double		b;
	double		c;
	double		det;
	double		t1;
	double		t2;

//	Un cylindre est defini exactement comme un cylindre mais avec deux angles
//	Un pour la rotation autour de l'axe x, l'autre autour de l'axe y
//	La technique consiste a reutiliser la meme formule que pour le cylindre
//	vertical, mais en deplacant la camera
//	Au lieu de deplacer la camera, il suffit de creer un rayon, dont le point
//	de depart correspond a la position de la camera ayant subit une rotation
//	autour du "centre" du cylindre en utilisant les angles definis dans le cylindre
//	meme chose pour le vecteur de ce nouveau rayon, c'est une rotation du vecteur
//	du premier rayon
	v = ft_getvecteur(cylindre->pos, ray->pos);
	v = ft_rotatevecteur(v, -cylindre->a, -cylindre->b, 0);
	ray2.pos = ft_translation(cylindre->pos, v);
	ray2.vec = ft_rotatevecteur(ray->vec, -cylindre->a, -cylindre->b, 0);
//	p.x = ray2.pos.x - cylindre->pos.x;
//	p.y = ray2.pos.y - cylindre->pos.y;
//	En fait ca sert a rien de faire ca car le resultat est deja dans v
	a = ray2.vec.x * ray2.vec.x + ray2.vec.y * ray2.vec.y;
	b = 2 * (ray2.vec.x * v.x + ray2.vec.y * v.y);
	c = v.x * v.x + v.y * v.y - cylindre->r * cylindre->r;
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
