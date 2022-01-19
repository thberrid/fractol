/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_generic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <thberrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:38:39 by thberrid          #+#    #+#             */
/*   Updated: 2021/04/21 14:38:42 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static t_pixel	*delta_from_key(t_pixel *translation, int key)
{
	t_pixel direction;

	direction.x = key == K_LEFT ? -1 : 1;
	direction.y = key == K_TOP ? 1 : -1;
	ft_bzero(translation, sizeof(t_pixel));
	if (key == K_LEFT || key == K_RIGHT)
		translation->x = VP_LENGTH / 15 * direction.x;
	if (key == K_TOP || key == K_BOTTOM)
		translation->y = VP_LENGTH / 15 * direction.y;
	return (translation);
}

static t_pixel	*delta_from_mouse
	(t_pixel *translation, t_pixel *mouse, int button)
{
	ft_bzero(translation, sizeof(t_pixel));
	if (button == ZOOM_IN)
	{
		translation->x = (mouse->x - VP_LENGTH / 2) / 2;
		translation->y = (VP_LENGTH / 2 - mouse->y) / 2;
	}
	return (translation);
}

int				mouse(int button, int x, int y, t_window *w)
{
	t_pixel		mouse;
	t_pixel		translation;

	if (button != ZOOM_IN && button != ZOOM_OUT)
		return (0);
	if ((w->zoom == 0 && button == ZOOM_OUT)
		|| (w->zoom == 50 && button == ZOOM_IN))
	{
		printf("no more zoom (zoom level = %d)\n", w->zoom);
		return (0);
	}
	if (w->state == LOCKED)
		return (0);
	w->state = LOCKED;
	mouse.x = x;
	mouse.y = y;
	w->zoom += button == ZOOM_IN ? 1 : -1;
	delta_from_mouse(&translation, &mouse, button);
	complex_plane_move(w, &translation);
	complex_plane_zoom(w, button);
	thread_set(w);
	thread_draw(w);
	return (0);
}

int				kboard(int key, t_window *w)
{
	t_pixel translation;

	if (key == K_SPACE)
	{
		complex_plane_reset(w);
		thread_set(w);
		if (thread_draw(w))
			force_quit(w);
	}
	else if (key == K_ESC || key == K_Q)
		force_quit(w);
	else if (key >= K_LEFT && key <= K_BOTTOM)
	{
		delta_from_key(&translation, key);
		complex_plane_move(w, &translation);
		thread_set(w);
		if (thread_draw(w))
			force_quit(w);
	}
	return (0);
}
