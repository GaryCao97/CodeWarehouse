#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int order[320], count[32] = { 0 }, compare[4] = { 0 }, mem_volume[4] = { 100,100,100,100 };
	//compare�����д����ÿ��Ҫ�Ƚϵ��ĸ��ڴ����ҳ���ĵ��ô���
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
					sign = 1;	//��ִͬ�м�1����
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
							j = num;		//ͨ���Ƚ�ȷ������ʹ�õ�ҳ����
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
	printf("\2**************LFUҳ���û��㷨*********************\2\n");
	printf("*******************���һ��ָ������************************");
	for (i = 0; i<320; i++) {
		if (i % 10 == 0)
			printf("\n");
		printf("%5d", order[i]);
	}
	printf("\n");
	printf("*****************************************************\n");
	printf("\tʮ�ε�ƽ��ȱҳ��Ϊ%d\n\tʮ�ε�ƽ��ȱҳ��Ϊ%.3f%%", add / 10, sum / 10);
	return 0;
}
