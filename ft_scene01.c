/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:36:58 by ltesson           #+#    #+#             */
/*   Updated: 2017/05/23 16:11:40 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_scene01(t_scene *s)
{
	t_point		pos;
	double		r;
	int			color;

	pos.x = 0;
	pos.y = 0;
	pos.z = 1;
	r = 60;
	color = DARKGREEN;
	ft_addplan(s, pos, r, color);
	if (s->error)
		return;
	pos.x = 0;
	pos.y = 0;
	pos.z = 1;
	r = -60;
	color = DARKRED;
	ft_addplan(s, pos, r, color);
	if (s->error)
		return;
	pos.x = 1;
	pos.y = 0;
	pos.z = 0;
	r = -120;
	color = BLUE;
	ft_addplan(s, pos, r, color);
	if (s->error)
		return;
	pos.x = 0;
	pos.y = 0;
	pos.z = -40;
	r = 8;
	color = RED;
	ft_addsphere(s, pos, r, color);
	if (s->error)
		return;
	pos.x = 50;
	pos.y = 50;
	pos.z = 60;
	r = 15;
	color = GREY;
	ft_addsphere(s, pos, r, color);
	if (s->error)
		return;
	pos.x = 50;
	pos.y = 50;
	pos.z = -60;
	r = 15;
	color = GREY;
	ft_addsphere(s, pos, r, color);
	if (s->error)
		return;
	pos.x = 50;
	pos.y = -50;
	pos.z = 60;
	r = 15;
	color = GREY;
	ft_addsphere(s, pos, r, color);
	if (s->error)
		return;
	pos.x = 50;
	pos.y = -50;
	pos.z = -60;
	r = 15;
	color = GREY;
	ft_addsphere(s, pos, r, color);
	if (s->error)
		return;
	pos.x = -50;
	pos.y = 50;
	pos.z = 60;
	r = 15;
	color = GREY;
	ft_addsphere(s, pos, r, color);
	if (s->error)
		return;
	pos.x = -50;
	pos.y = 50;
	pos.z = -60;
	r = 15;
	color = GREY;
	ft_addsphere(s, pos, r, color);
	if (s->error)
		return;
	pos.x = -50;
	pos.y = -50;
	pos.z = 60;
	r = 15;
	color = GREY;
	ft_addsphere(s, pos, r, color);
	if (s->error)
		return;
	pos.x = -50;
	pos.y = -50;
	pos.z = -60;
	r = 15;
	color = GREY;
	ft_addsphere(s, pos, r, color);
	if (s->error)
		return;
	pos.x = 50;
	pos.y = 50;
	pos.z = 0;
	r = 10;
	color = GREY;
	ft_addvcylindre(s, pos, r, color);
	if (s->error)
		return;
	pos.x = -50;
	pos.y = 50;
	pos.z = 0;
	r = 10;
	color = GREY;
	ft_addvcylindre(s, pos, r, color);
	if (s->error)
		return;
	pos.x = 50;
	pos.y = -50;
	pos.z = 0;
	r = 10;
	color = GREY;
	ft_addvcylindre(s, pos, r, color);
	if (s->error)
		return;
	pos.x = -50;
	pos.y = -50;
	pos.z = 0;
	r = 10;
	color = GREY;
	ft_addvcylindre(s, pos, r, color);
}
