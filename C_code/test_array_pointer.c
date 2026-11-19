#include<stdio.h>
//利用指针遍历第一种定义形式的二维数组


int main(void)
{
	//定义二维数组
	int arr[3][5] =
	{
		{1,2,3,4,5},
		{11,22,33,44,55},
		{121,131,141,151,161}
	};

	int (*p)[5] = arr;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d ", *(*p + j));
		}
		printf("\n");
		p++;
	}

	return 0;
}