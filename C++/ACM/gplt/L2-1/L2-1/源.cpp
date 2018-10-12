#include<iostream>
using namespace std;
struct people{
	double money = 0;
	int sum = 0;
	int num;
};
void sort(people *obj,int number,int left,int right){
	int i, j;
	people t, temp;
	if (left > right)return;
	temp = obj[left];
	i = left;
	j = right;
	while (i != j){
		while ((obj[j].money >= temp.money) && (i < j))
			j--;
		while ((obj[i].money <= temp.money) && (i < j))
			i++;
		if (i < j){
			t = obj[i];
			obj[i] = obj[j];
			obj[j] = t;
		}
	}
	obj[left] = obj[i];
	obj[i] = temp;
	sort(obj, number, left, i - 1);
	sort(obj, number, i + 1, right);
	return;
}
int main(){
	people per[10001];
	int n, m = 0;
	cin >> n;
	while (m++ < n){
		int num, sum = 0;
		cin >> num;
		while (num-- > 0){
			int i, r_money;
			cin >> i >> r_money;
			sum += r_money;
			per[i].money += r_money;
			per[i].sum += 1;
		}
		per[m].money -= sum;
		per[m].num = m;
	}
	sort(per, n, 1, n);
	for (int j = n; j >= 1; j--){
		per[j].money = per[j].money / 100.0;
		printf("%d %.2lf", per[j].num, per[j].money);
		if (j != 1)cout << endl;
	}
	return 0;
}