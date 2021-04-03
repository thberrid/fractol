/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:04:00 by user42            #+#    #+#             */
/*   Updated: 2021/04/03 16:04:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int    window_init(t_window *w, char *av1)
{
    w->fractal_setid = get_fractal_id(av1);
	if (w->fractal_setid >= FRACTAL_SETS_LEN)
		return (1);
	ft_bzero(w, sizeof(t_window));
	ft_strcpy(w->name, W_NAME);
	w->width = W_WIDTH;
	w->height = W_HEIGHT;
	w->precision = (float)PLAN_WIDTH / W_WIDTH;
	w->delta_zero.x = W_WIDTH / 2;
	w->delta_zero.y = W_HEIGHT / 2;
    return (0);
}

void	window_move(t_window *w, t_pixel *translation)
{
	w->delta_zero.x += translation->x;
	w->delta_zero.y += translation->y;
}

void	window_zoom(t_window *w, int key)
{
	int factor;

	factor = 2;
	if (key == SCROLL_UP)
	{
		w->precision *= factor;
		w->delta_zero.x *= factor;
		w->delta_zero.y *= factor;
	}
	else
	{
		w->precision /= factor;
		w->delta_zero.x /= factor;
		w->delta_zero.y /= factor;
	}
}