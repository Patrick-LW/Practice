#include<stdio.h>
int main()
{
	//打印乘方表(输入几打多少)
	int n;
	scanf("%d", &n);
	for (int j = 1; j <= n; j++)
	{
		for (int i = 1; i <= j; i++)
		{
			int a = j;
			for (int m = 1; m < i; m++)
			{
				a = a * j;
			}
			int result = a;
			printf("%d ^ %d = %d\t", j, i, result);
		}
		printf("\n");
	}
	return 0;
}