#include "functions.h"


void push( stack **head, int value )
{
	stack* node = malloc( sizeof(stack) );

	if( node == NULL ) {
		fputs( "Error: Out of memory\n", stderr );
		exit( 1 );
	} else {
		node->data = value;
		node->next = *head;
		*head = node;
	}
}

int pop( stack **head )
{
	if( *head == NULL ) {
		fputs( "Error: bottom of stack!\n", stderr );
		exit( 1 );
	} else {
		stack* top = *head;
		int value = top->data;
		*head = top->next;
		free( top );
		return value;
	}
}

int eval( char op, stack** head )
{
	int temp;
	switch( op ) {
		case '+': return pop(head) + pop(head);
		case '*': return pop(head) * pop(head);
		case '-': temp = pop(head); return pop(head) - temp;
		case '/': temp = pop(head); return pop(head) / temp;
	}
}

int need( char op )
{
	switch( op ) {
		case '+':
		case '*':
		case '-':
		case '/':
			return 2;
		default:
			fputs( "Invalid operand!", stderr );
			exit( 1 );
	}
}

int checknr( char* number )
{
	for( ; *number; number++ )
		if( *number < '0' || *number > '9' )
			return 0;

	return 1;
}
