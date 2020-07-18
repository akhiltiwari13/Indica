#include<stdio.h>

int  main()
{
	char a='A';
	char *pa=&a; // a pointer needs to be initialized before using it other wise it gives a memory error.
	char **ppa=&pa; // a pointer to a pointer.
	char ***pppa=&ppa; // a pointer to (a pointer to a pointer).

	//printing the initial values of all the pointers.
	printf("a=%c\n", a);
	printf("pa=%p\n", pa);
	printf("ppa=%p\n", ppa);
	printf("pppa=%p\n", pppa);
	printf("&pppa=%p\n", &pppa);
	
	// dereferencing above pointers to manipulate with various values.
	printf("*pa=%c\n", *pa);
	printf("**ppa=%c\n", **ppa);
	printf("***pppa=%c\n", ***pppa);
	

	return 0;
}
