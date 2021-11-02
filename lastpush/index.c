/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbentouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:06:12 by sbentouy          #+#    #+#             */
/*   Updated: 2021/11/02 16:06:31 by sbentouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pushswap.h"

int	*file_tab(int *t, char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		t[i - 1] = ft_atoi(av[i]);
		i++;
	}
	return (t);
}

int	valid_parse(char **str)
{
	int	i;

	i = 1;
	while (str[i] && is_digit(str[i]) && in_range_int(str[i]))
		i++;
	return (i - 1);
}

int	*indexxx(int *t, int size, int min, int max)
{
	int	*tab;
	int	i;
	int	j;
	int	s;

	i = -1;
	s = 0;
	tab = malloc(sizeof(int) * size);
	while (++i < size)
	{
		j = -1;
		max = 2147483647;
		while (++j < size)
		{
			if (t[j] < max && t[j] > min)
			{
				max = t[j];
				s = j;
			}
		}
		tab[s] = i;
		min = max;
	}
	free (t);
	return (tab);
}

