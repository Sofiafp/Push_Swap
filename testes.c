#include <stdio.h>
#include "libps.h"

void	printlist1(t_stack *head)
{
	if (head)
	{
		while (head->next != NULL)
		{
			printf("%d - ", head->content);
			head = head->next;
		}
		if (head != NULL)
			printf("%d - ", head->content);
	}
	printf("\n ~~~~~~~~~~~~~~ \n");
}

int main() {

	t_stack		*head = NULL;

	t_stack		*um;
	um = create_new_node(1);

	t_stack		*dois;
	dois = create_new_node(2);
	t_stack		*quatro;
	quatro = create_new_node(4);
	t_stack		*cinco;
	cinco = create_new_node(6);

	insert_at_head(&head, um);
	insert_at_head(&head, dois);
	insert_at_head(&head, quatro);
	insert_at_head(&head, cinco);

	printlist1(head);
	
// remove_node(&head, head);

	printlist1(head);


	t_stack *tail = get_tail(head);

	printf("%d\n", head->content);
	printf("%d\n", head->next->content);
	printf("%d\n", head->next->next->content);
	printf("%d\n", head->next->next->content);
	printf("%d\n", head->next->next->prev->content);
	printf("%d\n", head->next->next->prev->prev->content);

	ra_rb(&head, 1);

	printf("%d\n", head->content);
	printf("%d\n", head->next->content);
	printf("%d\n", head->next->next->content);
	printf("%d\n", head->next->next->content);
	printf("%d\n", head->next->next->prev->content);
	printf("%d\n", head->next->next->prev->prev->content);

	ra_rb(&head, 0);

	printf("%d\n", head->content);
	printf("%d\n", head->next->content);
	printf("%d\n", head->next->next->content);
	printf("%d\n", head->next->next->content);
	printf("%d\n", head->next->next->prev->content);
	printf("%d\n", head->next->next->prev->prev->content);

	sa_sb(&head, 1);

	printf("%d\n", head->content);
	printf("%d\n", head->next->content);
	printf("%d\n", head->next->next->content);
	printf("%d\n", head->next->next->content);
	printf("%d\n", head->next->next->prev->content);
	printf("%d\n", head->next->next->prev->prev->content);

	sa_sb(&head, 0);

	printf("%d\n", head->content);
	printf("%d\n", head->next->content);
	printf("%d\n", head->next->next->content);
	printf("%d\n", head->next->next->content);
	printf("%d\n", head->next->next->prev->content);
	printf("%d\n", head->next->next->prev->prev->content);

	rra_rrb(&head, 0);

	printf("%d\n", head->content);
	printf("%d\n", head->next->content);
	printf("%d\n", head->next->next->content);
	printf("%d\n", head->next->next->content);
	printf("%d\n", head->next->next->prev->content);
	printf("%d\n", head->next->next->prev->prev->content);

	rra_rrb(&head, 1);

	printf("%d\n", head->content);
	printf("%d\n", head->next->content);
	printf("%d\n", head->next->next->content);
	printf("%d\n", head->next->next->content);
	printf("%d\n", head->next->next->prev->content);
	printf("%d\n", head->next->next->prev->prev->content);

	t_stack *head_b = NULL;

	pa_pb(&head,&head_b, 1);
	pa_pb(&head,&head_b, 1);
	printf("STACK A = %d\n", head->content);
	printf("STACK A = %d\n", head->next->content);
	printf("STACK A = %d\n", head->next->content);
	printf("STACK A = %d\n", head->next->prev->content);
//	printf("%d\n", head->next->next->prev->content);
	printf("STACK B = %d\n", head_b->content);
	printf("STACK B = %d\n", head_b->next->content);
	printf("STACK B = %d\n", head_b->next->content);
	printf("STACK B = %d\n", head_b->next->prev->content);


}