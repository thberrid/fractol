/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <thberrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 09:56:52 by thberrid          #+#    #+#             */
/*   Updated: 2021/04/12 09:57:04 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		julia_mouse(int x, int y, t_window *w)
{
	t_pixel		pixel;

	if (w->state == LOCKED)
		return (0);
	w->state = LOCKED;
	pixel.x = x;
	pixel.y = y;
	pixel_to_complex(&w->mouse_over, &pixel, w);
	if (thread_draw(w))
		force_quit(w);
	return (0);
}

int		julia(t_complex *zsrc, t_window *w)
{
	int			iterations;
	int			index;
	t_complex	z;
	t_complex	z_sqr;

	ft_memcpy(&z, zsrc, sizeof(t_complex));
	index = 0;
	iterations = 50 + w->zoom * 3;
	while (index < iterations)
	{
		z_sqr.r = z.r * z.r;
		z_sqr.i = z.i * z.i;
		z.i = 2 * z.r * z.i + w->mouse_over.i;
		z.r = z_sqr.r - z_sqr.i + w->mouse_over.r;
		if (z_sqr.i + z_sqr.r > 4)
			break ;
		index += 1;
	}
	if (index == iterations)
		return (0);
	return (int_to_color(index));
}
