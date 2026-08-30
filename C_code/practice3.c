#include<stdio.h>
int main()
{
//幂次方练习，算1^1+2^2+3^3+4^4……+10^10=?
	long long alresult = 0;
	for (int i = 1; i <= 10; i++)
	{
		long long result = 1;
		for (int j = 1; j <= i; j++)
		{
			result = result * i;
		}
		alresult = alresult + result;
	}
	printf("结果是%lld", alresult);
	return 0;
}