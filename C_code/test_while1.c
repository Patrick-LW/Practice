#include<stdio.h>

int main()
{
	//给定一个整数，判断是否是二的幂次方
	int n;
	scanf("%d", &n);
	while (n != 1 && n % 2 ==0)
	{
		n = n / 2;
	}
	if (n == 1)
	{
		printf("yes");
	}
	else
	{
		printf("no");
	}
	return 0;
}