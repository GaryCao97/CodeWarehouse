#include <iostream>
using namespace std;
int main()
{
	int A[11] = {-45,-6,1,16,49,68,82,167,502,630},input,i;
	cout << "Please enter an integer : ";
	cin >> input;
	for(i = 0;i < 11 && input > A[i];i++);
	for(int n = 10;n > i;n--)
		A[n] = A[n-1];
	A[i] = input;
	for(i = 0;i <11;i++)
		cout << A[i] << " ";
	cout << endl;
	return 0;
}