/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 11:19:24 by thberrid          #+#    #+#             */
/*   Updated: 2021/03/29 11:19:25 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <keycodes.h>
# include <libft.h>
# include <mlx.h>

# define W_WIDTH	750
# define W_HEIGHT	750
# define W_NAME		"fractol"

typedef struct	s_img
{
	void	*id;
	char	*canvas;
	int		line_size;
	int		pixel_size;
	int		endian;
}				t_img;

typedef struct	s_window
{
	void			*id;
	void			*mlx;
	void			*img;
	char			name[32];
	unsigned int	width;
	unsigned int	height;
	unsigned int	zoom;
}				t_window;

#endif