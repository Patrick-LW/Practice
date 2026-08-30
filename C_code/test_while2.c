#include<stdio.h>
int main()
{
	//判断整数是否是回文数
	int num;
	scanf("%d", &num);
	int pri = num;//保存初始值
	int temp = 0;
	int result = 0;
	while (num != 0)
	{
		temp = num % 10;
		num = num / 10;
		result = result * 10 + temp;
	}
	if (result == pri)
	{
		printf("是回文数");
	}
	else
	{
		printf("不是回文数");
	}
	return 0;
}