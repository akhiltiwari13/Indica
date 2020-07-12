# include<stdio.h>

int main(void)
{
	int i=1234;
	int *p=&i;
	int j=*p; // * is the dereference operator as it dereferences a pointer to give it's value.

	printf("The address is: %p\n",&i);
	printf("The pointer points at  %p\n",p);
	printf("The value of the variable j after dereferencing is %d\n ",j);
	printf("After changing the value at the location pointed to by the pointer p is \n");
	*p=13;
	printf("The value of the variable i is  %d and that of the j is %d\n ",i, j);
	
	return 0;
}


