#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void fcfs(){
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
}
void lru(){
	int order[320], mem_volume[4] = { 100,100,100,100 };
	int l = 0, i = 0, j, cx;
	int num, temp = 0, ex_chan = 0, add = 0;
	float value = 0, sum = 0;
	srand(time(NULL));
	for (cx = 0; cx<10; cx++) {
		while (i<320) {
			order[i] = rand() % 320;
			if ((order[i] + 1) / 10 == mem_volume[0])
				;				//如果所调页数同第一个内存块中页数相同，则执行空操作
			else if ((order[i] + 1) / 10 == mem_volume[1]) {
				temp = mem_volume[1];
				mem_volume[1] = mem_volume[0];
				mem_volume[0] = temp;//如果所调页数同第二个内存块相同，则排序只需交换一次
			}
			else if ((order[i] + 1) / 10 == mem_volume[2]) {
				for (j = 2; j>0; j--) {
					temp = mem_volume[j];
					mem_volume[j] = mem_volume[j - 1];
					mem_volume[j - 1] = temp;
				}
			}
			else if ((order[i] + 1) / 10 == mem_volume[3]) {
				for (j = 3; j>0; j--) {
					temp = mem_volume[j];
					mem_volume[j] = mem_volume[j - 1];
					mem_volume[j - 1] = temp;
				}
			}			//如果所调页数同第3、4个内存块中页数相同，则通过循环进行排序
			else {
				l++;
				if (mem_volume[3] == 100)
					mem_volume[3] = (order[i] + 1) / 10;//保证刚开始调入内存块中就产生缺页
				else {
					mem_volume[3] = (order[i] + 1) / 10;
					for (num = 3; num>0; num--) {
						ex_chan = mem_volume[num];
						mem_volume[num] = mem_volume[num - 1];
						mem_volume[num - 1] = ex_chan;	//写人后重新排序
					}
				}
			}
			i++;
			order[i] = rand() % (order[i - 1] + 2);
			if (order[i] / 10 == mem_volume[0])
				;
			else if (order[i] / 10 == mem_volume[1]) {
				temp = mem_volume[1];
				mem_volume[1] = mem_volume[0];
				mem_volume[0] = temp;
			}

			else if (order[i] / 10 == mem_volume[2]) {
				for (j = 2; j>0; j--) {
					temp = mem_volume[j];
					mem_volume[j] = mem_volume[j - 1];
					mem_volume[j - 1] = temp;
				}
			}
			else if (order[i] / 10 == mem_volume[3]) {
				for (j = 3; j>0; j--) {
					temp = mem_volume[j];
					mem_volume[j] = mem_volume[j - 1];
					mem_volume[j - 1] = temp;
				}
			}
			else {
				l++;
				if (mem_volume[2] == 100)
					mem_volume[2] = order[i] / 10;
				else {
					mem_volume[3] = order[i] / 10;
					for (num = 3; num>0; num--) {
						ex_chan = mem_volume[num];
						mem_volume[num] = mem_volume[num - 1];
						mem_volume[num - 1] = ex_chan;
					}
				}
			}
			i++;
			order[i] = order[i - 1] + 1;
			if (order[i] / 10 == mem_volume[0])
				;
			else if (order[i] / 10 == mem_volume[1]) {
				temp = mem_volume[1];
				mem_volume[1] = mem_volume[0];
				mem_volume[0] = temp;
			}
			else if (order[i] / 10 == mem_volume[2]) {
				for (j = 2; j>0; j--) {
					temp = mem_volume[j];
					mem_volume[j] = mem_volume[j - 1];
					mem_volume[j - 1] = temp;
				}
			}
			else if (order[i] / 10 == mem_volume[3]) {
				for (j = 3; j>0; j--) {
					temp = mem_volume[j];
					mem_volume[j] = mem_volume[j - 1];
					mem_volume[j - 1] = temp;
				}
			}
			else {
				l++;
				if (mem_volume[1] == 100)
					mem_volume[1] = order[i] / 10;
				else {
					mem_volume[3] = order[i] / 10;
					for (num = 3; num>0; num--) {
						ex_chan = mem_volume[num];
						mem_volume[num] = mem_volume[num - 1];
						mem_volume[num - 1] = ex_chan;
					}
				}
			}
			i++;
			order[i] = rand() % (319 - order[i - 1] - 2) + (order[i - 1] + 2);
			if (order[i] / 10 == mem_volume[0])
				;
			else if (order[i] / 10 == mem_volume[1]) {
				temp = mem_volume[1];
				mem_volume[1] = mem_volume[0];
				mem_volume[0] = temp;
			}
			else if (order[i] / 10 == mem_volume[2]) {
				for (j = 2; j>0; j--) {
					temp = mem_volume[j];
					mem_volume[j] = mem_volume[j - 1];
					mem_volume[j - 1] = temp;
				}
			}
			else if (order[i] / 10 == mem_volume[3]) {
				for (j = 3; j>0; j--) {
					temp = mem_volume[j];
					mem_volume[j] = mem_volume[j - 1];
					mem_volume[j - 1] = temp;
				}
			}
			else {
				l++;
				if (mem_volume[0] == 100)
					mem_volume[0] = order[i] / 10;
				else {
					mem_volume[3] = order[i] / 10;
					for (num = 3; num>0; num--) {
						ex_chan = mem_volume[num];
						mem_volume[num] = mem_volume[num - 1];
						mem_volume[num - 1] = ex_chan;
					}
				}
			}
			i++;
		}
		value = l / 320.0 * 100;
		sum = sum + value;
		add = add + l;
	}
	printf("\2**************LRU页面置换算法******************\2\n");
	printf("*******************指令序列************************");
	for (i = 0; i<320; i++) {
		if (i % 10 == 0)
			printf("\n");
		printf("%5d", order[i]);
	}
	printf("\n");
	printf("*****************************************************\n");
	printf("\t\t十次的平均缺页数为%d\n\t\t十次的平均缺页率为%.3f%%", add / 10, sum / 10);
}
void lfu()
{
	int order[320], count[32] = { 0 }, compare[4] = { 0 }, mem_volume[4] = { 100,100,100,100 };
	//compare数组中存放了每次要比较的四个内存块中页数的调用次数
	int l = 0, i = 0, j, k = 0, cx = 0;
	int min, num = 0, n, sign = 0, add = 0;
	float value = 0, sum = 0;
	srand(time(NULL));
	for (cx = 0; cx < 10; cx++) {
		while (i < 320) {
			order[i] = rand() % 320;
			for (j = 0; j < 4; j++)
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
					for (num = 0; num < 4; num++) {
						k = mem_volume[num];
						compare[num] = count[k];
						if (compare[num] < min) {
							min = compare[num];
							j = num;		//通过比较确定最少使用的页数，
						}
					}
					mem_volume[j] = (order[i] + 1) / 10;
				}
			}
			i++;
			order[i] = rand() % (order[i - 1] + 2);
			for (j = 0; j < 4; j++)
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
					for (num = 0; num < 4; num++) {
						k = mem_volume[num];
						compare[num] = count[k];
						if (compare[num] < min) {
							min = compare[num];
							j = num;
						}
					}
					mem_volume[j] = (order[i] + 1) / 10;
				}
			}
			i++;
			order[i] = order[i - 1] + 1;
			for (j = 0; j < 4; j++)
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
					for (num = 0; num < 4; num++) {
						k = mem_volume[num];
						compare[num] = count[k];
						if (compare[num] < min) {
							min = compare[num];
							j = num;
						}
					}
					mem_volume[j] = (order[i] + 1) / 10;
				}
			}
			i++;
			order[i] = rand() % (319 - order[i - 1] - 2) + (order[i - 1] + 2);
			for (j = 0; j < 4; j++)
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
					for (num = 0; num < 4; num++) {
						k = mem_volume[num];
						compare[num] = count[k];
						if (compare[num] < min) {
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
	for (i = 0; i < 320; i++) {
		if (i % 10 == 0)
			printf("\n");
		printf("%5d", order[i]);
	}
	printf("\n");
	printf("*****************************************************\n");
	printf("\t十次的平均缺页数为%d\n\t十次的平均缺页率为%.3f%%", add / 10, sum / 10);
}

int main() {
	int n;
	while (printf("\n请选择算法：\nFCFS\t1\nLRU\t2\nLFU\t3\n") && (scanf("%d", &n) != EOF)) {
		switch (n) {
		case 1:fcfs(); break;
		case 2:lru(); break;
		case 3:lfu(); break;
		}
	}
	return 0;
}