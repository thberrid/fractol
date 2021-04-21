/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 11:13:55 by thberrid          #+#    #+#             */
/*   Updated: 2021/03/29 11:14:24 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		main(int ac, char **av)
{
	t_window	w;

	if (ac != 2 || window_init(&w, av[1]))
		return (print_usage());
	w.mlx = mlx_init();
	if (!w.mlx || !(w.id = mlx_new_window(w.mlx, VP_LENGTH, VP_LENGTH, w.name))
		|| image_init(&w))
		return (print_init_error());
	if (thread_draw(&w))
		return (print_thread_error());
	mlx_key_hook(w.id, w.fractal_set->kboard, &w);
	mlx_mouse_hook(w.id, w.fractal_set->mouse, &w);
	if (w.fractal_set->hover)
		mlx_hook(w.id, 6, 1L << 6, w.fractal_set->hover, &w);
	mlx_loop(w.mlx);
	return (0);
}
