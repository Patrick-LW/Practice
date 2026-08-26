//猜数字小游戏，范围是1~100，共有5次机会


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	srand(time(NULL));
	int answer = rand() % 100 + 1;
	int guess;
	int count = 5;
	while (1)
	{
		printf("你还有%d次机会，请输入你要猜的数：", count);
		scanf("%d", &guess);
		if (count == 1)
		{
			printf("你没有机会啦，答案是：%d\n", answer);
			break;
		}
		if (guess == answer)
		{
			printf("恭喜你猜对了！");
			break;
		}
		else if (guess < answer)
		{
			printf("不对哦，再猜猜看？(小了哦)\n");
			count--;
		}
		else if (guess > answer)
		{
			printf("不对哦，再猜猜看？(大了哦)\n");
			count--;
		}
	}

	return 0;
}