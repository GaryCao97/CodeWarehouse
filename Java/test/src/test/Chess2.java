package test;

import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Ellipse;
import javafx.scene.shape.Line;
import javafx.stage.Stage;

public class Chess2 extends Application {
	public void start(Stage primaryStage) throws Exception {
		ChessBox mainPane = new ChessBox();
		Scene scene = new Scene(mainPane, 400, 400);
		primaryStage.setTitle("井字棋2");
		primaryStage.setScene(scene);
		primaryStage.show();
	}
	public static void main(String[] args) {
		Application.launch(args);
	}
}
class ChessBox extends Pane{
	private int chessNum = 3;
	private double w = 4000, h = 4000;
	private Line[] hLine;//横线
	private Line[] vLine;//竖线
	private int[][] chessBox;
	private int whoseTurn;//1 X -1 O
	private int[] check;
	int whoWon;
	private static char[] chess = {'O',' ','X'};
	
	public ChessBox() {
		hLine = new Line[chessNum + 1];
		vLine = new Line[chessNum + 1];
		chessBox = new int[chessNum][chessNum];
		check = new int[2 * chessNum + 2];
		for(int i = 0;i < chessNum;i++)
			for(int j = 0;j < chessNum;j++)
				chessBox[i][j] = 0;
		for(int n = 0;n < 2 * chessNum + 2;n++)check[n] = 0;
		this.setPrefSize(w, h);
		drawLine();
		whoWon = 0;
		whoseTurn = 1;
		this.setOnMouseClicked(e -> {
			int i = ((int)e.getX()) / ((int) (this.getWidth() / chessNum));
			int j = ((int)e.getY()) / ((int) (this.getHeight() / chessNum));
			if(canChess(i,j)) {
				drawChess(i,j);
				whoWon = whoWon();
			}
			if(whoWon != 0) {
				whoseTurn = 0;
				HBox pane = new HBox(4);
				Label text = new Label(chess[whoWon + 1] + "赢了");
				Button btn = new Button("再来一次");
				pane.getChildren().addAll(text,btn);
				pane.setAlignment(Pos.CENTER);
				Stage newStage = new Stage();
				Scene newScene = new Scene(pane, 200, 200);
				newStage.setTitle("消息");
				newStage.setScene(newScene);
				newStage.show();
				btn.setOnAction(c -> {
					this.restart();
					newStage.close();
				});
			} 
		});
	}
	
	public void drawLine() {
		for(int n = 0; n <= chessNum; n++) {
			hLine[n] = new Line(0,0,0,0);
			hLine[n].startYProperty().bind(this.heightProperty().divide(chessNum).multiply(n));
			hLine[n].endXProperty().bind(this.widthProperty());
			hLine[n].endYProperty().bind(this.heightProperty().divide(chessNum).multiply(n));
			hLine[n].setStrokeWidth(5);
			hLine[n].setStroke(Color.BLACK);
			vLine[n] = new Line(0,0,0,0);
			vLine[n].startXProperty().bind(this.widthProperty().divide(chessNum).multiply(n));
			vLine[n].endXProperty().bind(this.widthProperty().divide(chessNum).multiply(n));
			vLine[n].endYProperty().bind(this.heightProperty());
			vLine[n].setStrokeWidth(5);
			vLine[n].setStroke(Color.BLACK);
		}
		this.getChildren().addAll(hLine);
		this.getChildren().addAll(vLine);
	}
	public boolean canChess(int i,int j) {
		if(chessBox[j][i] == 0 && whoseTurn != 0)return true;
		return false;
	}
	public int whoWon() {
		for(int i = 0;i < check.length;i++) {
			if(check[i] != 0 && check[i] % chessNum == 0)return check[i] / chessNum;
		}
		return 0;
	}
	public void drawChess(int i, int j) {
		// x = (i + 0.5) * (this.getWidth() / chessNum);
		// y = (j + 0.5) * (this.getHeight() / chessNum);
		chessBox[j][i] = whoseTurn;
		check[j] += whoseTurn;
		check[i + chessNum] += whoseTurn;
		if(j == i)check[2 * chessNum] += whoseTurn;
		if(j + i == chessNum - 1)check[2 * chessNum + 1] += whoseTurn;
		if(whoseTurn == 1) {
			drawX(i,j);
			whoseTurn = -1;
		}
		else if(whoseTurn == -1) {
			drawO(i,j);
			whoseTurn = 1;
		}
	}
	public void drawX(int i, int j) {
		Line line1 = new Line(10, 10, 10, 10);
		line1.startXProperty().bind(this.widthProperty().divide(chessNum).multiply(i).add(10));
		line1.startYProperty().bind(this.heightProperty().divide(chessNum).multiply(j).add(10));
		line1.endXProperty().bind(this.widthProperty().divide(chessNum).multiply(i + 1).subtract(10));
		line1.endYProperty().bind(this.heightProperty().divide(chessNum).multiply(j + 1).subtract(10));
		Line line2 = new Line(10, 10, 10, 10);
		line2.startXProperty().bind(this.widthProperty().divide(chessNum).multiply(i).add(10));
		line2.startYProperty().bind(this.heightProperty().divide(chessNum).multiply(j + 1).subtract(10));
		line2.endXProperty().bind(this.widthProperty().divide(chessNum).multiply(i + 1).subtract(10));
		line2.endYProperty().bind(this.heightProperty().divide(chessNum).multiply(j).add(10));
		getChildren().addAll(line1, line2);
	}
	public void drawO(int i, int j) {
		Ellipse ellipse = new Ellipse(10,10,10,10);
		ellipse.centerXProperty().bind(this.widthProperty().divide(chessNum).multiply(i + 0.5));
		ellipse.centerYProperty().bind(this.heightProperty().divide(chessNum).multiply(j + 0.5));
		ellipse.radiusXProperty().bind(this.widthProperty().divide(chessNum * 2).subtract(10));
		ellipse.radiusYProperty().bind(this.heightProperty().divide(chessNum * 2).subtract(10));
		ellipse.setStroke(Color.BLACK);
		ellipse.setFill(Color.WHITE);
		getChildren().addAll(ellipse);
	}
	void restart() {
		getChildren().clear();
		for(int i = 0;i < chessNum;i++)
			for(int j = 0;j < chessNum;j++)
				chessBox[i][j] = 0;
		for(int n = 0;n < 2 * chessNum + 2;n++)check[n] = 0;
		this.getChildren().addAll(hLine);
		this.getChildren().addAll(vLine);
		whoWon = 0;
		whoseTurn = 1;
	}
}
