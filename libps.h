/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:30:55 by sofia             #+#    #+#             */
/*   Updated: 2022/03/22 17:46:42 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPS_H
# define LIBPS_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct t_list
{
	int				content;
	struct t_list	*next;
	struct t_list	*prev;
}					t_stack;

int		push_swap(int argc, char **argv);
t_stack	*create_new_node(int content);
void	insert_at_head(t_stack **head, t_stack *new);
void	remove_node(t_stack **head, t_stack *node_to_remove);
void	clean_lst(t_stack **head_a);
int		is_it_ordered(t_stack *head);
int		is_it_num(char *arg);
int		error_msg(t_stack **head);
int		does_it_repeat(t_stack *head);
t_stack	*get_tail(t_stack *head);
void	ra_rb(t_stack **head, int a_or_b);
void	rra_rrb(t_stack **head, int a_or_b);
void	pa_pb(t_stack **head_a, t_stack**head_b, int a_or_b);
void	sa_sb(t_stack **head, int a_or_b);
void	rrr(t_stack **head_a, t_stack **head_b);
void	rr(t_stack **head_a, t_stack **head_b);
t_stack	*two_algs(t_stack *head);
t_stack	*three_als(t_stack *head);
t_stack	*big_alg(t_stack *head_a);
int		is_it_semi_ordered(t_stack *head);
t_stack	*find_the_biggest(t_stack *head);
int		lst_size(t_stack *head);
t_stack	*rotate_to_order(t_stack *head);
// APAGAR DEPOIS
void	printlist(t_stack *head, int color);
// ---
void	create_dif_lst(t_stack	**lst, t_stack *head, int val);
void	create_abs_lst(t_stack **lst_abs, t_stack *head);
int		find_the_place(t_stack *head, int val);
t_stack	*rotate_it(t_stack *head, int count);
void		find_the_smallest_aux(t_stack *lst_w_negs, int *i);
int		find_the_smalest(t_stack *lst, t_stack *lst_w_negs);
t_stack	*chose_what_to_do(t_stack *head_a, t_stack *head);
t_stack	*smallest_no(t_stack *head);
void	and_do_it(t_stack **head_a, t_stack **head_b, t_stack *node_to_put);
void	do_less(t_stack **head_a, t_stack **head_b, int a, int b);
void	rotate_it2(t_stack **head, int count, int a_or_b);

#endif

/*NOTAS
	- APAGAR STDIO.H N TE ESQUEÇAS
*/
