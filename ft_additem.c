/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:30:00 by ltesson           #+#    #+#             */
/*   Updated: 2017/05/16 17:23:11 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_additem(t_scene *s)
{
	t_point		pos;
	double		r;
	int			color;

	pos.x = 50;
	pos.y = 25;
	pos.z = 25;
	r = 25;
	color = BLUE;
	ft_addsphere(s, pos, r, color);
	if (s->error)
		return;
	pos.x = 50;
	pos.y = -25;
	pos.z = 25;
	r = 20;
	color = GREEN;
	ft_addsphere(s, pos, r, color);
	if (s->error)
		return;
	pos.x = 50;
	pos.y = 0;
	pos.z = 0;
	r = 40;
	color = RED;
	ft_addsphere(s, pos, r, color);
}
