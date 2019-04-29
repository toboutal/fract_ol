/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   burning_ship.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: toboutal <toboutal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/26 22:52:10 by toboutal     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/27 18:03:51 by toboutal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void		do_burn(t_env *e)
{
	init_burn(e);
	draw_burn(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	menu(e);
	mlx_mouse_hook(e->win, event_mouse_b, e);
	mlx_hook(e->win, 2, 3, key_hook_b, e);
	mlx_loop(e->mlx);
}

void		init_burn(t_env *e)
{
	e->x1 = -3;
	e->x2 = 2.5;
	e->y1 = -2;
	e->y2 = 3;
	e->zoom = 230;
	e->imax = 80;
	e->r = 10;
	e->g = 10;
	e->b = 10;
}

void		draw_burn(t_env *e)
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
				e->z_r = fabs(e->z_r * e->z_r - e->z_i * e->z_i + e->c_r);
				e->z_i = fabs(2 * e->z_i * e->tmp + e->c_i);
				e->i++;
			}
			put_color(e);
			e->y++;
		}
		e->x++;
	}
}

void		redraw_burn(t_env *e)
{
	draw_burn(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	menu(e);
}
