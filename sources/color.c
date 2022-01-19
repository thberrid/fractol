/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <thberrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:22:22 by thberrid          #+#    #+#             */
/*   Updated: 2021/04/21 12:22:23 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		int_to_color(int index)
{
	int		color;

	color = (index * 16) % 256 << 16;
	color += (index * 8) % 256 << 8;
	color += (index * 4) % 256;
	return (color);
}