/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbentouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:23:29 by sbentouy          #+#    #+#             */
/*   Updated: 2021/11/02 15:57:57 by sbentouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include<stdlib.h>
# include<unistd.h>
# include<ctype.h>
# include<stdio.h>

typedef struct s_stack
{
	int				val;
	struct s_stack	*next;
}	t_stack;

typedef struct s_op
{
	char		*oper;
	struct s_op	*next;
}	t_op;

void	pushswap(int size, t_stack *a, t_stack *b);
void	check_and_sort(t_stack *a, t_stack	*b, int *tab, int size);
int		*indexxx(int *t, int size, int min, int max);
int		valid_parse(char **str);
int		*file_tab(int *t, char **av);
t_stack	*sort3(int *tab, int size);
void	sort_5_init(t_stack **a, t_stack **b, int *tab);
t_stack	*sort5(t_stack *a, int *tab, int size);
int		in_range_int(char *str);
int		is_digit(char *str);
long	ft_atoi(char *str);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	check_duplicate(t_stack *a, int size);
int		is_max(t_stack *a);
int		is_min(t_stack *a);
int		is_sorted(t_stack *a);
void	free_all(t_stack *a, t_stack *b, int *tab);
int		b_is_empty(t_stack *b);
int		stack_size(t_stack *a);
int		check_pos(t_stack *a, int value);
int		last(t_stack *a);
t_stack	*fill(t_stack *a, int *tab, int size);
t_stack	*ft_push(t_stack *pile, int data);
t_stack	*rotate_ab(t_stack *p, char *str);
void	ft_push_ab(t_stack **a, t_stack **b, char *str);
t_stack	*reverse_rotate(t_stack *a, char *str);
int		*case1(int *tab);
int		*case2(int *tab);
int		*case3(int *tab);
int		*case4(int *tab);
int		*case5(int *tab);
int		is_tab_sorted(int *tab, int size);
int		tab_has_dup(int *tab, int size);


#endif
