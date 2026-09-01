//指针
#include<stdio.h>
void get_max_min(int arr[], int len, int* max, int* min);
int main()
{
	int arr[] = { 2,5,1,7,3 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int max = arr[0];
	int min = arr[0];
	get_max_min(arr, len, &max, &min);
	printf("%d %d", max, min);
	return 0;
}

//定义判断最大值和最小值函数（指针可以返回多个值）
void get_max_min(int arr[], int len, int* max, int* min)
{
	*max = arr[0];
	for (int i = 1; i < len; i++)
	{
		if (*max < arr[i])
		{
			*max = arr[i];
		}
	}

	*min = arr[0];
	for (int i = 1; i < len; i++)
	{
		if (*min > arr[i])
		{
			*min = arr[i];
		}
	}
}