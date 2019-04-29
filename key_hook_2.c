/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_hook_2.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: toboutal <toboutal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/26 22:47:02 by toboutal     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/27 18:07:21 by toboutal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void			key_quit(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img);
	mlx_destroy_window(e->mlx, e->win);
	exit(0);
}

double			rush(int key)
{
	static double rush = 0.3;

	if (key == 82)
		rush = 0.3;
	if (key == 83)
		rush = 0.001;
	if (key == 84)
		rush = 0.000001;
	return (rush);
}

void			key_color(int key, t_env *e, char *name)
{
	(key == 23) ? e->g += 3 : 0;
	(key == 22) ? e->b += 3 : 0;
	(key == 21) ? e->r += 3 : 0;
	if (!(ft_strcmp("mandel", name)))
		redraw_mandel(e);
	if (!(ft_strcmp("julia", name)))
		redraw_julia(e);
	if (!(ft_strcmp("burn", name)))
		redraw_burn(e);
}

void			key_direction(int key, t_env *e, char *name)
{
	double speed;

	speed = rush(key);
	(key == UP) ? e->y1 += speed : 0;
	(key == DOWN) ? e->y1 -= speed : 0;
	(key == LEFT) ? e->x1 += speed : 0;
	(key == RIGHT) ? e->x1 -= speed : 0;
	if (!(ft_strcmp("mandel", name)))
		redraw_mandel(e);
	if (!(ft_strcmp("julia", name)))
		redraw_julia(e);
	if (!(ft_strcmp("burn", name)))
		redraw_burn(e);
}
