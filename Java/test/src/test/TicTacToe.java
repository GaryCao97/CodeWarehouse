package test;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Ellipse;
import javafx.scene.shape.Line;
import javafx.stage.Stage;

public class TicTacToe extends Application {
	public static void main(String[] args) {
		Application.launch(args);
	}
	private final int chessNum = 3;
	private Cell[][] cell = new Cell[chessNum][chessNum];
	private char whoseTurn = 'X';
	private Label lbStatus = new Label("轮到X走了！");
	public void start(Stage primaryStage) throws Exception {
		GridPane chessBox = new GridPane();
		for(int i = 0;i < chessNum;i++)
			for(int j = 0;j < chessNum;j++)
				chessBox.add(cell[i][j] = new Cell(), j, i);
		
		Button btnAgain = new Button("新的游戏");
		btnAgain.setOnAction(e -> {
			for(int i = 0;i < chessNum;i++)
				for(int j = 0;j < chessNum;j++) {
					cell[i][j].setStatus(' ');
					cell[i][j].getChildren().clear();
				}
			whoseTurn = 'X';
			lbStatus.setText("轮到" + whoseTurn + "走了！");
		});
		
		BorderPane mainPane = new BorderPane();
		mainPane.setTop(btnAgain);
		mainPane.setCenter(chessBox);
		mainPane.setBottom(lbStatus);
		
		Scene scene = new Scene(mainPane,450,400);
		primaryStage.setTitle("井字棋");
		primaryStage.setScene(scene);
		primaryStage.show();
	}
	public boolean isFull() {
		for(int i = 0;i < chessNum;i++)
			for(int j = 0;j < chessNum;j++)
				if(cell[i][j].getStatus() == ' ')
					return false;
		return true;
	}
	public boolean isWon(char who) {
		for(int n = 0;n < chessNum;n++) {
			if(cell[n][0].getStatus() == who &&
					cell[n][1].getStatus() == who &&
					cell[n][2].getStatus() == who) {
				return true;
			}
			if(cell[0][n].getStatus() == who &&
					cell[1][n].getStatus() == who &&
					cell[2][n].getStatus() == who) {
				return true;
			}
		}
		if(cell[0][0].getStatus() == who &&
				cell[1][1].getStatus() == who &&
				cell[2][2].getStatus() == who) {
			return true;
		}
		if(cell[0][2].getStatus() == who &&
				cell[1][1].getStatus() == who &&
				cell[2][0].getStatus() == who) {
			return true;
		}
		return false;
	}
	class Cell extends Pane {
		private char status = ' ';
		public Cell() {
			setStyle("-fx-border-color:black");
			this.setPrefSize(2000,2000);
			this.setOnMouseClicked(e -> handleMouseClick());
		}
		public char getStatus() {return status;}
		public void setStatus(char status) {
			this.status = status;
			if(this.status == 'X') drawX();
			else if(this.status == 'O') drawO();
		}
		public void drawX() {
			Line line1 = new Line(10, 10, 10, 10);
			line1.endXProperty().bind(this.widthProperty().subtract(10));
			line1.endYProperty().bind(this.heightProperty().subtract(10));
			Line line2 = new Line(10, 10, 10, 10);
			line2.endXProperty().bind(this.widthProperty().subtract(10));
			line2.startYProperty().bind(this.heightProperty().subtract(10));
			getChildren().addAll(line1, line2);
		}
		public void drawO() {
			Ellipse ellipse = new Ellipse(10,10,10,10);
			ellipse.centerXProperty().bind(this.widthProperty().divide(2));
			ellipse.centerYProperty().bind(this.heightProperty().divide(2));
			ellipse.radiusXProperty().bind(this.widthProperty().divide(2).subtract(10));
			ellipse.radiusYProperty().bind(this.heightProperty().divide(2).subtract(10));
			ellipse.setStroke(Color.BLACK);
			ellipse.setFill(Color.WHITE);
			getChildren().addAll(ellipse);
		}
		public void handleMouseClick() {
			if(status == ' ' && whoseTurn != ' ') {
				setStatus(whoseTurn);
				if(isWon(whoseTurn)) {
					lbStatus.setText(whoseTurn + " 赢了！游戏结束！");
					whoseTurn = ' ';
				}
				else if(isFull()) {
					lbStatus.setText("平局！游戏结束");
					whoseTurn = ' ';
				}
				else {
					whoseTurn = (whoseTurn == 'X') ? 'O' : 'X';
					lbStatus.setText("轮到" + whoseTurn + "走了！");
				}
			}
		}
	}
}
