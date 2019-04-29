/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: toboutal <toboutal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/26 23:00:36 by toboutal     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/27 18:04:38 by toboutal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define HEIGHT 900
# define WIDTH 1000
# define CENTER_H HEIGHT / 2
# define CENTER_W WIDTH / 2
# define PI 3.14159265
# define WHITE 0xFFFFFF
# define ESC 53
# define SPACEBAR 49
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define RESET 15
# define PLUS_NUM 69
# define MINUS_NUM 78
# define PLUS 24
# define MINUS 27

# include <stdlib.h>
# include <math.h>
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"

typedef struct		s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int		bpp;
	int		bpl;
	int		endian;

	char	f;
	double	zoom;
	double	x;
	double	y;
	double	y1;
	double	y2;
	double	x1;
	double	x2;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	tmp;

	int		i;
	int		imax;
	int		motion;

	int		theta;
	int		radius;

	int		r;
	int		g;
	int		b;
}					t_env;

int					anim(t_env *e);
void				ft_circle(t_env *e);
void				put_pixel_to_img(t_env *e, int x, int y);
void				init_env(t_env *e);
void				menu(t_env *e);
void				put_color(t_env *e);
void				print_usage(void);
void				menu(t_env *e);
void				key_quit(t_env *e);
void				key_direction(int key, t_env *e, char *f);
int					envent_mouse(int key, int x, int y, t_env *e);
void				key_color(int key, t_env *e, char *name);

void				do_mandel(t_env *e);
void				do_julia(t_env *e);
void				do_tricorn(t_env *e);
void				do_sword(t_env *e);
void				do_burn(t_env *e);
void				do_chameleon(t_env *e);

void				init_mandel(t_env *e);
void				init_julia(t_env *e);
void				init_tricorn(t_env *e);
void				init_sword(t_env *e);
void				init_burn(t_env *e);
void				init_chameleon(t_env *e);

void				draw_mandel(t_env *e);
void				draw_julia(t_env *e);
void				draw_tricorn(t_env *e);
void				draw_sword(t_env *e);
void				draw_burn(t_env *e);
void				draw_chameleon(t_env *e);

void				redraw_mandel(t_env *e);
void				redraw_julia(t_env *e);
void				redraw_tricorn(t_env *e);
void				redraw_sword(t_env *e);
void				redraw_burn(t_env *e);
void				redraw_chameleon(t_env *e);

int					julia_motion(int x, int y, t_env *e);
int					julia_motion2(int x, int y, t_env *e);
int					mandel_motion(int x, int y, t_env *e);

int					key_hook_m(int key, t_env *e);
int					key_hook_j(int key, t_env *e);
int					key_hook_t(int key, t_env *e);
int					key_hook_s(int key, t_env *e);
int					key_hook_b(int key, t_env *e);
int					key_hook_c(int key, t_env *e);

int					event_mouse_m(int key, int c, int y, t_env *e);
int					event_mouse_j(int key, int c, int y, t_env *e);
int					event_mouse_t(int key, int c, int y, t_env *e);
int					event_mouse_s(int key, int c, int y, t_env *e);
int					event_mouse_b(int key, int c, int y, t_env *e);
int					event_mouse_c(int key, int c, int y, t_env *e);

#endif
