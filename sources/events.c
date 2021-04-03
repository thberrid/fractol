/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:02:02 by user42            #+#    #+#             */
/*   Updated: 2021/04/03 16:02:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_pixel *delta_from_key(t_pixel *translation, int key)
{
	t_pixel direction;

	direction.x = key == K_LEFT ? 1 : -1;
	direction.y = key == K_TOP ? 1 : -1;
	translation->x = W_WIDTH / 15 * direction.x;
	translation->y = W_HEIGHT / 15 * direction.y;
	return (translation);
}	

t_pixel	*delta_from_mouse(t_pixel *translation, t_pixel *mouse, int button)
{
	if (button)
		translation->x += mouse->x;
	return (translation);
}

int 	mouse(int button, int x, int y, t_window *w)
{
	t_pixel		mouse;
	t_pixel		translation;

	if (button == SCROLL_UP || button == SCROLL_DOWN)
	{
		mouse.x = x;
		mouse.y = y;
		delta_from_mouse(&translation, &mouse, button);
		window_move(w, &translation);
		window_zoom(w, button);
		image_draw(w);
	}
	return (0);
}

int 	keyboard(int key, t_window *w)
{
	t_pixel translation;

	if (key == K_ESC || key == K_Q)
	{
		mlx_destroy_image(w->mlx, w->img_id);
		mlx_destroy_window(w->mlx, w->id);
		exit(0);
	}
	if (key >= K_LEFT && key <= K_BOTTOM)
	{
		delta_from_key(&translation, key);
		window_move(w, &translation);
		image_draw(w);
	}
	return (0);
}