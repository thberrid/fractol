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

int mandelbrot(t_complex *c, t_window *w)
{
	int			iterations;
	int			index;
	t_complex	z;
	long double	z_r2;
	long double	z_i2;
	(void)w;

	ft_bzero(&z, sizeof(t_complex));
	index = 0;
	iterations = 255;
	z_r2 = 0;
	z_i2 = 0;
	while (index < iterations)
	{
		z.i = 2 * z.r * z.i + c->i;
		z.r = z_r2 - z_i2 + c->r;
		z_r2 = z.r * z.r;
		z_i2 = z.i * z.i;
		if (z_r2 + z_i2 > 4)
			break ;
		index += 1;
	}
	return (index << 16);
}