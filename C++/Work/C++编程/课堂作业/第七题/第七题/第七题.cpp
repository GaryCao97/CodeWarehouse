#include <iostream>
using namespace std;

int main()
{
	int num_1 , num_2 , num_3 , num_4;
	for (num_1 = 1; num_1 <= 9;num_1++)
	{
		for(num_2 = 1; num_2 <= 9;num_2++)
		{
			if (num_2 == num_1) continue;
			for (num_3 = 1; num_3 <= 9;num_3++)
			{
				if (num_3 == num_1 || num_3 == num_2) continue;
				for (num_4 = 1; num_4 <= 9;num_4++)
				{
					if (num_4 == num_1 || num_4 == num_2 || num_4 == num_3) continue;
					if (num_4 == 12 - (num_1 + num_2 + num_3))					
						cout << "Sum{ " << num_1 << ", " << num_2 << ", " << num_3 << ", " << num_4 << " }= 12" << endl;
				}
			}
		}
	}
	return 0;
}