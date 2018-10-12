#include<iostream>
#include<string>
using namespace std;
int main() {
	string a;
	string b;
	cin >> a >> b;
	int lena = a.size();
	int lenb = b.size();
	int index = 1;
	while(lenb < lena) {
		b = "0" + b;
		lenb++;
	}
	for(; index<=lena; index++) {
		if(index%2) {
			int t = (a[lena-index]+b[lenb-index]-'0'-'0') % 13;
			switch(t) {
				case 10 :
					b[lenb-index] = 'J';
					break;
				case 11 : 
					b[lenb-index] = 'Q';
					break;
				case 12 : 
					b[lenb-index] = 'K';
					break;
				default :
					b[lenb-index] = t + '0';
			}
		}
		else {
			int t = b[lenb-index] - a[lena-index];
			t = t < 0 ? t+10 : t;
			b[lenb-index] = t+'0';
		}
	}
	cout << b << endl;
	return 0;
}
