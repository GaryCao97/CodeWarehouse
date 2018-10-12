package AfterClass;

import java.util.Random;

import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.stage.Stage;

public class PokerCard extends Application {
	public static void main(String[] args) {
		launch(args);
	}
	public void start(Stage primaryStage) throws Exception {
		CardGame g0 = new CardGame();
		Bridge g1 = new Bridge();
		Poker g2 = new Poker();
		BorderPane mainPane = new BorderPane();
		HBox topPane = new HBox(5);
		Button btnBridge = new Button("Bridge牌");
		topPane.getChildren().add(btnBridge);
		Button btnPoker = new Button("Poker牌");
		topPane.getChildren().add(btnPoker);
		TextField tfN = new TextField();
		topPane.getChildren().add(tfN);
		topPane.setAlignment(Pos.CENTER);
		topPane.setStyle("-fx-padding:15 15 15 15;");
		mainPane.setTop(topPane);
		mainPane.setCenter(g0.gamePane);
		btnBridge.setOnAction(e -> {
			g1.deal();
			mainPane.setCenter(g1.gamePane);
		});
		btnPoker.setOnAction(e -> {
			if(tfN.getText() != "") {
				g2.deal(Integer.parseInt(tfN.getText()));
				mainPane.setCenter(g2.gamePane);
			}
		});
		Scene scene = new Scene(mainPane,1600,900);
		primaryStage.setTitle("棋牌游戏");
		primaryStage.setScene(scene);
		primaryStage.show();
	}
}

class Card {
	int index;
	String CardSuit;
	String CardNum;
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
		CardImage = new ImageView(new Image(("file:PokerImage/" + (order + 1) + ".jpg")));
		CardImage.setFitHeight(150);
		CardImage.setFitWidth(105);
	}
}
class CardGame {
	//设计CardGame类表示普通的52张纸牌，
	//有四种花色（红心Heart、方块Diamond、梅花Club和黑桃Spade），
	//每种花色各13张：A、K、Q、J、10、9、......2，
	//设计适当函数实现纸牌基本功能，如洗牌等
	int length = 52;
	Card[] cards = new Card[length];
	public GridPane gamePane;
	Random Rand = new Random();
	public CardGame() {
		for(int i = 0;i < length;i++) {
			cards[i] = new Card(i);
		}
		gamePane = new GridPane();
		gamePane.setVgap(5);
		gamePane.setHgap(5);
		gamePane.setStyle("-fx-padding:5 5 5 5;");
		gamePane.setAlignment(Pos.CENTER);
		for(int i = 0;i < 4;i++) {
			gamePane.add(new Label("第" + (i+1) + "手"), 0, i);
			for(int j = 1;j <= 13;j++) {
				gamePane.add(cards[i*13 + (j - 1)].CardImage, j, i);
			}
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
}
class Bridge extends CardGame {
	//从CardGame类派生出Bridge类，为Bridge类设计deal函数，用来将纸牌分为四手，每手13张；
	public void deal() {
		gamePane.getChildren().clear();
		Shuffle();
		for(int i = 0;i < 4;i++) {
			gamePane.add(new Label("第" + (i+1) + "手"), 0, i);
			for(int j = 1;j <= 13;j++) {
				gamePane.add(cards[i*13 + (j - 1)].CardImage, j, i);
			}
		}
	}
}
class Poker extends CardGame {
	//从CardGame类派生出Poker类，为Poker类设计deal函数，用来将纸牌分为n手（n从2到7，代表游戏人数），每手5张。
	public void deal(int n) {
		gamePane.getChildren().clear();
		if(n >= 2 && n <= 7) {
			Shuffle();
			for(int i = 0;i < n;i++) {
				gamePane.add(new Label("第" + (i+1) + "手"),i, 0);
				for(int j = 1;j <= 5;j++) {
					gamePane.add(cards[i*5 + j - 1].CardImage, i, j);
				}
			}
		}
	}
}