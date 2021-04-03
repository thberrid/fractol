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

void	image_init(t_window *w, t_img *img)
{
	if (w->img_id)
	{
		mlx_clear_window(w->mlx, w->id);
		mlx_destroy_image(w->mlx, w->img_id);
	}
	img->id = mlx_new_image(w->mlx, w->width, w->height);
	w->img_id = img->id;
	img->canvas = mlx_get_data_addr(img->id, &img->pixel_size, &img->line_size, &img->endian);
}

void	image_draw(t_window *w)
{
	t_img	img;
	t_pixel	pixel;
	t_fractal_set *fractal_set;
	int color;

    fractal_set = get_available_sets();
	image_init(w, &img);
	pixel.y = 0;
	while (pixel.y < W_HEIGHT)
	{
		pixel.x = 0;
		while (pixel.x < W_WIDTH)
		{
			color = fractal_set[w->fractal_setid].f(&pixel, w);
			if (color)
				ft_memcpy(&img.canvas[pixel_to_addr(&pixel, &img)], &color, sizeof(int));
			pixel.x += 1;
		}
		pixel.y += 1;
	}
	mlx_put_image_to_window(w->mlx, w->id, img.id, 0, 0);
}