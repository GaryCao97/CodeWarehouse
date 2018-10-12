#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int order[320], count[32] = { 0 }, compare[4] = { 0 }, mem_volume[4] = { 100,100,100,100 };
	//compare数组中存放了每次要比较的四个内存块中页数的调用次数
	int l = 0, i = 0, j, k = 0, cx = 0;
	int min, num = 0, n, sign = 0, add = 0;
	float value = 0, sum = 0;
	srand(time(NULL));
	for (cx = 0; cx<10; cx++) {
		while (i<320) {
			order[i] = rand() % 320;
			for (j = 0; j<4; j++)
				if ((order[i] + 1) / 10 == mem_volume[j]) {
					n = (order[i] + 1) / 10;
					count[n] += 1;
					sign = 1;	//相同执行加1操作
				}
			if (sign)
				sign = 0;
			else {
				l++;
				if (mem_volume[3] == 100) {
					mem_volume[3] = (order[i] + 1) / 10;
					n = (order[i] + 1) / 10;
					count[n] += 1;
				}
				else {
					min = 1000;
					for (num = 0; num<4; num++) {
						k = mem_volume[num];
						compare[num] = count[k];
						if (compare[num]<min) {
							min = compare[num];
							j = num;		//通过比较确定最少使用的页数，
						}
					}
					mem_volume[j] = (order[i] + 1) / 10;
				}
			}
			i++;
			order[i] = rand() % (order[i - 1] + 2);
			for (j = 0; j<4; j++)
				if (order[i] / 10 == mem_volume[j]) {
					n = order[i] / 10;
					count[n] += 1;
					sign = 1;
				}
			if (sign)
				sign = 0;
			else {
				l++;
				if (mem_volume[2] == 100) {
					mem_volume[2] = (order[i] + 1) / 10;
					n = (order[i] + 1) / 10;
					count[n] += 1;
				}
				else {
					min = 1000;
					for (num = 0; num<4; num++) {
						k = mem_volume[num];
						compare[num] = count[k];
						if (compare[num]<min) {
							min = compare[num];
							j = num;
						}
					}
					mem_volume[j] = (order[i] + 1) / 10;
				}
			}
			i++;
			order[i] = order[i - 1] + 1;
			for (j = 0; j<4; j++)
				if (order[i] / 10 == mem_volume[j]) {
					n = order[i] / 10;
					count[n] += 1;
					sign = 1;
				}
			if (sign)
				sign = 0;
			else {
				l++;
				if (mem_volume[1] == 100) {
					mem_volume[1] = (order[i] + 1) / 10;
					n = (order[i] + 1) / 10;
					count[n] += 1;
				}
				else {
					min = 1000;
					for (num = 0; num<4; num++) {
						k = mem_volume[num];
						compare[num] = count[k];
						if (compare[num]<min) {
							min = compare[num];
							j = num;
						}
					}
					mem_volume[j] = (order[i] + 1) / 10;
				}
			}
			i++;
			order[i] = rand() % (319 - order[i - 1] - 2) + (order[i - 1] + 2);
			for (j = 0; j<4; j++)
				if (order[i] / 10 == mem_volume[0]) {
					n = order[i] / 10;
					count[n] += 1;
					sign = 1;
				}
			if (sign)
				sign = 0;
			else {
				l++;
				if (mem_volume[0] == 100) {
					mem_volume[0] = (order[i] + 1) / 10;
					n = (order[i] + 1) / 10;
					count[n] += 1;
				}
				else {
					min = 1000;
					for (num = 0; num<4; num++) {
						k = mem_volume[num];
						compare[num] = count[k];
						if (compare[num]<min) {
							min = compare[num];
							j = num;
						}
					}
					mem_volume[j] = (order[i] + 1) / 10;
				}
			}
			i++;
		}
		value = l / 320.0 * 100;
		add = add + l;
		sum = sum + value;
	}
	printf("\2**************LFU页面置换算法*********************\2\n");
	printf("*******************最后一次指令序列************************");
	for (i = 0; i<320; i++) {
		if (i % 10 == 0)
			printf("\n");
		printf("%5d", order[i]);
	}
	printf("\n");
	printf("*****************************************************\n");
	printf("\t十次的平均缺页数为%d\n\t十次的平均缺页率为%.3f%%", add / 10, sum / 10);
	return 0;
}
