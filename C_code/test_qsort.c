#include<stdio.h>
#include<stdlib.h>

//写比较函数
int cmp(const void* p1, const void* p2)
{
	int a = *(const int*)p1;
	int b = *(const int*)p2;
	return (a > b) - (a < b); //升序

}

//遍历
void answer(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}

}

int main(void)
{
	int arr[] = { 5,3,9,29,10,33 };
	int len = sizeof(arr) / sizeof(int);

	qsort(arr, len, sizeof(arr[0]), cmp);

	answer(arr, len);
	return 0;
}