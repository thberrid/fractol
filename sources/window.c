/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:04:00 by user42            #+#    #+#             */
/*   Updated: 2021/04/03 16:04:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	image_init(t_window *w)
{
	w->img.id = mlx_new_image(w->mlx, VIEWPORT_LENGTH, VIEWPORT_LENGTH);
	w->img.canvas = mlx_get_data_addr(w->img.id, &w->img.pixel_size, &w->img.line_size, &w->img.endian);
}

int    window_init(t_window *w, char *av1)
{
	ft_bzero(w, sizeof(t_window));
    w->fractal_set = get_fractal_set(av1);
	if (!w->fractal_set)
		return (1);
	ft_strcpy(w->name, W_NAME);
	complex_plane_reset(w);
	thread_set(w);
    return (0);
}
