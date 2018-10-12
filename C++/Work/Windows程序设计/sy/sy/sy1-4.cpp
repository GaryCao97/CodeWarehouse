#include<iostream>
using namespace std;
class Transport{
private:
	double speed;
	int people_num;
	double weight;
	char *size;
public:
	Transport(){
		speed = 0;
		people_num = 0;
		weight = 0;
		size = "125*1256*452";
	}
	void SetSpeed(double v){
		speed = v;
	}
	double GetSpeed(){
		return speed;
	}
	void SetNum(int n){
		people_num = n;
	}
	int GetNum(){
		return people_num;
	}
	void SetWeight(double w){
		weight = w;
	}
	double GetWeight(){
		return weight;
	}
	void SetSize(char s[]){
		size = s;
	}
	char* GetSize(){
		return size;
	}
};
class LandTransport :public Transport{
public:
	void ShowInfo(){
		printf_s("�ý�ͨ����Ϊ½�Ͻ�ͨ���ߣ�\n");
		printf_s("�ٶ�Ϊ��%.2lf km / h\n", GetSpeed());
		printf_s("��������Ϊ��%d ��\n", GetNum());
		printf_s("��ͨ��������Ϊ��%.2lf kg\n", GetWeight());
		printf_s("��ͨ�����ͺ�Ϊ��%s\n", GetSize());
	}
};
class AirTransport :public Transport{
public:
	void ShowInfo(){
		printf_s("�ý�ͨ����Ϊ���н�ͨ���ߣ�\n");
		printf_s("�ٶ�Ϊ��%.2lf km / h\n", GetSpeed());
		printf_s("��������Ϊ��%d ��\n", GetNum());
		printf_s("��ͨ��������Ϊ��%.2lf kg\n", GetWeight());
		printf_s("��ͨ�����ͺ�Ϊ��%s\n", GetSize());
	}
};
class WaterTransport :public Transport{
public:
	void ShowInfo(){
		printf_s("�ý�ͨ����Ϊˮ�Ͻ�ͨ���ߣ�\n");
		printf_s("�ٶ�Ϊ��%.2lf km / h\n", GetSpeed());
		printf_s("��������Ϊ��%d ��\n", GetNum());
		printf_s("��ͨ��������Ϊ��%.2lf kg\n", GetWeight());
		printf_s("��ͨ�����ͺ�Ϊ��%s\n", GetSize());
	}
};

int main(){
	LandTransport t1;
	AirTransport t2;
	WaterTransport t3;
	t1.ShowInfo();
	cout << endl;
	t2.ShowInfo();
	cout << endl;
	t3.ShowInfo();
	cout << endl;
	return 0;
}