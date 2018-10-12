#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int apple = 0 , watermelon = 0, pear = 0;
	int num = 0;
	for (apple = 1;apple <= 100;apple++)
	{
		for (watermelon = 1;watermelon <= 10;watermelon++)
		{
			for (pear = 1;pear <= 200;pear++)
			{
				if (apple + watermelon + pear == 100 && apple * 0.4 + watermelon * 4 + pear * 0.2 == 40)
				{
					cout << "apple " << setw(3) << apple << "  watermelon " << setw(3) << watermelon << "  pear " << setw(3) << pear << endl;
					num++;
				}
			}
		}
	}
	cout << "Total number  " << num << endl;
	return 0;
}