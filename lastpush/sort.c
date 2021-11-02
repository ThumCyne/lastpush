/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbentouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:08:58 by sbentouy          #+#    #+#             */
/*   Updated: 2021/11/02 13:13:01 by sbentouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	*case1(int *tab)
{
	int	tmp;

	ft_putstr("sa\n");
	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tmp;
	return (tab);
}

int	*case2(int *tab)
{
	int	tmp;

	ft_putstr("sa\nrra\n");
	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tmp;
	tmp = tab[2];
	tab[2] = tab[1];
	tab[1] = tab[0];
	tab[0] = tmp;
	return (tab);
}

int	*case3(int *tab)
{
	int	tmp;

	ft_putstr("ra\n");
	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tab[2];
	tab[2] = tmp;
	return (tab);
}

int	*case4(int *tab)
{
	int	tmp;

	ft_putstr("sa\nra\n");
	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tmp;
	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tab[2];
	tab[2] = tmp;
	return (tab);
}
