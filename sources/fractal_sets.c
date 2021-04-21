/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_sets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:30:53 by user42            #+#    #+#             */
/*   Updated: 2021/04/03 16:31:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_fractal_set	*get_available_sets(void)
{
	static t_fractal_set available_sets[FRACTAL_SETS_LEN + 1] = {
		{"mandelbrot", &mandelbrot, &mouse, NULL, &kboard},
		{"julia", &julia, &mouse, &julia_mouse, &kboard},
		{"ship", &ship, &mouse, NULL, &kboard},
		{NULL, NULL, NULL, NULL, NULL}
	};

	return (available_sets);
}

t_fractal_set	*get_fractal_set(char *name)
{
	int				index;
	t_fractal_set	*available_sets;

	index = 0;
	available_sets = get_available_sets();
	while (index < FRACTAL_SETS_LEN)
	{
		if (!ft_strcmp(name, available_sets[index].name))
			return (&available_sets[index]);
		index += 1;
	}
	return (NULL);
}
