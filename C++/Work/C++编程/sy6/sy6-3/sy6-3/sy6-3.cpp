#include <iostream>
#include <cstring>
using namespace std;
void newcopy(char *New,char *Old)
{
	int i = 0, j = 0;
	while(*(Old+i) != '\0')
	{
		if (*(Old+i) >= 'a' && *(Old+i) <= 'z')
		{
			for(j = i;*(Old+j) != '\0';j++)
				*(Old+j) = *(Old+j+1);
		}
		else
		{
			i++;
		}
	}
	for(i = 0;i < 20;i++)
		*(New + i) = *(Old + i);
}
int main()
{
	char old_ch[20] = "AsDfGHjkUbSiNDSeqh",new_ch[20];
	newcopy(new_ch,old_ch);
	//cout << old_ch << endl;
	cout << new_ch << endl;
	return 0;
}