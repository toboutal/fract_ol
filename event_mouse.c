/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event_mouse.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: toboutal <toboutal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/26 22:53:00 by toboutal     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/27 18:07:40 by toboutal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int			event_mouse_j(int key, int x, int y, t_env *e)
{
	double x_mouse;
	double y_mouse;

	if (y > 0)
	{
		x_mouse = (x / e->zoom) + e->x1;
		y_mouse = (y / e->zoom) + e->y1;
		if (key == 4 || key == 1)
		{
			e->zoom *= 1.1;
			e->x1 = x_mouse - (x / e->zoom);
			e->y1 = y_mouse - (y / e->zoom);
			redraw_julia(e);
		}
		if (key == 5 || key == 2)
		{
			e->zoom /= 1.1;
			e->x1 = x_mouse - (x / e->zoom);
			e->y1 = y_mouse - (y / e->zoom);
			redraw_julia(e);
		}
	}
	return (0);
}

int			event_mouse_m(int key, int x, int y, t_env *e)
{
	double x_mouse;
	double y_mouse;

	if (y > 0)
	{
		x_mouse = (x / e->zoom) + e->x1;
		y_mouse = (y / e->zoom) + e->y1;
		if (key == 4 || key == 1)
		{
			e->zoom *= 1.1;
			e->x1 = x_mouse - x / e->zoom;
			e->y1 = y_mouse - y / e->zoom;
			redraw_mandel(e);
		}
		if (key == 5 || key == 2)
		{
			e->zoom *= 0.9;
			e->x1 = x_mouse - (x / e->zoom);
			e->y1 = y_mouse - (y / e->zoom);
			redraw_mandel(e);
		}
	}
	return (0);
}

int			event_mouse_b(int key, int x, int y, t_env *e)
{
	double x_mouse;
	double y_mouse;

	if (y > 0)
	{
		x_mouse = (x / e->zoom) + e->x1;
		y_mouse = (y / e->zoom) + e->y1;
		if (key == 4 || key == 1)
		{
			e->zoom *= 1.1;
			e->x1 = x_mouse - (x / e->zoom);
			e->y1 = y_mouse - (y / e->zoom);
			redraw_burn(e);
		}
		if (key == 5 || key == 2)
		{
			e->zoom /= 1.1;
			e->x1 = x_mouse - (x / e->zoom);
			e->y1 = y_mouse - (y / e->zoom);
			redraw_burn(e);
		}
	}
	return (0);
}
