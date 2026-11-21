//定义加减乘除四个函数
//用户输入三个数字
//前两天表示参与计算的数字
//第三个数字表示要调用的函数
#include<stdio.h>

int sum(int a, int b)
{
	return a + b;
}

int minus(int a, int b)
{
	return a - b;
}

int multiply(int a, int b)
{
	return a * b;
}

int divide(int a, int b)
{
	return a / b;
}

int main(void)
{
	int num1, num2, choose;
	int (*arr[4])(int, int) = { sum,minus,multiply,divide };
	printf("请输入两个参与计算的数：");
	scanf("%d%d", &num1, &num2);
	printf("请输入要进行的计算（用数字表示）：");
	scanf("%d", &choose);
	//调用指针函数
	int res = (arr[choose - 1])(num1, num2);
	printf("%d", res);
	return 0;
}