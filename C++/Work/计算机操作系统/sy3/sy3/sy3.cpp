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
			order[i] = rand() % 320;  //�����������order��
			for (j = 0; j<4; j++)
				if ((order[i] + 1) / 10 == mem_volume[j])
					sign = 1;	//ͨ��sign��ʶ�ж�����ҳ���Ƿ����ڴ����

			if (sign)
				sign = 0;
			else {
				l++;
				if (mem_volume[3] == 100)
					mem_volume[3] = (order[i] + 1) / 10;// ��֤��һ�ε����ҳ�涼����ȱҳ
				else {
					mem_volume[num] = (order[i] + 1) / 10;  //����ȱҳ���뵽�ڴ����
					num = (num + 1) % 4;		 //numֵΪ�´���Ҫ�û���ȥ���ڴ���ж�Ӧ��ҳ��
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
	printf("\2***************FCFSҳ���û��㷨*******************\2\n");
	printf("*******************���һ��ָ������************************");
	for (i = 0; i<320; i++) {
		if (i % 10 == 0)
			printf("\n");
		printf("%5d", order[i]);
	}
	printf("\n");
	printf("*****************************************************\n");
	printf("\t\tʮ�ε�ƽ��ȱҳ��Ϊ%d\n\t\tʮ�ε�ƽ��ȱҳ��Ϊ%.3f%%", add / 10, sum / 10);
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
}
void lfu()
{
	int order[320], count[32] = { 0 }, compare[4] = { 0 }, mem_volume[4] = { 100,100,100,100 };
	//compare�����д����ÿ��Ҫ�Ƚϵ��ĸ��ڴ����ҳ���ĵ��ô���
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
					for (num = 0; num < 4; num++) {
						k = mem_volume[num];
						compare[num] = count[k];
						if (compare[num] < min) {
							min = compare[num];
							j = num;		//ͨ���Ƚ�ȷ������ʹ�õ�ҳ����
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
	printf("\2**************LFUҳ���û��㷨*********************\2\n");
	printf("*******************���һ��ָ������************************");
	for (i = 0; i < 320; i++) {
		if (i % 10 == 0)
			printf("\n");
		printf("%5d", order[i]);
	}
	printf("\n");
	printf("*****************************************************\n");
	printf("\tʮ�ε�ƽ��ȱҳ��Ϊ%d\n\tʮ�ε�ƽ��ȱҳ��Ϊ%.3f%%", add / 10, sum / 10);
}

int main() {
	int n;
	while (printf("\n��ѡ���㷨��\nFCFS\t1\nLRU\t2\nLFU\t3\n") && (scanf("%d", &n) != EOF)) {
		switch (n) {
		case 1:fcfs(); break;
		case 2:lru(); break;
		case 3:lfu(); break;
		}
	}
	return 0;
}