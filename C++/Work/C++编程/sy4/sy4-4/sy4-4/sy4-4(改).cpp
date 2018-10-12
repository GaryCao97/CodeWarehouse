#include <iostream>
#include <cstdio>
using namespace std;
int num[20];
void Sort()
{
	int temp;
	for (int n = 0;n < 20;n++)
	{
		for (int m = 0;m < n;m++)
		{
			if (num [n] <= num[m])
			{
				temp = num[n];
				for (int i = n;i > m;i--)
					num[i] = num[i - 1];
				num[m] = temp;
				break;
			}
		}
	}
	cout << "排序后：" << endl;
	for (int n = 0;n < 20;n++)
		cout << num[n] << " ";
	cout << endl;
}
void Search(int a,int b[20])
{
	int n1 = 0, n2 = 19, n3 = (n1 + n2) / 2;
	for (;a != b[n3];)
	{
		n3 = (n1 + n2) / 2;
		if(a > b[n3]) n1 = n3;
		else if (a < b[n3]) n2 = n3;
		if(n2 - n1 == 1 && a != b[n1] && a != b[n2])break;
		else if (n2 - n1 == 1 && n2 == 19)n3 = n2;
	}
	if (a == b[n3])
		cout << a << "是数列的第" << n3 + 1 << "个数。" << endl;
	else cout << a << "不在数列中。" << endl;
}
int main()
{
	cout << "请输入初始数列：" << endl;
	for(int i = 0;i < 20;i++)
		scanf("%d",&num[i]);
	Sort();
	int input;
loop:
	cout << "请输入你需要查找的数：";
	scanf("%d",&input);
	Search(input,num);
	goto loop;
	return 0;
}