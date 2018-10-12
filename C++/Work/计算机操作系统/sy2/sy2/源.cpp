#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef struct {
	int num;
	int priority;
	int enterTime, runTime, startTime, endTime;
	int running;
}Progress;
typedef struct {
	Progress *Pro;
	int len;
}Progresses;
void FCFS(Progresses progresses);//�����ȷ���
void PSA_NM(Progresses progresses);//����ռʽ���ȼ�����
void PSA_PM(Progresses progresses);//��ռʽ���ȼ�����
void InputProgressInfo(Progresses &progresses);//������Ϣ����
void OutputProgressInfo(Progresses progresses);//������Ϣ���

int CompByEnterTime(Progress Pro1, Progress Pro2) {
	return Pro1.enterTime < Pro2.enterTime;//����
}
int CompByStartTime(Progress Pro1, Progress Pro2) {
	return Pro1.startTime < Pro2.startTime;//����
}
int CompByPriority(Progress Pro1, Progress Pro2) {
	return Pro1.priority > Pro2.priority;//����
}
int GetOrder(Progresses p, Progress q) {
	for (int i = 0; i < p.len; i++) {
		if (p.Pro[i].num == q.num && p.Pro[i].enterTime == q.enterTime && p.Pro[i].runTime == q.runTime&& p.Pro[i].priority == q.priority)
			return i;
	}
	return -1;
}
void FCFS(Progresses progresses) {
	sort(progresses.Pro, progresses.Pro + progresses.len, CompByEnterTime);
	for (int i = 0; i < progresses.len; i++) {
		progresses.Pro[i].startTime = progresses.Pro[i].endTime = progresses.Pro[i].running = 0;
	}
	int n = progresses.len;
	progresses.Pro[0].startTime = progresses.Pro[0].enterTime;
	progresses.Pro[0].endTime = progresses.Pro[0].startTime+ progresses.Pro[0].runTime;
	for (int i = 1; i < n; i++) {
		if (progresses.Pro[i].enterTime > progresses.Pro[i - 1].endTime) {
			progresses.Pro[i].startTime = progresses.Pro[i].enterTime;
			progresses.Pro[i].endTime = progresses.Pro[i].startTime + progresses.Pro[i].runTime;
		}
		else {
			progresses.Pro[i].startTime = progresses.Pro[i - 1].endTime;
			progresses.Pro[i].endTime = progresses.Pro[i].startTime + progresses.Pro[i].runTime;
		}
	}
	sort(progresses.Pro, progresses.Pro + progresses.len, CompByStartTime);
	cout << "---------------------�����ȷ������-----------------------" << endl;
	OutputProgressInfo(progresses);
	cout << "---------------------�����ȷ������-----------------------" << endl;
}
void PSA_NM(Progresses progresses) {
	sort(progresses.Pro, progresses.Pro + progresses.len, CompByEnterTime);
	for (int i = 0; i < progresses.len; i++) {
		progresses.Pro[i].startTime = progresses.Pro[i].endTime = progresses.Pro[i].running = 0;
	}
	Progresses readyPro;
	readyPro.len = 1;
	readyPro.Pro = (Progress*)malloc(sizeof(Progress));
	*(readyPro.Pro) = progresses.Pro[0];
	int t = 0, endTime = progresses.Pro[progresses.len - 1].enterTime, orderP = 1, orderQ = 0;
	while (t <= endTime || readyPro.len) {
		while (t == progresses.Pro[orderP].enterTime) {
			readyPro.Pro = (Progress*)realloc(readyPro.Pro, (readyPro.len + 1) * sizeof(Progress));
			readyPro.Pro[readyPro.len++] = progresses.Pro[orderP++];
		}
		sort(readyPro.Pro, readyPro.Pro + readyPro.len, CompByPriority);
		if (t >= readyPro.Pro[0].enterTime && t >= progresses.Pro[orderQ].endTime) {
			orderQ = GetOrder(progresses, readyPro.Pro[0]);
			progresses.Pro[orderQ].startTime = t;
			progresses.Pro[orderQ].endTime = progresses.Pro[orderQ].startTime + progresses.Pro[orderQ].runTime;
			for (int i = 1; i < readyPro.len; i++)
				readyPro.Pro[i - 1] = readyPro.Pro[i];
			readyPro.Pro = (Progress*)realloc(readyPro.Pro, (readyPro.len - 1) * sizeof(Progress));
			readyPro.len--;
		}
		t++;
	}
	sort(progresses.Pro, progresses.Pro + progresses.len, CompByStartTime);
	cout << "-----------------���ȼ����ȣ�����ռʽ��-------------------" << endl;
	OutputProgressInfo(progresses);
	cout << "-----------------���ȼ����ȣ�����ռʽ��-------------------" << endl;
}
void PSA_PM(Progresses progresses) {
	sort(progresses.Pro, progresses.Pro + progresses.len, CompByEnterTime);
	for (int i = 0; i < progresses.len; i++) {
		progresses.Pro[i].startTime = progresses.Pro[i].endTime = progresses.Pro[i].running = 0;
	}
	Progresses readyPro;
	readyPro.len = 1;
	readyPro.Pro = (Progress*)malloc(sizeof(Progress));
	*(readyPro.Pro) = progresses.Pro[0];
	int t = 0, endTime = progresses.Pro[progresses.len - 1].enterTime, orderP = 1, orderQ = 0;
	while (t <= endTime || readyPro.len) {
		while (t == progresses.Pro[orderP].enterTime) {
			readyPro.Pro = (Progress*)realloc(readyPro.Pro, (readyPro.len + 1) * sizeof(Progress));
			readyPro.Pro[readyPro.len++] = progresses.Pro[orderP++];
		}
		sort(readyPro.Pro, readyPro.Pro + readyPro.len, CompByPriority);
		if (t >= readyPro.Pro[0].enterTime && t >= progresses.Pro[orderQ].endTime) {
			orderQ = GetOrder(progresses, readyPro.Pro[0]);
			if (!progresses.Pro[orderQ].startTime)progresses.Pro[orderQ].startTime = t;
		}
		if (progresses.Pro[orderQ].startTime && readyPro.Pro[0].running < readyPro.Pro[0].runTime) {
			readyPro.Pro[0].running++;
		}
		else if (readyPro.Pro[0].running == readyPro.Pro[0].runTime) {
			orderQ = GetOrder(progresses, readyPro.Pro[0]);
			progresses.Pro[orderQ].endTime = t;
			for (int i = 1; i < readyPro.len; i++)
				readyPro.Pro[i - 1] = readyPro.Pro[i];
			readyPro.Pro = (Progress*)realloc(readyPro.Pro, (readyPro.len - 1) * sizeof(Progress));
			readyPro.len--;
			t--;
		}
		t++;
	}
	sort(progresses.Pro, progresses.Pro + progresses.len, CompByStartTime);
	cout << "------------------���ȼ����ȣ���ռʽ��--------------------" << endl;
	OutputProgressInfo(progresses);
	cout << "------------------���ȼ����ȣ���ռʽ��--------------------" << endl;
}
void InputProgressInfo(Progresses &progresses) {
	int n;
	cout << "��������̸���n��";
	cin >> n;
	progresses.len = n;
	progresses.Pro = (Progress*)malloc(n * sizeof(Progress));
	cout << "������" << n << "�����̵���Ϣ��(��� ���ȼ� ����ʱ�� ����ʱ��)" << endl;
	for (int i = 0; i < n; i++) {
		cin >> progresses.Pro[i].num >> progresses.Pro[i].priority >> progresses.Pro[i].enterTime >> progresses.Pro[i].runTime;
		progresses.Pro[i].startTime = progresses.Pro[i].endTime = progresses.Pro[i].running = 0;
	}
}
void OutputProgressInfo(Progresses progresses) {
	int n = progresses.len;
	cout << " ��� ���ȼ� ��ʼʱ�� ����ʱ�� ��תʱ�� ����ʱ�� ����ʱ��" << endl;
	for (int i = 0; i < n; i++) {
		cout << setw(3) << progresses.Pro[i].num
			<< setw(7) << progresses.Pro[i].priority
			<< setw(9) << progresses.Pro[i].startTime
			<< setw(9) << progresses.Pro[i].endTime
			<< setw(9) << progresses.Pro[i].endTime - progresses.Pro[i].startTime
			<< setw(9) << progresses.Pro[i].enterTime
			<< setw(9) << progresses.Pro[i].runTime << endl;
	}
}
int main() {
	Progresses progresses;
	InputProgressInfo(progresses);
	FCFS(progresses);
	cout << endl << endl << endl;
	PSA_NM(progresses);
	cout << endl << endl << endl;
	PSA_PM(progresses);
	cout << endl << endl << endl;
	return 0;
}