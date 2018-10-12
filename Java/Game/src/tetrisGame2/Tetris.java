package tetrisGame2;

import javafx.beans.property.BooleanProperty;
import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleBooleanProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.Pane;

public class Tetris extends Pane {
	static final int LENGTH = 12,HIGH = 20;
	static final double WIDTH = Block.SIZE * LENGTH,HEIGHT = Block.SIZE * HIGH;
	private GridPane tetrisPane;
	private Block[][] blockMap;
	private int[][] tetrisMap;
	private int[][] tempTetrisMap;
	private TetrisBlock nowBlock;
	public TetrisBlock nextBlock;
	private IntegerProperty score;
	public BooleanProperty bpChange;
	
	public Tetris() {
		//this.setPrefSize(WIDTH+10, HEIGHT);
		bpChange = new SimpleBooleanProperty(false);
		score = new SimpleIntegerProperty(0);
		tetrisPane = new GridPane();
		this.getChildren().add(tetrisPane);
		tetrisMap = new int[HIGH][LENGTH];
		for(int i = 0;i < tetrisMap.length;i++) 
			for(int j = 0;j < tetrisMap[i].length;j++) 
				tetrisMap[i][j] = TetrisBlock.TYPR_NUM;
		tempTetrisMap = new int[HIGH][LENGTH];
		for(int i = 0;i < tempTetrisMap.length;i++) 
			for(int j = 0;j < tempTetrisMap[i].length;j++) 
				tempTetrisMap[i][j] = TetrisBlock.TYPR_NUM;
		blockMap = new Block[HIGH][LENGTH];
		for(int i = 0;i < blockMap.length;i++) 
			for(int j = 0;j < blockMap[i].length;j++) {
				blockMap[i][j] = new Block(null);
				tetrisPane.add(blockMap[i][j], j, i);
			}
		nextBlock = this.getRandBlock();
		nowBlock = nextBlock;
		nextBlock = this.getRandBlock();
		nowBlock.setLayoutX((LENGTH-TetrisBlock.LENGTH)/2);
		nowBlock.setLayoutY(-4);
		nowBlock.startDrop();
		nowBlock.layoutYProperty().addListener(al1 -> {
			setMap();
			if(isDown())next();
		});
	}
	public IntegerProperty scoreProperty() {
		return score;
	}
	private void setMap() {
		copyMap(tetrisMap,tempTetrisMap);
		int[][] pos = nowBlock.getBlockPos();
		for(int i = 0;i < pos.length;i++) 
			if(!outOfArea(pos[i][0], pos[i][1]))
				tempTetrisMap[pos[i][1]][pos[i][0]] = nowBlock.getType();
		updateMapToPane(tempTetrisMap);
	}
	private void updateMapToPane(int[][] map) {
		for(int i = 0;i < map.length;i++) 
			for(int j = 0;j < map[i].length;j++) 
				blockMap[i][j].setColor(TetrisBlock.blockColor[map[i][j]]);
	}
	private void copyMap(int[][] from,int[][] to) {
		for(int i = 0;i < from.length;i++) 
			for(int j = 0;j < from[i].length;j++) 
				to[i][j] = from[i][j];
	}
	boolean isEnd() {
		for(int i = 0;i < tetrisMap[0].length;i++) 
			if(tetrisMap[0][i] != TetrisBlock.TYPR_NUM)
				return true;
		return false;
	}
	public void speedUp() {
		nowBlock.getDropAnime().setRate(5.0);
	}
	public void speedBack() {
		nowBlock.getDropAnime().setRate(1.0);
	}
	public void fastDown() {
		nowBlock.getDropAnime().setRate(100.0);
	}
	public void moveLeft() {
		if(outOfArea(nowBlock))return;
		nowBlock.setLayoutX(nowBlock.getLayoutX() - 1);
		if(outOfArea(nowBlock))nowBlock.setLayoutX(nowBlock.getLayoutX()+ 1);
		setMap();
	}
	public void moveRight() {
		if(outOfArea(nowBlock))return;
		nowBlock.setLayoutX(nowBlock.getLayoutX() + 1);
		if(outOfArea(nowBlock))nowBlock.setLayoutX(nowBlock.getLayoutX() - 1);
		setMap();
	}
	public void rotateBlock() {
		nowBlock.rotateBlock();
		if(outOfArea(nowBlock))nowBlock.rotateBlockBack();
		setMap();
	}
	private boolean outOfArea(TetrisBlock what) {
		int[][] pos = what.getBlockPos();
		for(int i = 0;i < pos.length;i++) {
			int x = pos[i][0];
			int y = pos[i][1];
			if(x < 0 || x >= LENGTH || y >= HIGH)
				return true;
			if(y < 0)continue;
			if(tetrisMap[y][x] != TetrisBlock.TYPR_NUM)
				return true;
		}
		return false;
	}
	private boolean outOfArea(int x,int y) {
		if(x < 0 || y < 0 || x >= LENGTH || y >= HIGH)
			return true;
		return false;
	}
	private TetrisBlock getRandBlock() {
		int n = (int)(Math.random() * TetrisBlock.TYPR_NUM);
		return new TetrisBlock(n);
	}
	private boolean isDown() {
		int[][] pos = nowBlock.getBlockPos();
		for(int i = 0;i < pos.length;i++) {
			if(pos[i][1]+1 == HIGH) {
				return true;
			}
			else if(!outOfArea(pos[i][0], pos[i][1]+1))
				if(tetrisMap[pos[i][1] + 1][pos[i][0]] != TetrisBlock.TYPR_NUM) {
					return true;
				}
		}
		return false;
	}
	private boolean canClear(int y) {
		int sum = 0,t = LENGTH;
		while(t-- != 0) {
			sum += (tetrisMap[y][t] != TetrisBlock.TYPR_NUM ? 1 : 0);
		}
		return sum == LENGTH;
	}
	private void clearLine(int y) {
		for(int i = 0;i < LENGTH;i++) {
			for(int j = y;j > 0;j--) {
				tetrisMap[j][i] = tetrisMap[j - 1][i];
			}
			tetrisMap[0][i] = TetrisBlock.TYPR_NUM;
		}
	}
	private void next() {
		copyMap(tempTetrisMap,tetrisMap);
		int s = 0;
		for(int i = 0;i < HIGH;i++) {
			if(canClear(i)) {
				clearLine(i--);
				s++;
			}
		}
		//System.out.println(s);
		if(s>0)
			score.set(score.get() + (int)Math.pow(2, s));
		updateMapToPane(tetrisMap);
		nowBlock.stopDrop();
		if(!isEnd()) {
			nowBlock = nextBlock;
			nextBlock = this.getRandBlock();
			bpChange.set(true);
			nowBlock.setLayoutX((LENGTH-TetrisBlock.LENGTH)/2);
			nowBlock.setLayoutY(-4);
			nowBlock.startDrop();
			nowBlock.layoutYProperty().addListener(al1 -> {
				setMap();
				if(isDown())next();
			});
		}
		else {
			System.out.println("end");
			gameOver();
		}
		bpChange.set(false);
	}
	private void gameOver() {
		
	}
}
