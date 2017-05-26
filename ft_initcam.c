/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initcam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 14:44:07 by ltesson           #+#    #+#             */
/*   Updated: 2017/05/24 18:59:20 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdio.h>

void	ft_getrightvec(t_camera *cam)
{
	cam->rightvec.x = -cam->vec.y;
	cam->rightvec.y = cam->vec.x;
	cam->rightvec.z = 0;
	if (cam->rightvec.x == 0 && cam->rightvec.y == 0)
		cam->rightvec.y = 1;
	cam->rightvec = ft_normalizevecteur(cam->rightvec);
}

void	ft_getupvec(t_camera *cam)
{
	double	q;

	cam->upvec.z = sqrt(cam->vec.x * cam->vec.x + cam->vec.y * cam->vec.y);
	if (cam->vec.x != 0 && cam->vec.y != 0)
	{
		q = cam->vec.x / cam->vec.y;
		cam->upvec.x = sqrt(cam->vec.z * cam->vec.z / (1 + 1/(q * q)));
		if (cam->vec.z * cam->vec.x > 0)
			cam->upvec.x = -cam->upvec.x;
		cam->upvec.y = cam->upvec.x / q;
	}
	else if (cam->vec.y == 0)
	{
		if (cam->vec.x > 0)
			cam->upvec.x = -cam->vec.z;
		else
			cam->upvec.x = cam->vec.z;
		cam->upvec.y = 0;
	}
	else if (cam->vec.x == 0)
	{
		if (cam->vec.y > 0)
			cam->upvec.y = -cam->vec.z;
		else
			cam->upvec.y = cam->vec.z;
		cam->upvec.x = 0;
	}
}

void	ft_initcam(t_camera *cam)
{
	if (cam->vec.x == 0 && cam->vec.y == 0 && cam->vec.z == 0)
		cam->vec.x = 1;
	cam->vec = ft_normalizevecteur(cam->vec);
	ft_getrightvec(cam);
	ft_getupvec(cam);
	cam->xindent = cam->viewwidth / cam->xres;
	cam->yindent = cam->viewheight / -cam->yres;
	cam->firstpix = ft_translation(cam->pos, ft_addvecteur(ft_multvecteur(cam->vec, cam->viewdist), ft_addvecteur(ft_multvecteur(cam->rightvec, cam->viewwidth / -2), ft_multvecteur(cam->upvec, cam->viewheight / 2))));
	printf("vecteur = {%f, %f, %f}\nrightvec = {%f, %f, %f}\nupvec = {%f, %f, %f}\n",
			cam->vec.x, cam->vec.y, cam->vec.z,
			cam->rightvec.x, cam->rightvec.y, cam->rightvec.z,
			cam->upvec.x, cam->upvec.y, cam->upvec.z);
//	printf("xindent = %f\nyindent = %f\nfirstpix = {%f, %f, %f}\n",
//			cam->xindent, cam->yindent,
//			cam->firstpix.x, cam->firstpix.y, cam->firstpix.z);
}
