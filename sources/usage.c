/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:22:44 by user42            #+#    #+#             */
/*   Updated: 2021/04/03 16:22:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void print_usage(void)
{
    int index;
    t_fractal_set *available_sets;

    available_sets = get_available_sets();
    index = 0;
    ft_printf("\nusage: ./fractol \"set\"\n\nAvailable sets are :\n");
    while (index < FRACTAL_SETS_LEN)
    {
        ft_printf("\t- %s\n", available_sets[index].name);
        index += 1;
    }
    ft_putendl("");
}