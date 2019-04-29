/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mandelbrot.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: toboutal <toboutal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/26 22:54:42 by toboutal     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/27 18:07:53 by toboutal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void		do_mandel(t_env *e)
{
	init_mandel(e);
	draw_mandel(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	menu(e);
	mlx_mouse_hook(e->win, event_mouse_m, e);
	mlx_hook(e->win, 2, 3, key_hook_m, e);
	mlx_hook(e->win, 6, 1L << 6, mandel_motion, e);
	mlx_loop(e->mlx);
}

void		init_mandel(t_env *e)
{
	e->x1 = -2.6;
	e->x2 = 2.5;
	e->y1 = -2.1;
	e->y2 = 3;
	e->zoom = 200;
	e->imax = 50;
	e->r = 10;
	e->g = 10;
	e->b = 10;
	e->motion = 0;
}

void		draw_mandel(t_env *e)
{
	e->x = 0;
	while (e->x < WIDTH)
	{
		e->y = 0;
		while (e->y < HEIGHT)
		{
			e->c_r = e->x / e->zoom + e->x1;
			e->c_i = e->y / e->zoom + e->y1;
			e->z_r = 0;
			e->z_i = 0;
			e->i = 0;
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->imax)
			{
				e->tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = 2 * e->z_i * e->tmp + e->c_i;
				e->i++;
			}
			put_color(e);
			e->y++;
		}
		e->x++;
	}
}

void		redraw_mandel(t_env *e)
{
	draw_mandel(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	menu(e);
}

int			mandel_motion(int x, int y, t_env *e)
{
	if (e->motion == 1)
		if (x > 0 && x <= WIDTH && y > 0 && y <= HEIGHT)
		{
			e->z_r = (double)x / e->zoom;
			e->z_i = (double)y / e->zoom;
			redraw_mandel(e);
		}
	return (0);
}
