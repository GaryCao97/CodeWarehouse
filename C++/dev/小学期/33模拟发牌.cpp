#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <algorithm>
using namespace std;
struct Poker{
	char Suit[5];
	char Face[3];
	int Num; 
}card[52];
char Player[4] = {'A','B','C','D'};
void Shuffle(){
	srand(time(0));
	for(int n = 0;n < 52;n++){
		card[n].Num = rand() % 52;
		for(int m = 0;m < n;m++)
			if(card[m].Num == card[n].Num){
				n--;
				break;
			}
	}
	for(int i = 0;i < 52;i++){
		switch(card[i].Num / 13){
		case 0 :strcpy(card[i].Suit,"ºÚÌÒ");break;
		case 1 :strcpy(card[i].Suit,"ºìÌÒ");break;
		case 2 :strcpy(card[i].Suit,"Ã·»¨");break;
		case 3 :strcpy(card[i].Suit,"·½¿é");break;
		}
		switch(card[i].Num % 13){
		case 0 :strcpy(card[i].Face,"A");break;
		case 1 :strcpy(card[i].Face,"2");break;
		case 2 :strcpy(card[i].Face,"3");break;
		case 3 :strcpy(card[i].Face,"4");break;
		case 4 :strcpy(card[i].Face,"5");break;
		case 5 :strcpy(card[i].Face,"6");break;
		case 6 :strcpy(card[i].Face,"7");break;
		case 7 :strcpy(card[i].Face,"8");break;
		case 8 :strcpy(card[i].Face,"9");break;
		case 9 :strcpy(card[i].Face,"10");break;
		case 10 :strcpy(card[i].Face,"J");break;
		case 11 :strcpy(card[i].Face,"Q");break;
		case 12 :strcpy(card[i].Face,"K");break;
		}
	}
}
int Comp(Poker p,Poker q){
	if ((p.Num % 13) == (q.Num % 13))return (p.Num / 13) > (q.Num / 13);
	else return (p.Num % 13) < (q.Num % 13);
}
void Output(){
	cout << setiosflags(ios::left);
	for(int o = 0,j = 0;o < 52;o++){
		if (j % 13 == 0)
			cout << "Íæ¼Ò" << Player[j/13] << ": ";
		cout << setw(4) << card[o].Suit;
		cout << setw(4) << card[o].Face;
		if (++j % 13 == 0)
			cout << endl << endl;
	}
}
int main(){
	Shuffle();
	sort(card,card + 13,Comp);
	sort(card + 13,card + 26,Comp);
	sort(card + 26,card + 39,Comp);
	sort(card + 39,card + 52,Comp);
	Output();
	return 0;
}
