/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: toboutal <toboutal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/26 21:11:03 by toboutal     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/27 18:08:08 by toboutal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void				print_usage(void)
{
	ft_putendl("usage : ./fractol -<option>");
	ft_putendl("");
	ft_putendl("mandelbrout :\t -m");
	ft_putendl("julia :\t\t -j");
	ft_putendl("burning ship :\t -b");
	ft_putendl("all :\t\t -all");
	ft_putendl("");
	exit(-1);
}

void				put_color(t_env *e)
{
	if (e->i == e->imax)
	{
		e->data[(e->bpl * (int)e->y) + (4 * (int)e->x) + 2] = 0;
		e->data[(e->bpl * (int)e->y) + (4 * (int)e->x) + 1] = 0;
		e->data[(e->bpl * (int)e->y) + (4 * (int)e->x)] = 0;
	}
	else
	{
		e->data[(e->bpl * (int)e->y) + (4 * (int)e->x) + 2] =
			(e->i * 145 / e->imax) * e->b;
		e->data[(e->bpl * (int)e->y) + (4 * (int)e->x) + 1] =
			sin((e->i * 0.16 + 8)) * 500 / e->imax + e->g;
		e->data[(e->bpl * (int)e->y) + (4 * (int)e->x)] =
			(e->i * 200 / e->imax) * e->r * e->r * e->r;
	}
}

void				menu(t_env *e)
{
	if (e->motion == 1)
		mlx_string_put(e->mlx, e->win, WIDTH / 2 - 40, 10, WHITE, "MOTION ON");
	mlx_string_put(e->mlx, e->win, 10, 85, WHITE, "MOTION ON/OFF Spacebar");
	mlx_string_put(e->mlx, e->win, 10, 100, WHITE, "ZOOM  | + | - | (NUM)");
	mlx_string_put(e->mlx, e->win, 10, 115, WHITE, "Move  Arrow key");
	mlx_string_put(e->mlx, e->win, 10, 130, WHITE, "RUSH  |1 | 2 | 3|");
	mlx_string_put(e->mlx, e->win, 10, 145, WHITE, "COLOR 4 | 5 | 6 ");
	mlx_string_put(e->mlx, e->win, 10, 160, WHITE, "ITER  + | -");
	mlx_string_put(e->mlx, e->win, 10, 175, WHITE, "RESET R");
	mlx_string_put(e->mlx, e->win, 10, 190, WHITE, "QUIT  ESC");
}

void				init_env(t_env *e)
{
	e->mlx = mlx_init();
	if (e->mlx == NULL)
	{
		ft_putendl("Connection to the graphical system failed");
		exit(0);
	}
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "Fractol by Toboutal");
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->bpl, &e->endian);
}

int					main(int ac, char **av)
{
	t_env			e;

	if (ac == 2)
	{
		init_env(&e);
		if (!ft_strcmp("-m", av[1]))
			do_mandel(&e);
		if (!ft_strcmp("-j", av[1]))
			do_julia(&e);
		if (!ft_strcmp("-b", av[1]))
			do_burn(&e);
		if (!ft_strcmp("-all", av[1]))
			system("sh all_fractals.sh");
		else
			print_usage();
	}
	else
		print_usage();
	return (0);
}
