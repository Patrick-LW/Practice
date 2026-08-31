//二分查找
#include<stdio.h>
int bionarysearch(int arr[], int len, int num);
int main()
{
	int arr[] = { 11,33,55,77,100 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int num;
	scanf("%d", &num);
	int index = bionarysearch(arr, len, num);
	printf("%d", index);
	return 0;
}

int bionarysearch(int arr[], int len, int num)
{
	//定义最大值、最小值
	int min = 0;
	int max = len - 1;

	while (min <= max)
	{
		//中间值
		int mid = (max + min) / 2;//注：中间值要放在循环里，每次计算一次
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
	//若没有这个数
	return -1;
}