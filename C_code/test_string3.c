#include<stdio.h>

void get(char *p)
{
	fgets(p, 100, stdin);
	for (int i = 0; p[i] != '\0'; i++)
	{
		if (p[i] == '\n')
		{
			p[i] = '\0';
			break;
		}
	}
}

void cat(char* p1, char* p2)
{
	int i = 0;
	int j = 0;
	while (p1[i] != '\0')
	{
		i++;
	}
	while (p2[j] != '\0')
	{
		p1[i] = p2[j];
		i++;
		j++;
	}
	//一定要加上'\0'
	p1[i] = '\0';
}

int main(void)
{
	char str1[100];
	char str2[100];
	get(str1);
	get(str2);
	cat(str1, str2);
	puts(str1);
}