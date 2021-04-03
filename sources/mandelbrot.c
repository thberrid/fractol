/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 11:46:39 by user42            #+#    #+#             */
/*   Updated: 2021/04/03 11:46:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int mandelbrot(t_pixel *pixel, t_window *w)
{
	t_complex	z;

	pixel_to_complex(&z, pixel, w);
	if (z.r == z.i)
		return (255 << 8);
	if (pixel->x == w->delta_zero.x || pixel->y == w->delta_zero.y)
		return (255 << 16);
    return (0);
}