/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <thberrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:36:19 by thberrid          #+#    #+#             */
/*   Updated: 2021/04/21 14:36:30 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void		force_quit(t_window *w)
{
	mlx_destroy_image(w->mlx, w->img.id);
	mlx_destroy_window(w->mlx, w->id);
	exit(0);
}
