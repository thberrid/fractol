/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 11:46:39 by user42            #+#    #+#             */
/*   Updated: 2021/04/03 11:46:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		mandelbrot(t_complex *c, t_window *w)
{
	int			iterations;
	int			index;
	t_complex	z;
	t_complex	z_sqr;

	ft_bzero(&z, sizeof(t_complex));
	ft_bzero(&z_sqr, sizeof(t_complex));
	index = 0;
	iterations = 50 + w->zoom * 3;
	while (index < iterations)
	{
		z.i = 2 * z.r * z.i + c->i;
		z.r = z_sqr.r - z_sqr.i + c->r;
		z_sqr.r = z.r * z.r;
		z_sqr.i = z.i * z.i;
		if (z_sqr.r + z_sqr.i > 4)
			break ;
		index += 1;
	}
	if (index == iterations)
		return (0);
	return (int_to_color(index));
}
