#include<stdio.h>

int  main()
{
	int a=66;
	
	int *p=&a; // a pointer needs to be initialized before using it other wise it gives a memory 'insert' error.
	// aparently not, using an uninitialized pointer did not give any error on printing the address it held by using the %p format specifier. gave a warning though.
	printf("*p=%d\n",*p);
	printf("a=%d\n", a);

	// using dereferencing a pointer to modify a value
	*p=13;
	printf("a=%d\n", a);
	printf("p=%p\n",p);
	printf("p+1=%p\n",p+1);
	printf("value @ the address p+1=%d\n",*(p+1));
	printf("&a=%p\n",&a);

int *z;
printf("z=%p",z);
printf("*z=%d",*z);
	return 0;
}
