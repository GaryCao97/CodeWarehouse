#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
struct Poker
{
	char Suit[9];
	char Face[6];
}card[52];
int Card[52];
void Shuffle()
{
	srand(time(0));
	for(int n = 0;n < 52;n++)
	{
		Card[n] = rand() % 52;
		for(int m = 0;m < n;m++)
			if(Card[m] == Card[n])
			{
				n--;
				break;
			}
	}
	for(int i = 0;i < 52;i++)
	{
		switch(Card[i] / 13)
		{
		case 0 :strcpy(card[i].Suit,"Spades");break;
		case 1 :strcpy(card[i].Suit,"Hearts");break;
		case 2 :strcpy(card[i].Suit,"Clubs");break;
		case 3 :strcpy(card[i].Suit,"Diamonds");break;
		}
		switch(Card[i] % 13)
		{
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
		case 10 :strcpy(card[i].Face,"Jack");break;
		case 11 :strcpy(card[i].Face,"Queen");break;
		case 12 :strcpy(card[i].Face,"King");break;
		}
	}
}
void Output()
{
	cout << setiosflags(ios::left);
	for(int o = 0,j = 0;o < 52;o++)
	{
		cout << setw(10) << card[o].Suit;
		cout << setw(9) << card[o].Face;
		if (++j % 4 == 0)
			cout << endl;
	}
}
int main()
{
	Shuffle();
	Output();
	return 0;
}
