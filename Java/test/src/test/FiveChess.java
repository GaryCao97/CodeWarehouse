package test;

import java.util.ArrayList;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Ellipse;
import javafx.scene.shape.Line;
import javafx.stage.Stage;

public class FiveChess extends Application {
	public void start(Stage primaryStage) throws Exception {
		BorderPane mainPane = new BorderPane();
		Wuziqi game = new Wuziqi();

		mainPane.setCenter(game.gamePane);
		mainPane.setBottom(game.statusPane);
		Scene scene = new Scene(mainPane);
		primaryStage.setTitle("五子棋");
		primaryStage.setScene(scene);
		primaryStage.show();
	}
	public static void main(String[] args) {
		Application.launch(args);
	}
}

class Wuziqi {
	private int cellSize = 19;
	private double w = 900, h = 900;
	private double perChessSize = 10;
	private double startPos = Math.abs(w - h);
	private int isX = (w < h ? 0 : 1);
	private int isY = 1 - isX;
	private double border = 5;
	private Line[] hLine;//横线
	private Line[] vLine;//竖线
	private int[][] chessBox;
	private ArrayList<Circle> chess;
	private int whoseTurn;//1 黑 -1 白
	public Pane gamePane = new Pane();
	public HBox statusPane = new HBox(5);
	private Label lbStatus = new Label();
	int whoWon;
	
	public Wuziqi() {
		statusPane.getChildren().add(lbStatus);
		lbStatus.setStyle("-fx-border-width: 1; -fx-border-color: #000000; -fx-background-color: #999999; -fx-font: bold 36 '宋体;'");
		lbStatus.setPrefSize(w, 20);
		hLine = new Line[cellSize];
		vLine = new Line[cellSize];
		chessBox = new int[cellSize][cellSize];
		chess = new ArrayList<Circle>();
		for(int i = 0;i < cellSize;i++)
			for(int j = 0;j < cellSize;j++)
				chessBox[i][j] = 0;
		gamePane.setPrefSize(w, h);
		drawLine();
		whoWon = 0;
		whoseTurn = 1;
		lbStatus.setText("轮到黑棋行动");
		gamePane.setOnMouseClicked(e -> {
			int i = (int)(e.getX() - isX * startPos) / (int)(perChessSize + border);
			int j = (int)(e.getY() - isY * startPos) / (int)(perChessSize + border);
			if(canChess(i,j)) {
				chessBox[j][i] = whoseTurn;
				if(whoseTurn == 1) {
					drawBlack(i,j);
					whoseTurn = -1;
					lbStatus.setText("轮到白棋行动");
				}
				else if(whoseTurn == -1) {
					drawWhite(i,j);
					whoseTurn = 1;
					lbStatus.setText("轮到黑棋行动");
				}
				whoWon = whoWon(i,j);
			}
			if(whoWon != 0) {
				whoseTurn = 0;
				Button btn = new Button("再来一次");
				Stage newStage = new Stage();
				Scene newScene = new Scene(btn, 400, 100);
				newStage.setTitle((whoWon == 1?"黑棋":"白棋") + "赢了");
				newStage.setScene(newScene);
				newStage.show();
				btn.setOnAction(c -> {
					restart();
					newStage.close();
				});
			} 
		});
	}

	public void drawLine() {
		for(int n = 0; n < cellSize; n++) {
			//横线
			hLine[n] = new Line(0,0,0,0);
			hLine[n].setStartX(isX * startPos + perChessSize * 0.5 + border);
			hLine[n].setStartY(isY * startPos + perChessSize * (n + 0.5) + border * (n+1));
			hLine[n].setEndX(w - isX * startPos - perChessSize * 0.5 - border);
			hLine[n].setEndY(isY * startPos + perChessSize * (n + 0.5) + border * (n+1));
			hLine[n].setStrokeWidth(1);
			hLine[n].setStroke(Color.BLACK);
			//竖线
			vLine[n] = new Line(0,0,0,0);
			vLine[n].setStartX(isX * startPos + perChessSize * (n + 0.5) + border * (n+1));
			vLine[n].setStartY(isY * startPos + perChessSize * 0.5 + border);
			vLine[n].setEndX(isX * startPos + perChessSize * (n + 0.5) + border * (n+1));
			vLine[n].setEndY(h - isY * startPos - perChessSize * 0.5 - border);
			vLine[n].setStrokeWidth(1);
			vLine[n].setStroke(Color.BLACK);
		}
		gamePane.getChildren().addAll(hLine);
		gamePane.getChildren().addAll(vLine);
		draw();
	}
	public boolean canChess(int i,int j) {
		if(i < 0 || j < 0 || i > cellSize || j > cellSize)return false;
		if(chessBox[j][i] == 0 && whoseTurn != 0)return true;
		return false;
	}
	public int whoWon(int i,int j) {
		int tmp = chessBox[j][i],num = 1,m;
		//横线判断
		m = 1;
		while((i + m < cellSize) && chessBox[j][i + (m++)] == tmp)num++;
		m = 1;
		while((i - m > -1) && chessBox[j][i - (m++)] == tmp)num++;
		if(num >= 5)return tmp;
		//竖线判断
		num = 1;
		m = 1;
		while((j + m < cellSize) && chessBox[j + (m++)][i] == tmp)num++;
		m = 1;
		while((j - m > -1) && chessBox[j - (m++)][i] == tmp)num++;
		if(num >= 5)return tmp;
		//左上右下
		num = 1;
		m = 1;
		while((i + m < cellSize) && (j + m < cellSize) && chessBox[j + (m)][i + (m++)] == tmp)num++;
		m = 1;
		while((i - m > -1) && (j - m > -1) && chessBox[j - (m)][i - (m++)] == tmp)num++;
		if(num >= 5)return tmp;
		//左下右上
		num = 1;
		m = 1;
		while((i + m < cellSize) && (j - m > -1) && chessBox[j - (m)][i + (m++)] == tmp)num++;
		m = 1;
		while((i - m > -1) && (j + m < cellSize) && chessBox[j + (m)][i - (m++)] == tmp)num++;
		if(num >= 5)return tmp;
		return 0;
	}
	public void drawBlack(int i, int j) {
		Circle ellipse = new Circle(10,10,10,10);
		ellipse.i = i;
		ellipse.j = j;
		ellipse.setCenterX(isX * startPos + perChessSize * (i + 0.5) + border * (i+1));
		ellipse.setCenterY(isY * startPos + perChessSize * (j + 0.5) + border * (j+1));
		ellipse.setRadiusX(perChessSize / 2);
		ellipse.setRadiusY(perChessSize / 2);
		ellipse.setStroke(Color.BLACK);
		ellipse.setFill(Color.BLACK);
		chess.add(ellipse);
		gamePane.getChildren().addAll(ellipse);
	}
	public void drawWhite(int i, int j) {
		Circle ellipse = new Circle(10,10,10,10);
		ellipse.i = i;
		ellipse.j = j;
		ellipse.setCenterX(isX * startPos + perChessSize * (i + 0.5) + border * (i+1));
		ellipse.setCenterY(isY * startPos + perChessSize * (j + 0.5) + border * (j+1));
		ellipse.setRadiusX(perChessSize / 2);
		ellipse.setRadiusY(perChessSize / 2);
		ellipse.setStroke(Color.BLACK);
		ellipse.setFill(Color.WHITE);
		chess.add(ellipse);
		gamePane.getChildren().addAll(ellipse);
	}
	void draw() {
		gamePane.widthProperty().addListener(ov -> {
			w = gamePane.getWidth();
			h = gamePane.getHeight();
			perChessSize = ((w < h ? w : h) - (cellSize + 1) * border) / cellSize;
			startPos = Math.abs(w - h) / 2;
			isX = (w < h ? 0 : 1);
			isY = 1 - isX;
			for(int n = 0; n < cellSize; n++) {
				//横线
				hLine[n].setStartX(isX * startPos + perChessSize * 0.5 + border);
				hLine[n].setStartY(isY * startPos + perChessSize * (n + 0.5) + border * (n+1));
				hLine[n].setEndX(w - isX * startPos - perChessSize * 0.5 - border);
				hLine[n].setEndY(isY * startPos + perChessSize * (n + 0.5) + border * (n+1));
				//竖线
				vLine[n].setStartX(isX * startPos + perChessSize * (n + 0.5) + border * (n+1));
				vLine[n].setStartY(isY * startPos + perChessSize * 0.5 + border);
				vLine[n].setEndX(isX * startPos + perChessSize * (n + 0.5) + border * (n+1));
				vLine[n].setEndY(h - isY * startPos - perChessSize * 0.5 - border);
			}
			for(int n = 0;n < chess.size();n++) {
				chess.get(n).setCenterX(isX * startPos + perChessSize * (chess.get(n).i + 0.5) + border * (chess.get(n).i+1));
				chess.get(n).setCenterY(isY * startPos + perChessSize * (chess.get(n).j + 0.5) + border * (chess.get(n).j+1));
				chess.get(n).setRadiusX(perChessSize / 2);
				chess.get(n).setRadiusY(perChessSize / 2);
			}
		});
		gamePane.heightProperty().addListener(ov -> {
			w = gamePane.getWidth();
			h = gamePane.getHeight();
			perChessSize = ((w < h ? w : h) - (cellSize + 1) * border) / cellSize;
			startPos = Math.abs(w - h) / 2;
			isX = (w < h ? 0 : 1);
			isY = 1 - isX;
			for(int n = 0; n < cellSize; n++) {
				//横线
				hLine[n].setStartX(isX * startPos + perChessSize * 0.5 + border);
				hLine[n].setStartY(isY * startPos + perChessSize * (n + 0.5) + border * (n+1));
				hLine[n].setEndX(w - isX * startPos - perChessSize * 0.5 - border);
				hLine[n].setEndY(isY * startPos + perChessSize * (n + 0.5) + border * (n+1));
				//竖线
				vLine[n].setStartX(isX * startPos + perChessSize * (n + 0.5) + border * (n+1));
				vLine[n].setStartY(isY * startPos + perChessSize * 0.5 + border);
				vLine[n].setEndX(isX * startPos + perChessSize * (n + 0.5) + border * (n+1));
				vLine[n].setEndY(h - isY * startPos - perChessSize * 0.5 - border);
			}
			for(int n = 0;n < chess.size();n++) {
				chess.get(n).setCenterX(isX * startPos + perChessSize * (chess.get(n).i + 0.5) + border * (chess.get(n).i+1));
				chess.get(n).setCenterY(isY * startPos + perChessSize * (chess.get(n).j + 0.5) + border * (chess.get(n).j+1));
				chess.get(n).setRadiusX(perChessSize / 2);
				chess.get(n).setRadiusY(perChessSize / 2);
			}
		});
	}
	void restart() {
		gamePane.getChildren().clear();
		for(int i = 0;i < cellSize;i++)
			for(int j = 0;j < cellSize;j++)
				chessBox[i][j] = 0;
		gamePane.getChildren().addAll(hLine);
		gamePane.getChildren().addAll(vLine);
		whoWon = 0;
		whoseTurn = 1;
	}
	class Circle extends Ellipse {
		public Circle(int k, int l, int m, int n) {
			super(k,l,m,n);
		}
		int i,j;
	}
}