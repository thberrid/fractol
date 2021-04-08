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

	direction.x = key == K_LEFT ? -1 : 1;
	direction.y = key == K_TOP ? 1 : -1;
	ft_bzero(translation, sizeof(t_pixel));
	if (key == K_LEFT ||  key == K_RIGHT)
		translation->x = VIEWPORT_LENGTH / 15 * direction.x;
	if (key == K_TOP ||  key == K_BOTTOM)
		translation->y = VIEWPORT_LENGTH / 15 * direction.y;
	return (translation);
}	

t_pixel	*delta_from_mouse(t_pixel *translation, t_pixel *mouse, t_window *w, int button)
{
	(void)button;
	(void)mouse;
	(void)w;
	translation->x = 0;
	translation->y = 0;
	return (translation);
}

int 	mandelmouse(int button, int x, int y, t_window *w)
{
	// update precision
	// update minimum
	// update length

//	t_pixel		mouse;
//	t_pixel		translation;
//	t_complex	z;

//	mouse.x = x;
//	mouse.y = y;
//	pixel_to_complex(&z, &mouse, w);
//	if (button == CLICK_LEFT)
//		printf("x: %d y: %d\nr: %f\ni: %f\n", x, y, z.r, z.i);
	(void)x;
	(void)y;
	if (button == ZOOM_IN || button == ZOOM_OUT)
	{
//		delta_from_mouse(&translation, &mouse, w, button);
//		complex_plane_move(w, &translation);
		complex_plane_zoom(w, button);
		image_draw(w);
	}
	return (0);
}

int 	mandelkboard(int key, t_window *w)
{
	t_pixel translation;

	if (key == K_SPACE)
	{
		complex_plane_reset(w);
		image_draw(w);
	}
	else if (key == K_ESC || key == K_Q)
	{
		mlx_destroy_window(w->mlx, w->id);
		exit(0);
	}
	else if (key >= K_LEFT && key <= K_BOTTOM)
	{
		delta_from_key(&translation, key);
		complex_plane_move(w, &translation);
		image_draw(w);
	}
	return (0);
}