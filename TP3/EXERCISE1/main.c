#include "functions.h"
#include "functions.c"

int main(int ac , char ** av )
{
	printf("%d\n" , ac );
	printf("-------------\n");
	int i = 1;
	while(i<ac)
	{
		int j = 0;
		while(av[i][j] != '\0')
		{
			printf("%c\n" , av[i][j]);
			j++;
		}
		printf("-------------\n");
		i++;
	}
	liste b = NULL;
	b = tabliste(av[1]);
	affichageListe(b);
	int j = pallandrome(b );
	printf("%d\n" , j );
	return 0 ;
}
