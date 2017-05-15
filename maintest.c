/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:04:17 by ltesson           #+#    #+#             */
/*   Updated: 2017/05/15 18:31:46 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdlib.h>

int		main()
{
	t_scene		*s;

	s = (t_scene*)malloc(sizeof(t_scene));
	s->cam = (t_camera*)malloc(sizeof(t_camera));
	s->cam->xres = 640;
	s->cam->yres = 480;
	s->cam->pos.x = -200;
	s->cam->pos.y = 0;
	s->cam->pos.z = 0;
	s->cam->vec.x = 1;
	s->cam->vec.y = 0;
	s->cam->vec.z = 0;
	s->cam->viewdist = 1;
	s->cam->viewwidth = 0.640;
	s->cam->viewheight = 0.480;
	ft_initcam(s->cam);
	s->list = NULL;
	s->error = 0;
	ft_additem(s);
	if (s->error)
		return (ft_error(s->error));
	ft_mlx(s);
	return (0);
}
