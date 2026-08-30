//练习：
//生成1~100随机数（不可重复）
//求和，求平均数，统计有多少个数据比平均数小

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int contains(int arr[], int len, int num);

int main()
{
	int arr[10] = { 0 };			//数组初始化
	int len = sizeof(arr) / sizeof(arr[0]);
	int sum = 0;
	double aver;					//平均数用double
	int count = 0;
	srand(time(NULL));
	for (int i = 0; i < len; )
	{
		int num = rand() % 100 + 1;	//不着急赋值给数组
		int flag = contains(arr, len, num);
		if (!flag)
		{
			arr[i] = num;
			printf("%d\n", arr[i]);
			i++;
		}
	}

	//加法
	for (int i = 0; i < len; i++)
	{
		sum = sum + arr[i];
	}
	//平均数
	aver = (double)sum / len;
	//统计有多少个数据比平均数小
	for (int i = 0; i < len; i++)
	{
		if ((double)arr[i] < aver)
		{
			count++;
		}
	}
	printf("和为：%d\n平均数为：%.1lf\n数据比平均数小的有%d个\n", sum, aver, count);
	return 0;
}

//练习三定义方程（判断是否随机数重复）
//是：1
//否：0
int contains(int arr[], int len, int num)
{
	for (int i = 0; i < len; i++)
	{
		if (arr[i] == num)
		{
			return 1;
		}
	}
	return 0;
}