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
				;				//�������ҳ��ͬ��һ���ڴ����ҳ����ͬ����ִ�пղ���
			else if ((order[i] + 1) / 10 == mem_volume[1]) {
				temp = mem_volume[1];
				mem_volume[1] = mem_volume[0];
				mem_volume[0] = temp;//�������ҳ��ͬ�ڶ����ڴ����ͬ��������ֻ�轻��һ��
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
			}			//�������ҳ��ͬ��3��4���ڴ����ҳ����ͬ����ͨ��ѭ����������
			else {
				l++;
				if (mem_volume[3] == 100)
					mem_volume[3] = (order[i] + 1) / 10;//��֤�տ�ʼ�����ڴ���оͲ���ȱҳ
				else {
					mem_volume[3] = (order[i] + 1) / 10;
					for (num = 3; num>0; num--) {
						ex_chan = mem_volume[num];
						mem_volume[num] = mem_volume[num - 1];
						mem_volume[num - 1] = ex_chan;	//д�˺���������
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
	printf("\2**************LRUҳ���û��㷨******************\2\n");
	printf("*******************ָ������************************");
	for (i = 0; i<320; i++) {
		if (i % 10 == 0)
			printf("\n");
		printf("%5d", order[i]);
	}
	printf("\n");
	printf("*****************************************************\n");
	printf("\t\tʮ�ε�ƽ��ȱҳ��Ϊ%d\n\t\tʮ�ε�ƽ��ȱҳ��Ϊ%.3f%%", add / 10, sum / 10);
	return 0;
}
