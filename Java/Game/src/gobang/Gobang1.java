package gobang;

import java.util.ArrayList;

import javafx.application.Application;
import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Ellipse;
import javafx.scene.shape.Line;
import javafx.scene.text.Text;
import javafx.stage.Stage;

public class Gobang1 extends Application {
	public void start(Stage primaryStage) throws Exception {
		BorderPane mainPane = new BorderPane();
		GobangPane centerPane = new GobangPane();
		StatusPane bottomPane = new StatusPane();
		bottomPane.setStatus(centerPane.whoseTurn.get());
		centerPane.whoseTurn.addListener(ov -> {
			bottomPane.setStatus(centerPane.whoseTurn.get());
		});
		mainPane.setCenter(centerPane);
		mainPane.setBottom(bottomPane);
		Scene scene = new Scene(mainPane);
		primaryStage.setTitle("五子棋");
		primaryStage.setScene(scene);
		primaryStage.show();
	}
	public static void main(String[] args) {
		Application.launch(args);
	}
}

class Gobang {
	private int chessboardSize;
	private int[][] chessboard;
	private int whoseTurn; // -1 白 1 黑

	public Gobang() {
		this(19);
	}
	public Gobang(int chessboardSize) {
		this.chessboardSize = chessboardSize;
		chessboard = new int[chessboardSize][chessboardSize];
		for(int i = 0;i < chessboardSize;i++)
			for(int j = 0;j < chessboardSize;j++)
				chessboard[i][j] = 0;
		whoseTurn = 1;
	}
	public boolean canPlace(int i,int j) {
		if(i < 0 || j < 0 || i > chessboardSize || j > chessboardSize)return false;
		if(chessboard[j][i] == 0 && whoseTurn != 0)return true;
		return false;
	}
	public void placeChess(int i,int j) {
		chessboard[j][i] = whoseTurn;
		whoseTurn = whoseTurn > 0 ? -1 : 1;
	}
	public int whoWon(int i,int j) {
		int tmp = chessboard[j][i],num = 1,m;
		//横线判断
		m = 1;
		while((i + m < chessboardSize) && chessboard[j][i + (m++)] == tmp)num++;
		m = 1;
		while((i - m > -1) && chessboard[j][i - (m++)] == tmp)num++;
		if(num >= 5)return tmp;
		//竖线判断
		num = 1;
		m = 1;
		while((j + m < chessboardSize) && chessboard[j + (m++)][i] == tmp)num++;
		m = 1;
		while((j - m > -1) && chessboard[j - (m++)][i] == tmp)num++;
		if(num >= 5)return tmp;
		//左上右下
		num = 1;
		m = 1;
		while((i + m < chessboardSize) && (j + m < chessboardSize) && chessboard[j + (m)][i + (m++)] == tmp)num++;
		m = 1;
		while((i - m > -1) && (j - m > -1) && chessboard[j - (m)][i - (m++)] == tmp)num++;
		if(num >= 5)return tmp;
		//左下右上
		num = 1;
		m = 1;
		while((i + m < chessboardSize) && (j - m > -1) && chessboard[j - (m)][i + (m++)] == tmp)num++;
		m = 1;
		while((i - m > -1) && (j + m < chessboardSize) && chessboard[j + (m)][i - (m++)] == tmp)num++;
		if(num >= 5)return tmp;
		return 0;
	}
	public int getWhoseTurn() {
		return whoseTurn;
	}
	public void restart() {
		for(int i = 0;i < chessboardSize;i++)
			for(int j = 0;j < chessboardSize;j++)
				chessboard[i][j] = 0;
		whoseTurn = 1;
	}
}

class GobangPane extends Pane {
	class Circle extends Ellipse {
		public Circle(int k, int l, int m, int n) {
			super(k,l,m,n);
		}
		int i,j;
	}
	private int boardSize;
	IntegerProperty whoseTurn;
	private Gobang game;
	private double w = 900, h = 900;
	private double perChessSize = 10;
	private double startPos = Math.abs(w - h);
	private int isX = (w < h ? 0 : 1);
	private int isY = 1 - isX;
	private double border = 5;
	private Line[] hLine;//横线
	private Line[] vLine;//竖线
	private ArrayList<Circle> chess;
	int whoWon;
	
	public GobangPane() {
		boardSize = 19;
		whoseTurn = new SimpleIntegerProperty();
		game = new Gobang(boardSize);
		hLine = new Line[boardSize];
		vLine = new Line[boardSize];
		chess = new ArrayList<Circle>();
		setPrefSize(w, h);
		whoseTurn.set(game.getWhoseTurn());
		whoWon = 0;
		drawLine();
		setEffect();
	}
	void drawLine() {
		for(int n = 0; n < boardSize; n++) {
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
		this.getChildren().addAll(hLine);
		this.getChildren().addAll(vLine);
	}
	void setEffect() {
		this.widthProperty().addListener(ov -> {
			w = this.getWidth();
			h = this.getHeight();
			perChessSize = ((w < h ? w : h) - (boardSize + 1) * border) / boardSize;
			startPos = Math.abs(w - h) / 2;
			isX = (w < h ? 0 : 1);
			isY = 1 - isX;
			for(int n = 0; n < boardSize; n++) {
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
		this.heightProperty().addListener(ov -> {
			w = this.getWidth();
			h = this.getHeight();
			perChessSize = ((w < h ? w : h) - (boardSize + 1) * border) / boardSize;
			startPos = Math.abs(w - h) / 2;
			isX = (w < h ? 0 : 1);
			isY = 1 - isX;
			for(int n = 0; n < boardSize; n++) {
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
		this.setOnMouseClicked(e -> {
			int i = (int)(e.getX() - isX * startPos) / (int)(perChessSize + border);
			int j = (int)(e.getY() - isY * startPos) / (int)(perChessSize + border);
			if(game.canPlace(i, j)) {
				drawChess(i,j,game.getWhoseTurn());
				game.placeChess(i, j);
				whoseTurn.set(game.getWhoseTurn());
				whoWon = game.whoWon(i,j);
			}
			if(whoWon != 0) {
				whoseTurn.set(0);
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
	public void drawChess(int i, int j, int whoseTurn) {
		Circle ellipse = new Circle(10,10,10,10);
		ellipse.i = i;
		ellipse.j = j;
		ellipse.setCenterX(isX * startPos + perChessSize * (i + 0.5) + border * (i+1));
		ellipse.setCenterY(isY * startPos + perChessSize * (j + 0.5) + border * (j+1));
		ellipse.setRadiusX(perChessSize / 2);
		ellipse.setRadiusY(perChessSize / 2);
		ellipse.setStroke(Color.BLACK);
		ellipse.setFill(whoseTurn > 0 ? Color.BLACK : Color.WHITE);
		chess.add(ellipse);
		this.getChildren().addAll(ellipse);
	}
	void restart() {
		game.restart();
		this.getChildren().clear();
		this.getChildren().addAll(hLine);
		this.getChildren().addAll(vLine);
		whoWon = 0;
		whoseTurn.set(1);;
	}
}

class StatusPane extends Pane {
	private Text tStatus;
	public StatusPane() {
		tStatus = new Text("");
		this.getChildren().add(tStatus);
		this.setStyle("-fx-alignment: center;");
	}
	public void setStatus(int whoseTurn) {
		String str = new String();
		if(whoseTurn == -1)str = "轮到白棋了";
		else if(whoseTurn == 1)str = "轮到黑棋了";
		tStatus.setText(str);
	}
}