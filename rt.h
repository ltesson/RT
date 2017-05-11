/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 13:12:12 by ltesson           #+#    #+#             */
/*   Updated: 2017/05/09 18:09:14 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# include <math.h>
# include <mlx.h>

typedef struct	s_camera
{
	char		*name;
	int			xres;
	int			yres;
	double		xpos;
	double		ypos;
	double		zpos;
	double		a;
	double		b;
}				t_camera;

typedef struct	s_sphere
{
	char		*name;
	double		x;
	double		y;
	double		z;
	double		r;
}				t_sphere;

typedef struct	s_plan
{
	char		*name;
	double		a;
	double		b;
	double		c;
}				t_plan;

typedef struct	s_cylindre
{
	char		*name;
	double		a;
	double		b;
	double		c;
	double		r;
}				t_cylindre;

typedef struct	s_spot
{
	char		*name;
	double		x;
	double		y;
	double		z;
}				t_spot;

typedef struct	s_scene
{
	t_camera	*cam;
	t_sphere	*sphere;
}				t_scene;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	t_scene		*s;
}				t_env;

void			ft_readfile(t_scene *s, char *av);
void			ft_mlx(t_scene *s);
void			ft_drawscene(t_scene *s, t_env *e);

#endif
