#include "functions.h"




int main( int argc, char** argv )
{
	int i, temp, stacksize = 0;
	stack* head = NULL;

	if( argc == 1 )
	{
		printf("Usage: %s <arg> [arg] ... \n", argv[0]);
		exit(1);
	}

	for( i = 1; i < argc; i++ ) {
		char* token = argv[i];
		char* endptr;
		char op;

		if( checknr( token ) ) {
			/* We have a valid number. */
			temp = atoi( token );
			push( &head, temp );
			++stacksize;
		} else {
			/* We have an operand (hopefully) */
			if( strlen( token ) != 1 ) {
				fprintf( stderr, "Error: Token '%s' too large.\n", token );
				exit( 1 );
			}

			op = token[0];

			if( stacksize < need( op ) ) {
				fputs( "Too few arguments on stack.\n", stderr );
				exit( 1 );
			}

			push( &head, eval( op, &head ) );
			stacksize -= need( op ) - 1;
		}
	}

	if( stacksize != 1 ) {
		fputs( "Too many arguments on stack.\n", stderr );
		exit( 1 );
	}

	printf( "Result: %i\n", head->data );

	return 0;
}
