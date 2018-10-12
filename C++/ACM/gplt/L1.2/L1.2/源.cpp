#include<iostream>
using namespace std;
int main(){
	int hh, mm;
	char hh_c, mm_c;
	scanf_s("%d:%d", &hh, &mm);
	if (hh < 12 || (hh == 12 && mm == 0)){
		hh_c = (hh < 10) ? '0' : 0;
		mm_c = (mm < 10) ? '0' : 0;
		cout << "Only " << hh_c << hh << ":" << mm_c << mm << ".  Too early to Dang.";
	}
	else{
		for (int i = 0; i < hh - 12; i++)
			cout << "Dang";
		if (mm > 0)
			cout << "Dang";
	}
	return 0;
}