/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <thberrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 10:53:49 by thberrid          #+#    #+#             */
/*   Updated: 2021/04/12 10:53:59 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_complex	*pixel_to_complex(t_complex *dst, t_pixel *src, t_window *w)
{
	ft_bzero(dst, sizeof(t_complex));
	dst->r = src->x * w->complex_plane.precision;
	dst->i = src->y * w->complex_plane.precision * -1;
	dst->r += w->complex_plane.minimum.r;
	dst->i += w->complex_plane.minimum.i;
	return (dst);
}

int			pixel_to_addr(t_pixel *pixel, t_mlx_img *imgdata)
{
	int	addr;

	addr = pixel->x * imgdata->pixel_size / 8;
	addr += pixel->y * imgdata->line_size;
	return (addr);
}
