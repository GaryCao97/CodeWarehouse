#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;
int GetBNum(int arr1[4],int arr2[4])
{
	int num=0;
	for (int n = 0;n < 4;n++)
		for (int i = 0;i < 4;i++)
			if (arr1[i] == arr2[n]) num++;
	return num;
}
int GetANum(int arr1[4],int arr2[4])
{
	int num=0;
	for (int i = 0;i < 4;i++)
		if (arr1[i] == arr2[i]) num++;
	return num;
}
int main()
{
	srand(time(0));
	int num[4], input[4], _num, _input;

	do
	{
	_num = ( rand() + 1000 ) % 10000;
	for (int i = 0;i < 4;i++)
		num[i] =  ( _num / (int)pow(10,3 - i) )  % 10;
	}while (num[0] ==num[1] || num[0] == num[2] || num[0] == num[3] || num[1] == num[2] || num[1] == num[3] || num[2] == num[3]);
	int n = 10 ;
	cout<< "猜数游戏" << endl 
		<< "先由计算机随机生成一个各位相异的4位数字，由用户来猜，根据用户猜测的结果给出提示：xAyB" << endl
		<<"其中，A前面的数字表示有几位数字不仅数字猜对了，而且位置也正确，B前面的数字表示有几位数字猜对了，但是位置不正确。" << endl;
	do
	{
		cout << "请给出你猜的数字： ";
		cin >> _input ;
		while (_input >= 10000 || _input < 1000){
			cout << "你输入了一个错误的数字，请重新输入： ";
			cin >> _input;
		}
		for (int i = 0;i < 4;i++)
			input[i] =  ( _input / (int)pow(10,3 - i) )  % 10;
		if (GetANum(num,input) == 4) 
		{
			cout << "恭喜你答对了！ " << endl;
			break;
		}
		else 
		{
			cout << "A" << GetANum(num,input) << "B" << GetBNum(num,input) - GetANum(num,input)<< endl;
			cout << "对不起，你猜错了!你还有 "<< --n << " 次机会！" << endl;
		}
	}while (n > 0);
	if (n == 0)
		cout << "答案是" << _num << endl;
	return 0;
}