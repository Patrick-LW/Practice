//键盘录入5个数并存入数组
//1）遍历数组
//2）反转数组
//3）再次遍历
#include<stdio.h>
void printfarr(int arr[], int len);
int main()
{
	int arr[5] = { 0 };
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < len; i++)
	{
		printf("请输入第%d个数据:", i + 1);
		scanf("%d", &arr[i]);
	}
	//1.遍历数组
	printf("\n原数组为：");
	printfarr(arr, len);
	//2.反转数组
	int i = 0;
	int j = len - 1;
	while (i < j)
	{
		for (i = 0; i < len; i++)
		{
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	//3.再次遍历
	printf("\n反转后的数组为：");
	printfarr(arr, len);
	return 0;
}

void printfarr(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d", arr[i]);
		printf(" ");
	}
	return 0;
}