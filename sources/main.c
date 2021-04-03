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
	t_window    w;

	if (ac != 2 || window_init(&w, av[1]))
		print_usage();
	else
	{	
		w.mlx = mlx_init();
		w.id = mlx_new_window(w.mlx, w.width, w.height, w.name);
		image_draw(&w);
		mlx_key_hook(w.id, &keyboard, &w);
		mlx_mouse_hook(w.id, &mouse, &w);
		mlx_loop(w.mlx);
	}
	return (0);
}
