/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:06:55 by user42            #+#    #+#             */
/*   Updated: 2021/04/03 16:07:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_complex	*pixel_to_complex(t_complex *z, t_pixel *px, t_window *w)
{
	/*
	z->r = px->x * w->precision - w->delta_zero.x * w->precision;
	z->i = (px->y * w->precision - w->delta_zero.y * w->precision) * -1;
	*/
	
	z->r = (px->x - w->delta_zero.x) * w->precision;
	z->i = (px->y - w->delta_zero.y) * w->precision;
	

	return (z);
}

int 	pixel_to_addr(t_pixel *pixel, t_img *imgdata)
{
	return (pixel->x * imgdata->pixel_size / 8 + pixel->y * imgdata->line_size);
}