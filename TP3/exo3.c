# include <stdlib.h>
# include <stdio.h>
# include <limits.h>


struct	s_stack
{
	int			data;
	struct s_stack		*next;
};
typedef struct s_stack t_stack;


t_stack *new_stack(int data);
int is_empty(t_stack *head);
void push(t_stack **head, int data);
int pop(t_stack **head);
int stack_len(t_stack *head);
int peek_stack(t_stack *head);
void print_stack(t_stack *head);

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


int main()
{
	t_stack * t1 = new_stack(10);
	print_stack(t1);
	push(&t1,15);
	int x = stack_len(t1);
	int y = peek_stack(t1);
	printf("%d\n",x);
	printf("%d\n",y);
	print_stack(t1);
	int z = pop(&t1);
	print_stack(t1);
	int z1 = pop(&t1);
	int x1 = stack_len(t1);
	print_stack(t1);
	printf("%d\n",x1);
	return 0;
}
