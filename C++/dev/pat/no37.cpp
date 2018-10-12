#include<iostream>
using namespace std;
typedef struct{
	long Galleon,Sickle,Knut;
	long total;
}money;
void getTotal(money &mon){
	mon.total = ((mon.Galleon*17) + mon.Sickle)*29 + mon.Knut;
}
int main(){
	money m,n,ans;
	scanf("%ld.%ld.%ld %ld.%ld.%ld",&m.Galleon,&m.Sickle,&m.Knut,&n.Galleon,&n.Sickle,&n.Knut);
	getTotal(m);
	getTotal(n);
	ans.total = n.total - m.total;
	if(ans.total < 0){
		ans.total = -ans.total;
		cout << '-';
	}
	ans.Galleon = ans.total/(17*29);
	ans.Sickle = (ans.total - ans.Galleon*17*29)/29;
	ans.Knut = ans.total - ans.Galleon*17*29 - ans.Sickle * 29;
	cout << ans.Galleon << '.' << ans.Sickle << '.' << ans.Knut;
	return 0;
}
