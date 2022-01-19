/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <thberrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 13:07:17 by thberrid          #+#    #+#             */
/*   Updated: 2021/04/21 13:07:20 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		print_init_error(void)
{
	ft_printf("MLX error\n");
	return (0);
}

int		print_thread_error(void)
{
	ft_printf("thread error\n");
	return (0);
}

int		print_usage(void)
{
	int				index;
	t_fractal_set	*available_sets;

	available_sets = get_available_sets();
	index = 0;
	ft_printf("\nusage: ./fractol \"set\"\n\nAvailable sets are :\n");
	while (index < FRACTAL_SETS_LEN)
	{
		ft_printf("\t- %s\n", available_sets[index].name);
		index += 1;
	}
	ft_printf("\nQ or ESC to quit\nMouse scroll to zoom\n\
	SPACE to reset the viewport\nArrow to move the viewport\n\n");
	return (0);
}
