/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_morevecteur.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 16:22:55 by ltesson           #+#    #+#             */
/*   Updated: 2017/05/16 17:00:03 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdio.h>

t_vecteur	ft_rotatevecteur(t_vecteur v, double a)
{
	t_vecteur	u;

	u.x = v.x * cos(a) - v.y * sin(a);
	u.y = v.x * sin(a) + v.y * cos(a);
	u.z = v.z;
	return (u);
}
