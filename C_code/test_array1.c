//基本查找(顺序查找)
#include<stdio.h>
int order(int arr[], int len, int x);

int main()
{
	int arr[] = { 11,22,33,44,55 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int x;
	scanf("%d", &x);
	int num = order(arr, len, x);
	printf("%d", num);
	return 0;
}

int order(int arr[], int len,int x)
{
	for (int i = 0; i < len; i++)
	{
		if (arr[i] == x)
		{
			return i;
		}
	}
	return -1;
}