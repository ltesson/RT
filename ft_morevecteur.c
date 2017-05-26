/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_morevecteur.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 16:22:55 by ltesson           #+#    #+#             */
/*   Updated: 2017/05/24 18:28:19 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdio.h>

t_vecteur	ft_rotatevecteurx(t_vecteur v, double a)
{
	t_vecteur	u;

	u.x = v.x;
	u.y = v.y * cos(a) - v.z * sin(a);
	u.z = v.y * sin(a) + v.z * cos(a);
	return (u);
}

t_vecteur	ft_rotatevecteury(t_vecteur v, double a)
{
	t_vecteur	u;

	u.x = v.x * cos(a) - v.z * sin(a);
	u.y = v.y;
	u.z = v.x * sin(a) + v.z * cos(a);
	return (u);
}

t_vecteur	ft_rotatevecteurz(t_vecteur v, double a)
{
	t_vecteur	u;

	u.x = v.x * cos(a) - v.y * sin(a);
	u.y = v.x * sin(a) + v.y * cos(a);
	u.z = v.z;
	return (u);
}
