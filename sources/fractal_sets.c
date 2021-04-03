/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_sets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:30:53 by user42            #+#    #+#             */
/*   Updated: 2021/04/03 16:31:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_fractal_set *get_available_sets(void)
{
    static t_fractal_set available_sets[FRACTAL_SETS_LEN + 1] = {
        {"mandelbrot", &mandelbrot},
        {NULL, NULL}
    };
    return (available_sets);
}

int get_fractal_id(char *name)
{
    int index;
    t_fractal_set *available_sets;

    available_sets = get_available_sets();
    index = 0;
    while (index < FRACTAL_SETS_LEN)
    {
        if (!ft_strcmp(name, available_sets[index].name))
            return (index);
        index += 1;
    }
    return (index);
}