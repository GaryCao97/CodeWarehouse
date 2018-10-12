#include <iostream>
using namespace std;
int main()
{
	double h,w,t;
	cout << "请输入：" << endl;
	cout << "体重(单位：kg) ";
	cin >> w;
	cout << "身高(单位：m)  ";
	cin >> h;
	t = w / (h * h);
	if(t < 18)
		printf("你的体指数为%lf，你是低体重体制。\n",t);
	else if(t>= 18&& t < 25)
		printf("你的体指数为%lf，你是正常体重体制。\n",t);
	else if(t>= 25&& t < 27)
		printf("你的体指数为%lf，你是超重体重体制。\n",t);
	else
		printf("你的体指数为%lf，你是肥胖体制。\n",t);
	return 0;
}