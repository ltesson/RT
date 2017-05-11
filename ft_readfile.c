/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:26:10 by ltesson           #+#    #+#             */
/*   Updated: 2017/05/03 19:04:59 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libft/libft.h"

void	ft_readfile(t_scene *s, char *av)
{
	int		fd;
	int		b;
	char	*line;

	s = (t_scene*)malloc(sizeof(t_scene));
	fd = open(file, O_RDONLY);
	b = 1;
	while (b)
	{
		get_next_line(fd, &line);
