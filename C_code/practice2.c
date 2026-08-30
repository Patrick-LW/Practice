#include<stdio.h>
int main()
{
	//质数练习
	//指定一个整数n，小于等于n的质数数量
	int n;
	scanf("%d", &n);
	int result = 0;
	//2.锁范围
	for (int j = 2; j <= n; j++)
	{
		//1.判定该数是否为质数
		int count = 0;
		for (int i = 2; i < j; i++)
		{
			if (j % i == 0)
			{
				count++;
				break;
			}
		}
		if (count == 0)
		{
			//3.统计
			result++;
		}
	}
	//输出结果
	printf("有%d个质数", result);
	return 0;
}