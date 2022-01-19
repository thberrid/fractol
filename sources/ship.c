/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <thberrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 09:17:48 by thberrid          #+#    #+#             */
/*   Updated: 2021/04/21 09:17:51 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static long double	lfabs(long double n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

int					ship(t_complex *c, t_window *w)
{
	int			iterations;
	int			index;
	t_complex	z;
	t_complex	z_sqr;

	ft_bzero(&z, sizeof(t_complex));
	ft_bzero(&z_sqr, sizeof(t_complex));
	index = 0;
	iterations = 100 + w->zoom;
	while (index < iterations)
	{
		z_sqr.r = z.r * z.r;
		z_sqr.i = z.i * z.i;
		z.i = 2 * lfabs(z.r * z.i) - c->i;
		z.r = z_sqr.r - z_sqr.i - c->r;
		if (z_sqr.i + z_sqr.r > 4)
			break ;
		index += 1;
	}
	if (index == iterations)
		return (0xffffffff);
	return ((index * 4) << 16);
}
