#include <stdlib.h>
#include <stdio.h>
#include "myMath.h"

int main()
{
	int a=0, b=0;

	printf("Enter first number : ");
	scanf("%d",&a);
	printf("Enter second number : ");
	scanf("%d",&b);

	if (isEqual(a, b)==1)
	{
		printf("Values are equal.\n");
	}
	else
	{
		printf("Values are not equal.\n");		
	}

	printf("Values before swaping : %d, %d \n", a, b);
	swap(&a, &b);
	printf("Values after swaping : %d, %d \n", a, b);

	return 0;
}
