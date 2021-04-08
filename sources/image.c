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

void	image_init(t_window *w, t_mlx_img *mlx_img)
{
	ft_bzero(mlx_img, sizeof(t_mlx_img));
	if (w->mlx_img_id)
		mlx_clear_window(w->mlx, w->id);
	mlx_img->id = mlx_new_image(w->mlx, VIEWPORT_LENGTH, VIEWPORT_LENGTH);
	w->mlx_img_id = mlx_img->id;
	mlx_img->canvas = mlx_get_data_addr(mlx_img->id, &mlx_img->pixel_size, &mlx_img->line_size, &mlx_img->endian);
}

void	image_draw(t_window *w)
{
	t_mlx_img		mlx_img;
	t_pixel			pixel;
	t_complex		z;
	unsigned int 	color;

	image_init(w, &mlx_img);
	ft_bzero(&pixel, sizeof(t_pixel));
	z.i = w->complex_plane.minimum.i;
	z.r = w->complex_plane.minimum.r;
	while (pixel.y < VIEWPORT_LENGTH)
	{
		pixel.x = 0;
		z.r = w->complex_plane.minimum.r;
		while (pixel.x < VIEWPORT_LENGTH)
		{
			color = w->fractal_set->draw(&z, w);
			if (color)
				ft_memcpy(&mlx_img.canvas[pixel_to_addr(&pixel, &mlx_img)], &color, sizeof(int));
			pixel.x += 1;
			z.r += w->complex_plane.precision;
		}
		pixel.y += 1;
		z.i -= w->complex_plane.precision;
	}
	mlx_put_image_to_window(w->mlx, w->id, mlx_img.id, 0, 0);
	mlx_destroy_image(w->mlx, w->mlx_img_id);
}