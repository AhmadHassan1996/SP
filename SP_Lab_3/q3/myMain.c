#include <stdlib.h>
#include <stdio.h>
#include "myMath.h"
#include "myStr.h"

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

	int size=5;
	char arr[5]={'m', 'a', 'd', 'a', 'm'};

	printf("Elements of array : \n");
	
	for (int i=0;i<size;i++)
	{
		printf("%c", arr[i]);
	}
	printf("\n");

	if (isPalindrome(arr, size)==1)
	{
		printf("The array is a palindrome.\n");
	}
	else
	{
		printf("The array is not a palindrome.\n");		
	}

	return 0;
}
