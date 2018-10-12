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
		printf_s("该交通工具为陆上交通工具；\n");
		printf_s("速度为：%.2lf km / h\n", GetSpeed());
		printf_s("限载人数为：%d 人\n", GetNum());
		printf_s("交通工具重量为：%.2lf kg\n", GetWeight());
		printf_s("交通工具型号为：%s\n", GetSize());
	}
};
class AirTransport :public Transport{
public:
	void ShowInfo(){
		printf_s("该交通工具为空中交通工具；\n");
		printf_s("速度为：%.2lf km / h\n", GetSpeed());
		printf_s("限载人数为：%d 人\n", GetNum());
		printf_s("交通工具重量为：%.2lf kg\n", GetWeight());
		printf_s("交通工具型号为：%s\n", GetSize());
	}
};
class WaterTransport :public Transport{
public:
	void ShowInfo(){
		printf_s("该交通工具为水上交通工具；\n");
		printf_s("速度为：%.2lf km / h\n", GetSpeed());
		printf_s("限载人数为：%d 人\n", GetNum());
		printf_s("交通工具重量为：%.2lf kg\n", GetWeight());
		printf_s("交通工具型号为：%s\n", GetSize());
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