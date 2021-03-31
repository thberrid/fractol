/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 11:13:55 by thberrid          #+#    #+#             */
/*   Updated: 2021/03/29 11:14:24 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void    window_init(t_window *w)
{
	ft_bzero(w, sizeof(t_window));
	w->width = W_WIDTH;
	w->height = W_HEIGHT;
	ft_strcpy(w->name, W_NAME);
}

int 	xy_to_addr(int x, int y, t_img *imgdata)
{
	return (x * imgdata->pixel_size / 8 + y * imgdata->line_size);
}

void	draw(t_window *w)
{
	t_img	img;
	int i;
	int px;

	px = 255 << 8;
	ft_bzero(&img, sizeof(t_img));
	img.id = mlx_new_image(w->mlx, w->width, w->height);
	w->img = img.id;
	img.canvas = mlx_get_data_addr(img.id, &img.pixel_size, &img.line_size, &img.endian);
	i = 0;
	while (i < 750)
	{
		ft_memcpy(&img.canvas[xy_to_addr(i, i, &img)], &px, sizeof(int));
		i += 1;
	}
	ft_printf("line: %d\npixel: %d\nendian: %d\n", img.line_size, img.pixel_size, img.endian);
	mlx_put_image_to_window(w->mlx, w->id, img.id, 0, 0);
}

int 	quit(int key, t_window *w)
{
	(void)w;
	if (key == K_ESC || key == K_Q)
	{
		mlx_destroy_image(w->mlx, w->img);
		mlx_destroy_window(w->mlx, w->id);
		exit(0);
	} 
	ft_printf("KEY %d\n", key);
	return (0);
}

int 	mouse(int button, int x, int y, t_window *w)
{
	(void)w;
	ft_printf("button: %d\nx: %d\ny: %d\n", button, x, y);
	return (0);
}

int		main(void)
{
	t_window    w;

	window_init(&w);
	w.mlx = mlx_init();
	w.id = mlx_new_window(w.mlx, w.width, w.height, w.name);
	draw(&w);
	mlx_key_hook(w.id, &quit, &w);
	mlx_mouse_hook(w.id, &mouse, &w);
	mlx_loop(w.mlx);
	return (0);
}
