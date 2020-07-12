#include<stdio.h>
#include<math.h>
//math.h header file needs to be dynamically linked to the program while building otherwise the compilation throws an undefined reference error.
//gcc -lm -o prog prog.c


void main()
{
	printf("enter a number:\n");
	int num;
	scanf("%d",&num);

	for(int trial=2; trial <=(int)sqrt((double)num); trial++){
		if(num%trial==0)
		{
			printf("not a prime number.\n");
			return 0;
		}
	}
	printf("%d is a prime number\n", num);
	return 0;
}
