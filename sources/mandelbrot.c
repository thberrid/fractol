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
	int			iterations;
	int			index;
	t_complex	c;
	t_complex	z;
	float		z_r2;
	float		z_i2;

	pixel_to_complex(&c, pixel, w);
	ft_bzero(&z, sizeof(t_complex));
	index = 0;
	z_i2 = 0;
	z_r2 = 0;
	iterations = 300;
	while (index < iterations && z_r2 + z_i2 <= 4)
	{
		z.i = 2 * z.r * z.i + c.i;
		z.r = z_r2 - z_i2 + c.r;
		z_r2 = z.r * z.r;
		z_i2 = z.i * z.i;
		index += 1;
	}
	//return (0x0000ffff - index);
	
	if (index >= iterations)
		return (0xf);
	
	//	else
//		return (index * 2 << 16);
		/*
	if (pixel->x == w->delta_zero.x || pixel->y == w->delta_zero.y)
		return (255 << 16);
	*/
    return (0);
}