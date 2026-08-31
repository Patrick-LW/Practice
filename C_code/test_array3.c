//插值查找
#include<stdio.h>

int main()
{
	int arr[] = { 11,22,33,44,66,100 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int num = 22;
	int index = search(arr, len, num);
	printf("%d", index);
	return 0;
}

int search(int arr[], int len, int num)
{
	int max = len - 1;
	int min = 0;
	while (min <= max)
	{
		int mid = min + (num - arr[min]) / (arr[max] - arr[min]) * (max - min);//计算mid的方式变了
		if (num < arr[mid])
		{
			max = mid - 1;
		}
		else if (num > arr[mid])
		{
			min = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}