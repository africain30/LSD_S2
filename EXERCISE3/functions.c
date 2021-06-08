#include "functions.h"


t_stack * new_stack(int x)
{
	t_stack * temp = (t_stack *)malloc(sizeof(t_stack));
	temp->data = x;
	temp ->next = NULL;
	return temp;
}

int is_empty(t_stack *head)
{
	if(head==NULL)
		return 1;
	return 0;
}

void push(t_stack ** head, int x)
{
	t_stack * temp = (t_stack *)malloc(sizeof(t_stack));
	(temp)->data = x;
	(temp)->next = *head;
	*head = temp;
}

int pop(t_stack **head)
{
	if(is_empty( *head))
		return INT_MIN;
	int x = (*head)->data;
	t_stack * temp = *head;
	(*head) = (*head)->next;
	free(temp);
	return x;
}


int stack_len(t_stack *head)
{
	if(is_empty(head))
		return 0;
	t_stack * temp;
	int j=0;
	while(temp!=NULL)
	{
		j++;
		temp=temp->next;
	}
	return j;
}

int peek_stack(t_stack *head)
{
	if(is_empty(head))
		return INT_MIN;
	return head->data;
}

void print_stack(t_stack *head)
{
	if(is_empty(head))
		return ;
	t_stack * temp = head;
	while(temp->next!=NULL)
	{
		printf("%d, ", temp->data);
        	temp=temp->next;
    	}
	if(temp!=NULL)
        	printf("%d\n", temp->data);
}
