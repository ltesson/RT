/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 16:51:20 by ltesson           #+#    #+#             */
/*   Updated: 2017/05/19 18:50:02 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_intersect(t_rayon *ray, t_listobj *liste)
{
	if (liste->type == SPHERE)
		ft_intersphere(ray, (t_sphere*)liste->objet);
	else if (liste->type == PLAN)
		ft_interplan(ray, (t_plan*)liste->objet);
}
