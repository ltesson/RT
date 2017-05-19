/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawscene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 17:43:30 by ltesson           #+#    #+#             */
/*   Updated: 2017/05/19 18:47:42 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_rayon		ft_primray(t_camera *c, double i, double j)
{
	t_vecteur	haut;
	t_vecteur	droit;
	t_rayon		ray;

	droit = ft_multvecteur(c->rightvec, c->xindent * j);
	haut = ft_multvecteur(c->upvec, c->yindent * i);
	ray.pos = ft_translation(c->firstpix, ft_addvecteur(haut, droit));
	ray.vec = ft_getvecteur(c->pos, ray.pos);
	ray.vec = ft_normalizevecteur(ray.vec);
	ray.pos = c->pos;
	return (ray);
}

void	ft_lancerayon(t_scene *s, t_env *e, int i, int j)
{
	t_rayon		ray;
	t_listobj	*liste;

	ray = ft_primray(s->cam, i, j);
	ray.color = 0;
	ray.t = INFINITY;
	liste = s->list;
	while (liste)
	{
		ft_intersect(&ray, liste);
		liste = liste->next;
	}
	e->addr[j * 4 + i * 4 * s->cam->xres + 2] = ray.color / (256 * 256);
	e->addr[j * 4 + i * 4 * s->cam->xres + 1] = (ray.color / 256) % 256;
	e->addr[j * 4 + i * 4 * s->cam->xres] = ray.color % 256;
}

void	ft_drawscene(t_scene *s, t_env *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < s->cam->yres)
	{
		j = 0;
		while (j < s->cam->xres)
		{
			ft_lancerayon(s, e, i, j);
			j++;
		}
		i++;
	}
}
