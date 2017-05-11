/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:04:17 by ltesson           #+#    #+#             */
/*   Updated: 2017/05/09 18:08:24 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdlib.h>

int		main()
{
	t_scene		*s;

	s = (t_scene*)malloc(sizeof(t_scene));
	s->cam = (t_camera*)malloc(sizeof(t_camera));
	s->sphere = (t_sphere*)malloc(sizeof(t_sphere));
	s->cam->xres = 640;
	s->cam->yres = 480;
	s->cam->xpos = -200;
	s->cam->ypos = 0;
	s->cam->zpos = 0;
	s->cam->a = 0;
	s->cam->b = 0;
	s->sphere->x = 0;
	s->sphere->y = 0;
	s->sphere->z = 0;
	s->sphere->r = 50;
	ft_mlx(s);
	return (0);
}
