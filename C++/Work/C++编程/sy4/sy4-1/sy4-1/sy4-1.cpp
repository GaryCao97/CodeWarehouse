#include<iostream>
using namespace std;
#define N 10
int MaxValue(int a[N])
{
	int max = a[0],i;
	for (i = 1;i < N;i++)
		max = max > a[i] ? max : a[i];
	return max;
}
int MinValue(int a[N])
{
	int min = a[0],i;
	for (i = 1;i < N;i++)
		min = min < a[i] ? min : a[i];
	return min;
}
int main()
{
	int a[N];
	printf("������%d��������\n",N);
	for(int i = 0;i < N;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i = 0;i < N;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n���ֵΪ%d��\n",MaxValue(a));
	cout << "�ǵ� ";
	for (int i = 0;i < N;i++)
		if(MaxValue(a) == a[i])	cout << i + 1 << " ";
	cout << "������";
	printf("\n��СֵΪ%d��\n",MinValue(a));
	cout << "�ǵ� ";
	for (int i = 0;i < N;i++)
		if(MinValue(a) == a[i])	cout << i + 1 << " ";
	cout << "������" << endl;
	return 0;
}