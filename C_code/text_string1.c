#include<stdio.h>

int main(void)
{
	char str[100];
	scanf("%s", str);

	printf("接受到的字符串为：%s\n", str);

	//遍历
	char* p = str;
	while (*p != '\0')
	{
		printf("%c", *p);
		p++;
	}


	return 0;
}
