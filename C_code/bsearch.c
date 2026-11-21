#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a, const void* b)
{
	int np = *(const int*)a;
	int nq = *(const int*)b;
	return (np > nq) - (np < nq);
}

void printarr(int* p, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", p[i]);
	}
}

int main(void)
{
	int arr[5] = { 2,8,1,4,3 };
	qsort(arr, 5, sizeof(arr[0]), cmp);
	printarr(arr, 5);
	int search = 8;
	int *res = (int*)bsearch(&search, arr, 5, sizeof(arr[0]), cmp);
	//数字
	printf("查找到：%d ", *res);
	//位置
	printf("位置：%d", res - arr);
	return 0;
}