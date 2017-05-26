/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltesson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 13:12:12 by ltesson           #+#    #+#             */
/*   Updated: 2017/05/23 16:24:30 by ltesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# include <math.h>
# include <mlx.h>
# define SPOT 0
# define SPHERE 1
# define PLAN 2
# define VCYLINDRE 103
# define RED 13511728
# define BLUE 3093151
# define GREEN 3127874
# define DARKBLUE 1645713
# define DARKRED 5319981
# define DARKGREEN 4805931
# define GREY 8159104

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
	double		t;
	int			color;
}				t_rayon;

typedef struct	s_camera
{
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
	t_point		pos;
	double		r;
	int			color;
}				t_sphere;

typedef struct	s_plan
{
	double		a;
	double		b;
	double		c;
	double		d;
	int			color;
}				t_plan;

typedef struct	s_vcylindre
{
	t_point		pos;
	double		r;
	int			color;
}				t_vcylindre;

typedef struct	s_cylindre
{
	double		a;
	double		b;
	double		c;
	double		r;
}				t_cylindre;

typedef struct	s_spot
{
	t_point		pos;
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
t_vecteur		ft_rotatevecteur(t_vecteur v, double a);
void			ft_intersect(t_rayon *ray, t_listobj *liste);
void			ft_intersphere(t_rayon *ray, t_sphere *sphere);
void			ft_interplan(t_rayon *ray, t_plan *plan);
void			ft_intervcylindre(t_rayon *ray, t_vcylindre *vcylindre);
int				ft_error(int);
void			ft_scene01(t_scene *s);
void			ft_addsphere(t_scene *s, t_point pos, double r, int color);
void			ft_addplan(t_scene *s, t_point pos, double r, int color);
void			ft_addvcylindre(t_scene *s, t_point pos, double r, int color);
int				ft_move(int keycode, t_camera *cam);

#endif
