/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 13:12:12 by ltesson           #+#    #+#             */
/*   Updated: 2017/05/15 18:31:28 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# include <math.h>
# include <mlx.h>
# define SPHERE 1
# define RED 16711680
# define BLUE 255

typedef struct			s_listobj
{
	void				*objet;
	int					type;
	struct s_listobj	*next;
}						t_listobj;

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
}				t_point;

typedef struct	s_vecteur
{
	double		x;
	double		y;
	double		z;
}				t_vecteur;

typedef struct	s_rayon
{
	t_point		pos;
	t_vecteur	vec;
}				t_rayon;

typedef struct	s_camera
{
	char		*name;
	int			xres;
	int			yres;
	t_point		pos;
	t_vecteur	vec;
	t_vecteur	upvec;
	t_vecteur	rightvec;
	double		viewdist;
	double		viewwidth;
	double		viewheight;
	t_point		firstpix;
	double		xindent;
	double		yindent;
}				t_camera;

typedef struct	s_sphere
{
	char		*name;
	t_point		pos;
	double		r;
	int			color;
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
	t_listobj	*list;
	t_sphere	*sphere;
	int			error;
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
void			ft_initcam(t_camera *cam);
t_vecteur		ft_normalizevecteur(t_vecteur v);
t_vecteur		ft_getvecteur(t_point a, t_point b);
t_vecteur		ft_multvecteur(t_vecteur v, double t);
t_vecteur		ft_addvecteur(t_vecteur v, t_vecteur w);
t_point			ft_translation(t_point p, t_vecteur v);
int				ft_intersect(t_rayon ray, t_sphere *sphere, double *t, int *color);
int				ft_error(int);
void			ft_additem(t_scene *s);
void			ft_addsphere(t_scene *s, t_point pos, double r, int color);

#endif
