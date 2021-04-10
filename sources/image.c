/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 17:11:05 by user42            #+#    #+#             */
/*   Updated: 2021/04/03 17:11:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int 	pixel_to_addr(t_pixel *pixel, t_mlx_img *imgdata)
{
	return (pixel->x * imgdata->pixel_size / 8 + pixel->y * imgdata->line_size);
}
