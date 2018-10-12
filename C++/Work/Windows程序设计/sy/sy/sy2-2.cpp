#include<iostream>
using namespace std;
void strcopy(char *acceptance, char *resource) {
	int n = 0;
	while (resource[n]) {
		acceptance[n] = resource[n];
		n++;
	}
	acceptance[n] = '\0';
}
int main() {
	char *ch1, *ch2;
	cin >> ch1 >> ch2;
	cout << "×Ö·û´®1£º" << ch1 << endl;
	cout << "×Ö·û´®2£º" << ch2 << endl;
	strcopy(ch1, ch2);
	cout << "×Ö·û´®1£º" << ch1 << endl;
	cout << "×Ö·û´®2£º" << ch2 << endl;
	return 0;
}