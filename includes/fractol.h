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
# include <pthread.h>
# include <math.h>

# define LOCKED 1
# define OPEN	0

# define COMPLEXE_PLAN_LENGTH	5.0
# define W_NAME					"fractol"

# define FRACTAL_SETS_LEN		3

# define THREAD_MAX				4
# define VP_LENGTH		750
# define VP_DIVISION		2
# define VP_LENGTH_THREAD	375

typedef struct	s_complex
{
	long double r;
	long double i;
}				t_complex;

typedef struct	s_pixel
{
	int		x;
	int		y;
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
	double		precision;
	double		length;
}				t_complex_plane;

typedef struct	s_thread_data
{
	pthread_t		id;
	t_complex		minimum;
	t_pixel			pixel;
	struct s_window	*w;
}				t_thread_data;

typedef struct	s_window
{
	void					*id;
	void					*mlx;
	char					state;
	t_mlx_img				img;
	char					name[32];
	int						zoom;
	t_complex				mouse_over;
	t_complex_plane			complex_plane;
	t_thread_data			threads[THREAD_MAX];
	struct s_fractal_set	*fractal_set;
}				t_window;

typedef struct	s_fractal_set
{
	char	*name;
	int		(*draw)(t_complex *, t_window *);
	int		(*mouse)(int, int, int, t_window *);
	int		(*hover)(int, int, t_window *);
	int		(*kboard)(int, t_window *);
}				t_fractal_set;

int				mandelbrot(t_complex *pixel, t_window *w);
int				julia(t_complex *c, t_window *w);
int				ship(t_complex *c, t_window *w);
int				julia_mouse(int x, int y, t_window *w);
int				mouse(int button, int x, int y, t_window *w);
int				kboard(int key, t_window *w);
int				window_init(t_window *w, char *av1);
int				image_init(t_window *w);
void			complex_plane_reset(t_window *w);
void			complex_plane_move(t_window *w, t_pixel *translation);
void			complex_plane_zoom(t_window *w, int key);
int				pixel_to_addr(t_pixel *pixel, t_mlx_img *imgdata);
t_complex		*pixel_to_complex(t_complex *dst, t_pixel *src, t_window *w);
int				int_to_color(int index);
void			thread_set(t_window *w);
int				thread_draw(t_window *w);
void			*routine(void *data);
t_fractal_set	*get_fractal_set(char *name);
t_fractal_set	*get_available_sets(void);
int				print_usage(void);
int				print_init_error(void);
int				print_thread_error(void);
void			force_quit(t_window *w);

#endif
