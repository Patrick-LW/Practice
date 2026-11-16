//给出两个数取余数
#include<stdio.h>
int main()
{
	int a = 10;
	int b = 3;
	int res = 0;
	int flag = remender(a, b, &res);
	if (!flag)
	{
		printf("%d", res);
	}
	return 0;
}

//定义取余函数
int remender(int a, int b, int* res)
{
	if (b == 0)
	{
		return 1;
	}
	*res = a % b;
	return 0;
}