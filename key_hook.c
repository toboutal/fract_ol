/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_hook.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: toboutal <toboutal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/26 22:46:42 by toboutal     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/27 18:07:04 by toboutal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int			key_hook_m(int key, t_env *e)
{
	(key == ESC) ? key_quit(e) : 0;
	key_direction(key, e, "mandel");
	(key == PLUS_NUM) ? e->zoom *= 1.1 : 0;
	(key == PLUS_NUM) ? redraw_mandel(e) : 0;
	(key == MINUS_NUM) ? e->zoom *= 0.9 : 0;
	(key == MINUS_NUM) ? redraw_mandel(e) : 0;
	(key == PLUS) ? e->imax += 20 : 0;
	(key == PLUS) ? redraw_mandel(e) : 0;
	if (key == MINUS)
		(e->imax -= 20) == 0 ? e->imax = 20 : 0;
	(key == MINUS) ? redraw_mandel(e) : 0;
	(key == RESET) ? init_mandel(e) : 0;
	(key == RESET) ? redraw_mandel(e) : 0;
	if (key == SPACEBAR)
		e->motion = (e->motion == 0 ? 1 : 0);
	key_color(key, e, "mandel");
	return (1);
}

int			key_hook_j(int key, t_env *e)
{
	(key == ESC) ? key_quit(e) : 0;
	key_direction(key, e, "julia");
	(key == PLUS_NUM) ? e->zoom *= 1.1 : 0;
	(key == PLUS_NUM) ? redraw_julia(e) : 0;
	(key == MINUS_NUM) ? e->zoom /= 1.1 : 0;
	(key == MINUS_NUM) ? redraw_julia(e) : 0;
	(key == PLUS) ? e->imax += 20 : 0;
	(key == PLUS) ? redraw_julia(e) : 0;
	if (key == MINUS)
		(e->imax -= 20) == 0 ? e->imax = 20 : 0;
	(key == MINUS) ? redraw_julia(e) : 0;
	(key == RESET) ? init_julia(e) : 0;
	(key == RESET) ? redraw_julia(e) : 0;
	if (key == SPACEBAR)
		e->motion = (e->motion != 1 ? 1 : 0);
	key_color(key, e, "julia");
	return (1);
}

int			key_hook_b(int key, t_env *e)
{
	(key == ESC) ? key_quit(e) : 0;
	key_direction(key, e, "burn");
	(key == PLUS_NUM) ? e->zoom *= 1.1 : 0;
	(key == PLUS_NUM) ? redraw_burn(e) : 0;
	(key == MINUS_NUM) ? e->zoom /= 1.1 : 0;
	(key == MINUS_NUM) ? redraw_burn(e) : 0;
	(key == PLUS) ? e->imax += 20 : 0;
	(key == PLUS) ? redraw_burn(e) : 0;
	if (key == MINUS)
		(e->imax -= 20) == 0 ? e->imax = 20 : 0;
	(key == MINUS) ? redraw_burn(e) : 0;
	(key == RESET) ? init_burn(e) : 0;
	(key == RESET) ? redraw_burn(e) : 0;
	key_color(key, e, "burn");
	return (1);
}
