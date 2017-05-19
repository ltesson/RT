/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 16:51:20 by ltesson           #+#    #+#             */
/*   Updated: 2017/05/19 17:21:55 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_intersect(t_rayon ray, t_listobj *liste, double *t, int *color)
{
	if (liste->type == SPHERE)
		return (ft_intersphere(ray, (t_sphere*)liste->objet, t, color));
//	if (liste->type == PLAN)
//		return (ft_interplan(ray, (t_plan*)liste->objet, t, color));
	return (0);
}
