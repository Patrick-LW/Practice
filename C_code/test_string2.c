#include<stdio.h>
int main(void)
{
	//×Ö·û´®Êý×é
	char strarr[2][100] =
	{
		"abcde",
		"abc"
	};
	for (int i = 0; i < 2; i++)
	{
		char* str = strarr[i];
		printf("%s\n", str);
	}
	return 0;
}