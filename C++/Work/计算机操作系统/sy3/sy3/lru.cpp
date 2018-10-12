#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
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
	return 0;
}
