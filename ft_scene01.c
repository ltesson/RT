/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:36:58 by ltesson           #+#    #+#             */
/*   Updated: 2017/06/08 18:11:35 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_scene01(t_scene *s)
{
	t_point		pos;
	t_point		t;
	double		r;
	int			color;

	pos.x = -200;
	pos.y = -300;
	pos.z = 20;
	r = 0.9;
	ft_addspot(s, pos, r);
	if (s->error)
		return ;
	pos.x = -200;
	pos.y = 300;
	pos.z = 20;
	r = 0.9;
	ft_addspot(s, pos, r);
	if (s->error)
		return ;
	pos.x = 0;
	pos.y = 0;
	pos.z = 1;
	r = 60;
	color = DARKGREEN;
	ft_addplan(s, pos, r, color);
	if (s->error)
		return ;
	pos.x = 0;
	pos.y = 0;
	pos.z = 1;
	r = -60;
	color = DARKRED;
	ft_addplan(s, pos, r, color);
	if (s->error)
		return ;
	pos.x = 1;
	pos.y = 1;
	pos.z = 1;
	r = -120;
	color = BLUE;
	ft_addplan(s, pos, r, color);
	if (s->error)
		return ;
	pos.x = 10;
	pos.y = -30;
	pos.z = -20;
	t.x = 1;
	t.y = 0;
	t.z = 0.4;
	color = RED;
	ft_addcone(s, pos, t, color);
	if (s->error)
		return ;
	pos.x = 5;
	pos.y = 30;
	pos.z = -30;
	t.x = -1;
	t.y = 0;
	t.z = 5;
	color = GREEN;
	ft_addcylindre(s, pos, t, color);
	if (s->error)
		return ;
	pos.x = 50;
	pos.y = 50;
	pos.z = 60;
	r = 15;
	color = GREY;
	ft_addsphere(s, pos, r, color);
	if (s->error)
		return ;
	pos.x = 50;
	pos.y = 50;
	pos.z = -60;
	r = 15;
	color = GREY;
	ft_addsphere(s, pos, r, color);
	if (s->error)
		return ;
	pos.x = 50;
	pos.y = -50;
	pos.z = 60;
	r = 15;
	color = GREY;
	ft_addsphere(s, pos, r, color);
	if (s->error)
		return ;
	pos.x = 50;
	pos.y = -50;
	pos.z = -60;
	r = 15;
	color = GREY;
	ft_addsphere(s, pos, r, color);
	if (s->error)
		return ;
	pos.x = -50;
	pos.y = 50;
	pos.z = 60;
	r = 15;
	color = GREY;
	ft_addsphere(s, pos, r, color);
	if (s->error)
		return ;
	pos.x = -50;
	pos.y = 50;
	pos.z = -60;
	r = 15;
	color = GREY;
	ft_addsphere(s, pos, r, color);
	if (s->error)
		return ;
	pos.x = -50;
	pos.y = -50;
	pos.z = 60;
	r = 15;
	color = GREY;
	ft_addsphere(s, pos, r, color);
	if (s->error)
		return ;
	pos.x = -50;
	pos.y = -50;
	pos.z = -60;
	r = 15;
	color = GREY;
	ft_addsphere(s, pos, r, color);
	if (s->error)
		return ;
	pos.x = 50;
	pos.y = 50;
	pos.z = 0;
	t.x = 0;
	t.y = 0;
	t.z = 10;
	color = GREY;
	ft_addcylindre(s, pos, t, color);
	if (s->error)
		return ;
	pos.x = -50;
	pos.y = 50;
	pos.z = 0;
	t.x = 0;
	t.y = 0;
	t.z = 10;
	color = GREY;
	ft_addcylindre(s, pos, t, color);
	if (s->error)
		return ;
	pos.x = 50;
	pos.y = -50;
	pos.z = 0;
	t.x = 0;
	t.y = 0;
	t.z = 10;
	color = GREY;
	ft_addcylindre(s, pos, t, color);
	if (s->error)
		return ;
	pos.x = -50;
	pos.y = -50;
	pos.z = 0;
	t.x = 0;
	t.y = 0;
	t.z = 10;
	color = GREY;
	ft_addcylindre(s, pos, t, color);
}
