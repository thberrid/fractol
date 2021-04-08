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

# define W_WIDTH		750
# define W_HEIGHT		750
# define PLAN_WIDTH		5
# define PLAN_HEIGHT	5
# define W_NAME			"fractol"

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

typedef struct	s_img
{
	void	*id;
	char	*canvas;
	int		line_size;
	int		pixel_size;
	int		endian;
}				t_img;

# define FRACTAL_SETS_LEN	1

enum 			e_fractalid
{
	mandelb,
	julia,
	future
};

typedef struct	s_window
{
	void			*id;
	void			*mlx;
	char			name[32];
	void			*img_id;
	enum e_fractalid 	fractal_setid;
	int				zoom;
	unsigned int	width;
	unsigned int	height;
	long double			precision;
	int				iterations;
	t_pixel 		delta_zero;
}				t_window;

typedef struct 	s_fractal_set
{
	char *name;
	int (*f)(t_pixel *, t_window *);
}				t_fractal_set;

int				mandelbrot(t_pixel *pixel, t_window *w);

int 		   	window_init(t_window *w, char *av1);
void			window_reset(t_window *w);
void			window_move(t_window *w, t_pixel *translation);
void			window_zoom(t_window *w, int key);
t_complex		*pixel_to_complex(t_complex *z, t_pixel *px, t_window *w);
int 			pixel_to_addr(t_pixel *pixel, t_img *imgdata);

void			image_draw(t_window *w);

int 			mouse(int button, int x, int y, t_window *w);
int 			keyboard(int key, t_window *w);

int 			get_fractal_id(char *name);
t_fractal_set 	*get_available_sets(void);

void 			print_usage(void);

#endif