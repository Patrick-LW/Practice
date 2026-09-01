//void类型函数
//进行数字交换（通用）
#include<stdio.h>
void  swap(void* a, void* b, int len);
int main()
{
	int a = 10;
	int b = 20;
	swap(&a, &b, 4);
	printf("%d %d", a, b);
	return 0;
}

void  swap(void* a, void* b, int len)
{
	char* p1 = a;
	char* p2 = b;
	char temp = 0;
	for (int i = 0; i < len; i++)
	{
		temp = *p1;
		*p1 = *p2;
		*p2 = temp;
		p1++;
		p2++;
	}
}