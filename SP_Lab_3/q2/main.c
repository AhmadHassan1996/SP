#include <stdlib.h>
#include <stdio.h>
#include "myStr.h"

int main()
{
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
