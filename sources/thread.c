/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <thberrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 16:37:29 by thberrid          #+#    #+#             */
/*   Updated: 2021/04/10 16:37:41 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void		thread_set(t_window *w)
{
	int				index;
	int				division_y;
	int				division_x;
	t_thread_data	*this;
	t_complex_plane	*complex_plane;

	index = 0;
	complex_plane = &w->complex_plane;
	division_y = 0;
	while (division_y < THREAD_MAX / VIEWPORT_DIVISION)
	{
		division_x = 0;
		while (division_x < THREAD_MAX / VIEWPORT_DIVISION)
		{
			this = &w->threads[index];
			this->w = w;
			this->pixel.x = VIEWPORT_LENGTH_THREAD * (division_x % VIEWPORT_DIVISION);
			this->pixel.y = VIEWPORT_LENGTH_THREAD * (division_y % VIEWPORT_DIVISION);
			this->minimum.r = complex_plane->minimum.r + (complex_plane->length / VIEWPORT_DIVISION * (division_x % VIEWPORT_DIVISION));
			this->minimum.i = complex_plane->minimum.i - (complex_plane->length / VIEWPORT_DIVISION * (division_y % VIEWPORT_DIVISION));
			division_x += 1;
			index += 1;
		}
		division_y += 1;
	}
}

int		thread_draw(t_window *w)
{
	int index;

	index = 0;
	while (index < THREAD_MAX)
	{
		pthread_create(&w->threads[index].id, NULL, routine, &w->threads[index]);
		index += 1;
	}
	index = 0;
	while (index < THREAD_MAX)
	{
		pthread_join(w->threads[index].id, NULL);
		index += 1;
	}
	mlx_clear_window(w->mlx, w->id);
	mlx_put_image_to_window(w->mlx, w->id, w->img.id, 0, 0);
	return (0);
}

void	*routine(void *vdata)
{
	t_pixel			pixel;
	t_complex		z;
	unsigned int 	color;
	t_window		*w;
	t_thread_data	*data;
	t_pixel			maximum;

	data = (t_thread_data *)vdata;
	w = data->w;
	z.i = data->minimum.i;
	pixel.y = data->pixel.y;
	pixel.x = data->pixel.x;
	maximum.x = pixel.x + VIEWPORT_LENGTH_THREAD;
	maximum.y = pixel.y + VIEWPORT_LENGTH_THREAD;
	while (pixel.y < maximum.y)
	{
		pixel.x = data->pixel.x;
		z.r = data->minimum.r;
		while (pixel.x < maximum.x)
		{
		//	write(1, "OK\n", 3);
			color = w->fractal_set->draw(&z, w);
			ft_memcpy(&w->img.canvas[pixel_to_addr(&pixel, &w->img)], &color, sizeof(int));
			pixel.x += 1;
			z.r += w->complex_plane.precision;
		}
		pixel.y += 1;
		z.i -= w->complex_plane.precision;
	}
	return (data);
}