// dereferencing a void pointer will give us an error because the computer would not know how to read the data @ the specified address.
#include<stdio.h>

int  main()
{
	int a=1025;
	char ac='a';

	int *pa=&a; // a pointer needs to be initialized before using it other wise it may give a memory error.
	char *pac=&ac;

	//printing the initial values of all the pointers.
	printf("a=%d\n", a);
	printf("ac=%c\n", ac);

	printf("pa=%p\n", pa);
	printf("pac=%p\n", pac);
	
	//declare a new character pointer
	char* npac=(char *)pa; // assign it by typecasting the integer pointer.

	// print the new pointer.
	printf("npac=%p\n", npac);
	
	
	printf("*pa=%d\n", *pa); //dereferencing pa.
	printf("*npac=%d\n", *npac); //dereferencing npac.
	printf("*(npac+1)=%d\n", *(npac+1)); //dereferencing npac+1.

	// introducing void pointer; that can hold any memory address.
       
	float *vp;
	vp=(float *)pa;
	printf("float pointer vp+3=%p\n",(vp+3));

	return 0;
}
