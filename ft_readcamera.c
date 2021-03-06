/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readcamera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 18:39:11 by ltesson           #+#    #+#             */
/*   Updated: 2017/06/15 18:44:20 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libft/libft.h"
#include <stdlib.h>

void	ft_cameradata(t_camera *camera, char *line)
{
	char	**split;

	split = ft_strsplit(line, ':');
	if (split == NULL)
		return ;
	if (split[1] != NULL)
	{
		if (ft_strcasecmp("x", split[0]) == 0)
			camera->pos.x = ft_atof(split[1]);
		if (ft_strcasecmp("y", split[0]) == 0)
			camera->pos.y = ft_atof(split[1]);
		if (ft_strcasecmp("z", split[0]) == 0)
			camera->pos.z = ft_atof(split[1]);
		if (ft_strcasecmp("a", split[0]) == 0)
			camera->vec.x = ft_atof(split[1]);
		if (ft_strcasecmp("b", split[0]) == 0)
			camera->vec.y = ft_atof(split[1]);
		if (ft_strcasecmp("c", split[0]) == 0)
			camera->vec.z = ft_atof(split[1]);
	}
	ft_freesplit(split);
}

void	ft_readcamera(t_scene *s, int fd, char *line, int *i)
{
	while (ft_strlen(line) && *i == 1)
	{
		*i = get_next_line(fd, &line);
		if (ft_strlen(line))
			ft_cameradata(s->cam, line);
	}
}
