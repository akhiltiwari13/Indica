#include<stdio.h>

void print_string(const char * str)
{
	//printf("%s\n", str);
	//while(*str!=0) // for character pointer the the last element is NULL.
	while(*str)
		printf("%c\n",*(str++));

}


int main(){
	char arr[]= {'a', 'b','c', '\0'};
	// char strlit[] will have more compile time information as compared to the char *strlit 
	// size of operator for strlit[] will give the size of the string including the null character
	// size of *strlit will return the size of an character pointer  
	char strlit[]= "akhil";
	char *ptr=arr;
	printf("%s\n", strlit);
	//print the sizes
	printf("size from arr:%lu\n", sizeof(arr));
	printf("size from ptr:%lu\n", sizeof(ptr));
	printf("size from strlit:%lu\n", sizeof(strlit));
	int * test=(int *)112345656;
	printf("size of test%lu\n", sizeof(test));
	puts("");
	puts("arr");
	print_string(arr);
	puts("");
	puts("strlit");
	print_string(strlit);
	puts("");
	puts("ptr");
	print_string(ptr);
	return 0;
}
