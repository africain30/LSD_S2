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
