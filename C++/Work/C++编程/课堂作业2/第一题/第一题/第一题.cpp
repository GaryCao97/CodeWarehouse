#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n,m=3;
start:
	cout << "��������Ҫ��������ĸ���n��";
	cin >> n;
	if (n <= 0) 
	{
		cout << "��������������󣬻���"<< --m << "�λ����������룡" << endl;
		goto start;
	}
	if (m == 0) 
		goto end;
	double num,max = 0,min = 0,aver = 0,sum_squares = 0,ssd;
	for (int i = 0;i < n;i++)
	{
		cout << "�������" << i+1 << "������";
		cin >> num;
		if (!i) {max = num;min = num;}
		if ( num > max) max = num;
		if (num < min) min = num;
		aver += num / n;
		sum_squares += num * num;
	}
	ssd = sqrt (sum_squares / n - pow (aver,2));
	cout << "��"<< n << "��������ֵ��ΧΪ��[" << min << " , " << max << "]" << endl;
	cout << "��Щ���ı�׼��Ϊ��" << ssd << endl;
end:
	return 0;
}