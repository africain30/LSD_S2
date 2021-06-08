#include "functions.h"
#include "functions.c"

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
