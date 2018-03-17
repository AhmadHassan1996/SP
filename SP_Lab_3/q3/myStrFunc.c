int isPalindrome(char * arr, int size)
{
	for (int i=0, j=size-1;i<size/2;i++, j--)
	{
		if (arr[i]!=arr[j])
		{
			return -1;
		}
	}
	return 1;
}
