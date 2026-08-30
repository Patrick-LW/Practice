//打乱数组
//定义一个数组录入数字1~5，将顺序打乱
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int arr[] = { 1,2,3,4,5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	srand(time(NULL));
	for (int i = 0; i < len; i++)
	{
		int index = rand() % len;
		//与随机位置的数交换位置
		int temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}

	for (int i = 0; i < len; i++)
	{
		printf("%d\n", arr[i]);
	}

	return 0;
}