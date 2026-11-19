#include<stdio.h>

int main(void)
{
	//第二种方法定义二维数组
	int arr1[3] = {1,2,3};
	int arr2[3] = {11,22,33};
	int* arr[2] = { arr1,arr2 };

	int** p = arr;
	
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", *(*p + j));
		}
		printf("\n");
		p++;
	}

	return 0;
}