#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct stack
{
	int data;
	struct stack *next;
} stack;


void push( stack **, int  );
int pop( stack ** );
int eval( char , stack** );
int need( char  );
int checknr( char*  );
