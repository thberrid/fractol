/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <thberrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 11:40:11 by thberrid          #+#    #+#             */
/*   Updated: 2021/04/08 11:40:15 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	complex_plane_reset(t_window *w)
{
	w->zoom = 0;
	w->complex_plane.length = COMPLEXE_PLAN_LENGTH;
	w->complex_plane.precision = w->complex_plane.length / VIEWPORT_LENGTH;
	w->complex_plane.minimum.r = COMPLEXE_PLAN_LENGTH / 2.0 * -1;
	w->complex_plane.minimum.i = COMPLEXE_PLAN_LENGTH / 2.0;
}

void	complex_plane_move(t_window *w, t_pixel *translation)
{
	w->complex_plane.minimum.r += (translation->x * w->complex_plane.precision);
	w->complex_plane.minimum.i += (translation->y * w->complex_plane.precision);
}

void	complex_plane_zoom(t_window *w, int key)
{
	long double	factor;
	long double n_len;
	int			direction;

	factor = key == ZOOM_IN ? 1.0 / 2 : 2;
	direction = key == ZOOM_IN ? 1 : -1;
	w->complex_plane.length *= factor;
	w->complex_plane.precision = w->complex_plane.length / VIEWPORT_LENGTH;
	n_len = key == ZOOM_IN ? w->complex_plane.length : w->complex_plane.length / 2;
	w->complex_plane.minimum.r += (n_len / 2) * direction;
	w->complex_plane.minimum.i -= (n_len / 2) * direction;
}