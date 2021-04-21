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

static void	thread_set_this(t_window *w, t_thread_data *this, int x, int y)
{
	this->w = w;
	this->pixel.x = VP_LENGTH_THREAD * (x % VP_DIVISION);
	this->pixel.y = VP_LENGTH_THREAD * (y % VP_DIVISION);
	this->minimum.r = w->complex_plane.minimum.r
		+ (this->pixel.x * w->complex_plane.precision);
	this->minimum.i = w->complex_plane.minimum.i
		- (this->pixel.y * w->complex_plane.precision);
}

void		thread_set(t_window *w)
{
	int				index;
	int				division_y;
	int				division_x;
	t_thread_data	*this;

	index = 0;
	division_y = 0;
	while (division_y < THREAD_MAX / VP_DIVISION)
	{
		division_x = 0;
		while (division_x < THREAD_MAX / VP_DIVISION)
		{
			this = &w->threads[index];
			thread_set_this(w, this, division_x, division_y);
			division_x += 1;
			index += 1;
		}
		division_y += 1;
	}
}

int			thread_draw(t_window *w)
{
	int index;

	index = 0;
	while (index < THREAD_MAX)
	{
		if (pthread_create(&w->threads[index].id, NULL,
			routine, &w->threads[index]))
			return (1);
		index += 1;
	}
	index = 0;
	while (index < THREAD_MAX)
	{
		pthread_join(w->threads[index].id, NULL);
		index += 1;
	}
	mlx_put_image_to_window(w->mlx, w->id, w->img.id, 0, 0);
	w->state = OPEN;
	return (0);
}

static void	foreach_pixel
	(t_pixel *minimum, t_pixel *maximum, t_complex *z_start, t_window *w)
{
	t_pixel			pixel;
	t_complex		z;
	unsigned int	color;

	z.i = z_start->i;
	pixel.y = minimum->y;
	while (pixel.y < maximum->y)
	{
		pixel.x = minimum->x;
		z.r = z_start->r;
		while (pixel.x < maximum->x)
		{
			color = w->fractal_set->draw(&z, w);
			ft_memcpy(&w->img.canvas[pixel_to_addr(&pixel, &w->img)],
				&color, sizeof(int));
			pixel.x += 1;
			z.r += w->complex_plane.precision;
		}
		pixel.y += 1;
		z.i -= w->complex_plane.precision;
	}
}

void		*routine(void *void_data)
{
	t_pixel			minimum;
	t_pixel			maximum;
	t_window		*w;
	t_thread_data	*data;

	data = (t_thread_data *)void_data;
	w = data->w;
	minimum.y = data->pixel.y;
	minimum.x = data->pixel.x;
	maximum.x = minimum.x + VP_LENGTH_THREAD;
	maximum.y = minimum.y + VP_LENGTH_THREAD;
	foreach_pixel(&minimum, &maximum, &data->minimum, w);
	return (data);
}
