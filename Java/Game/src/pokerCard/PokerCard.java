package pokerCard;

import java.util.Random;

import javafx.scene.image.Image;
import javafx.scene.image.ImageView;

public class PokerCard {
	private int length;
	private Card[] cards;
	private Card[][] dealCards;
	Random Rand = new Random();
	public PokerCard() {
		length = 52;
		cards = new Card[length];
		for(int i = 0;i < length;i++) {
			cards[i] = new Card(i);
		}
	}
	public PokerCard(int len) {
		length = len;
		cards = new Card[length];
		for(int i = 0;i < length;i++) {
			cards[i] = new Card(i);
		}
	}
	private int[] random(int len) {
		int[] tmp = new int[len];
		for (int i = 0; i < len; i++) {
			tmp[i] = Rand.nextInt(len);
			for (int j = 0; j < i; j++) {
				if (tmp[j] == tmp[i]) {
					i--;
					break;
				}
			}
		}
		return tmp;
	}
	public void Shuffle() {
		int[] rand = random(length);
		Card temp = null;
		for(int i = 0; i < rand.length; i++){
			int k = rand[i];
			temp = cards[i];
			cards[i] = cards[k];
			cards[k] = temp;
		}
	}
	public void QiePai() {
		int number = Rand.nextInt(length);
		Card[] temp = new Card[length];
		int start = number;
		for (int i = 0; i < length - number; i++) {
			temp[i] = cards[start++];
		}
		for (int j = 0; j < number; j++) {
			temp[length - number + j] = cards[j];
		}
		for (int k = 0; k < length; k++) {
			cards[k] = temp[k];
		}
	}
	public void deal(int n, int len) {
		dealCards = new Card[n][len];
		Shuffle();
		for(int i = 0;i < n;i++) {
			for(int j = 0;j < len;j++) {
				dealCards[i][j] = cards[i *len + j];
			}
		}
	}
	public Card[] getDealCards(int index) {
		return dealCards[index];
	}
}

class Card{
	int index;
	String CardSuit;
	String CardNum;
	String CardName;
	ImageView CardImage;

	public Card(int order) {
		index = order;
		switch(order % 4) {
		case 0:CardSuit = "Spade";break;
		case 1:CardSuit = "Heart";break;
		case 2:CardSuit = "Club";break;
		case 3:CardSuit = "Diamond";break;
		}
		switch(order / 4) {
		case 0:CardNum = "A";break;
		case 1:CardNum = "2";break;
		case 2:CardNum = "3";break;
		case 3:CardNum = "4";break;
		case 4:CardNum = "5";break;
		case 5:CardNum = "6";break;
		case 6:CardNum = "7";break;
		case 7:CardNum = "8";break;
		case 8:CardNum = "9";break;
		case 9:CardNum = "10";break;
		case 10:CardNum = "J";break;
		case 11:CardNum = "Q";break;
		case 12:CardNum = "K";break;
		}
		if(order >= 52) {
			CardSuit = "";
			CardNum = "";
			CardName = order == 52 ? "" : "";
		}
		else CardName = CardSuit + " " + CardNum;
		CardImage = new ImageView(new Image(("file:/E:/Java/PokerImage/" + (order + 1) + ".jpg")));
		CardImage.setFitHeight(150);
		CardImage.setFitWidth(105);
	}
}