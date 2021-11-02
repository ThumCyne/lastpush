/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbentouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:05:04 by sbentouy          #+#    #+#             */
/*   Updated: 2021/11/02 16:07:52 by sbentouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pushswap(int size, t_stack *a, t_stack *b)
{
	int		maxbits;
	int		i;
	int		j;

	maxbits = 0;
	while ((size) >> maxbits != 0)
		maxbits++;
	i = -1;
	while (++i < maxbits)
	{
		j = -1;
		while (++j < size)
		{
			if (((a->val >> i) & 1 ) == 1)
				a = rotate_ab(a, "ra\n");
			else
				ft_push_ab(&a, &b, "pb\n");
		}
		while (!(b_is_empty(b)))
			ft_push_ab(&b, &a, "pa\n");
	}
	free_all(a, b, NULL);
	b = NULL;
}

void	free_stack(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*ptr;

	if (a != NULL)
	{
		ptr = a;
		while (ptr->next != NULL)
		{
			tmp = ptr;
			ptr = ptr->next;
			free(tmp);
		}
		free(ptr);
	}
}

void	free_all(t_stack *a, t_stack *b, int *tab)
{
	if (tab != NULL)
		free(tab);
	if (a != NULL)
		free_stack(a);
	if (b != NULL)
		free_stack(b);
}
void check_and_sort(t_stack *a, t_stack	*b, int *tab, int size)
{
	if (size == 5)
	{
		a = sort5(a, tab, size);
		check_duplicate(a, 5);
		free_all(a, b, tab);
	}
	else
	{
		a = fill(a, tab, size - 1);
		check_duplicate(a, size);
		pushswap(size, a, b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		size;
	int		*tab;

	if (argc > 1)
	{
	a = NULL;
	b = NULL;
	size = valid_parse(argv);
	tab = malloc(sizeof(int) * size);
	tab = file_tab(tab, argv);
	if (tab_has_dup(tab, size))
	{
		free_all(a, b, tab);
		ft_putstr("Error\nduplicate arg\n");
		return (0);
	}
	tab = indexxx(tab, size, -2147483648, 2147483647);
	if (is_tab_sorted(tab, size))
	{
		free_all(a, b, tab);
		return (0);
	}
	if (size == 3)
	{
		a = sort3(tab, size);
		check_duplicate(a, 3);
		free_all(a, b, tab);
	}
	else
		check_and_sort(a, b, tab, size);
	}
	return (0);
}
