#include <iostream>
using namespace std;
int main()
{
	int n,i;
	char a[]="";
	cout<<"请输入需要加密的字符：";
	cin>>a;
	n=sizeof(a);
	for (i = 0;i <= n-1;i++)
	{
		a[i] = a[i] + 5;
	}
	cout<<a<<endl;
	return 0;
}