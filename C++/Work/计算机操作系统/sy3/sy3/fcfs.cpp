#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int order[320], mem_volume[4] = { 100,100,100,100 };
	int l = 0, i = 0, j, num = 0, cx, sign = 0, add = 0;
	float value = 0, sum = 0;
	srand(time(NULL));
	for (cx = 0; cx<10; cx++) {
		while (i<320) {
			order[i] = rand() % 320;  //产生随机数放order中
			for (j = 0; j<4; j++)
				if ((order[i] + 1) / 10 == mem_volume[j])
					sign = 1;	//通过sign标识判断所调页数是否在内存块中

			if (sign)
				sign = 0;
			else {
				l++;
				if (mem_volume[3] == 100)
					mem_volume[3] = (order[i] + 1) / 10;// 保证第一次调入的页面都产生缺页
				else {
					mem_volume[num] = (order[i] + 1) / 10;  //将所缺页调入到内存块中
					num = (num + 1) % 4;		 //num值为下次所要置换出去的内存块中对应的页数
				}
			}
			i++;
			order[i] = rand() % (order[i - 1] + 2);
			for (j = 0; j<4; j++)
				if (order[i] / 10 == mem_volume[j])
					sign = 1;
			if (sign)
				sign = 0;
			else {
				l++;
				if (mem_volume[2] == 100)
					mem_volume[2] = order[i] / 10;
				else {
					mem_volume[num] = order[i] / 10;
					num = (num + 1) % 4;
				}
			}
			i++;
			order[i] = order[i - 1] + 1;
			for (j = 0; j<4; j++)
				if (order[i] / 10 == mem_volume[j])
					sign = 1;
			if (sign)
				sign = 0;
			else {
				l++;
				if (mem_volume[1] == 100)
					mem_volume[1] = order[i] / 10;
				else {
					mem_volume[num] = order[i] / 10;
					num = (num + 1) % 4;
				}
			}
			i++;
			order[i] = rand() % (319 - order[i - 1] - 2) + (order[i - 1] + 2);
			for (j = 0; j<4; j++)
				if (order[i] / 10 == mem_volume[0])
					sign = 1;
			if (sign)
				sign = 0;
			else {
				l++;
				if (mem_volume[0] == 100)
					mem_volume[0] = (order[i] + 1) / 10;
				else {
					mem_volume[num] = order[i] / 10;
					num = (num + 1) % 4;
				}
			}
			i++;
		}
		value = l / 320.0 * 100;
		add = add + l;
		sum = sum + value;
	}
	printf("\2***************FCFS页面置换算法*******************\2\n");
	printf("*******************最后一次指令序列************************");
	for (i = 0; i<320; i++) {
		if (i % 10 == 0)
			printf("\n");
		printf("%5d", order[i]);
	}
	printf("\n");
	printf("*****************************************************\n");
	printf("\t\t十次的平均缺页数为%d\n\t\t十次的平均缺页率为%.3f%%", add / 10, sum / 10);
	return 0;
}
