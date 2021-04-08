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
# include <stdio.h>

# define VIEWPORT_LENGTH		750
# define COMPLEXE_PLAN_LENGTH	5.0
# define W_NAME					"fractol"

# define FRACTAL_SETS_LEN		1

typedef struct s_complex
{
	long double r;
	long double i;
}				t_complex;

typedef struct s_pixel
{
	int 	x;
	int 	y;
}				t_pixel;

typedef struct	s_mlx_img
{
	void	*id;
	char	*canvas;
	int		line_size;
	int		pixel_size;
	int		endian;
}				t_mlx_img;

typedef struct	s_complex_plane
{
	t_complex	minimum;
	long double	precision;
	long double	length;
}				t_complex_plane;

typedef struct	s_window
{
	void			*id;
	void			*mlx;
	char			name[32];
	void			*mlx_img_id;
	struct s_fractal_set	*fractal_set;
	t_complex_plane	complex_plane;
}				t_window;

typedef struct 	s_fractal_set
{
	char *name;
	int (*draw)(t_complex *, t_window *);
	int (*mouse)(int, int, int, t_window *);
	int (*kboard)(int, t_window *);
}				t_fractal_set;

int				mandelbrot(t_complex *pixel, t_window *w);
int 			mandelmouse(int button, int x, int y, t_window *w);
int 			mandelkboard(int key, t_window *w);

int 		   	window_init(t_window *w, char *av1);

void			complex_plane_reset(t_window *w);
void			complex_plane_move(t_window *w, t_pixel *translation);
void			complex_plane_zoom(t_window *w, int key);

int 			pixel_to_addr(t_pixel *pixel, t_mlx_img *imgdata);

void			image_draw(t_window *w);

t_fractal_set	*get_fractal_set(char *name);
t_fractal_set 	*get_available_sets(void);

void 			print_usage(void);

#endif