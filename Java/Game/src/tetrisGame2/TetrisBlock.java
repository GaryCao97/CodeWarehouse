package tetrisGame2;

import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.util.Duration;

public class TetrisBlock {
	static final Color[] blockColor = {
			Color.rgb(128, 0, 128),//×Ï
			Color.rgb(0, 0, 255),//À¶
			Color.rgb(175, 255, 47),//Çà
			Color.rgb(0, 255, 0),//ÂÌ
			Color.rgb(255, 255, 0),//»Æ
			Color.rgb(255, 165, 0),//³È
			Color.rgb(255, 0, 0),//ºì
			Color.rgb(255, 255, 255)//°×
	};
	static final int[][][] blockPos = {
			{{1,0},{1,1},{1,2},{1,3}},//----
			{{1,1},{2,1},{2,2},{2,3}},//|__
			{{2,1},{2,2},{2,3},{1,3}},//__|
			{{2,1},{2,2},{1,2},{2,3}},//_|_
			{{1,1},{1,2},{2,2},{2,1}},//|| ==
			{{1,1},{1,2},{2,2},{2,3}},//-|_
			{{2,1},{2,2},{1,2},{1,3}} //_|-
	};
	static final int LENGTH = 4;
	static final int TYPR_NUM = 7;
	
	private IntegerProperty layoutX,layoutY;
	private int type;
	private int[][] blockShape;
	private Timeline dropAnime;
	
	public TetrisBlock(int blockType) {
		layoutX = new SimpleIntegerProperty(0);
		layoutY = new SimpleIntegerProperty(0);
		type = blockType;
		blockShape = new int[LENGTH][2];
		copyShape(blockPos[type],blockShape);
		dropAnime = new Timeline(new KeyFrame(Duration.millis(500), kf-> {
			setLayoutY(getLayoutY() + 1);
		}));
		dropAnime.setCycleCount(Timeline.INDEFINITE);
	}
	public Timeline getDropAnime() {
		return dropAnime;
	}
	public void startDrop() {
		dropAnime.play();
	}
	public void stopDrop() {
		dropAnime.stop();
	}
	public int getType() {
		return type;
	}
	public IntegerProperty layoutXProperty() {
		return layoutX;
	}
	public int getLayoutX() {
		return layoutX.get();
	}
	public void setLayoutX(int layoutX) {
		this.layoutX.set(layoutX);
	}
	public IntegerProperty layoutYProperty() {
		return layoutY;
	}
	public int getLayoutY() {
		return layoutY.get();
	}
	public void setLayoutY(int layoutY) {
		this.layoutY.set(layoutY);
	}
	public int[][] getBlockPos(){
		int[][] pos = new int[LENGTH][2];
		for(int i = 0;i < pos.length;i++) {
			pos[i][0] = blockShape[i][1] + getLayoutX();
			pos[i][1] = blockShape[i][0] + getLayoutY();
		}
		return pos;
	}
	public Color getBlockColor() {
		return blockColor[type];
	}
	public void rotateBlock() {
		for(int i = 0;i < LENGTH;i++) {
			int x = blockShape[i][1];
			int y = blockShape[i][0];
			blockShape[i][1] = (LENGTH - 1) - y;
			blockShape[i][0] = x;
		}
	}
	public void rotateBlockBack() {
		for(int i = 0;i < LENGTH;i++) {
			int x = blockShape[i][1];
			int y = blockShape[i][0];
			blockShape[i][1] = y;
			blockShape[i][0] = (LENGTH - 1) - x;
		}
	}
	private void copyShape(int[][] from, int[][] to) {
		for(int i = 0;i < from.length;i++) 
			for(int j = 0;j < from[i].length;j++) 
				to[i][j] = from[i][j];
	}
}

class Block extends Rectangle {
	static final double SIZE = 20;
	public Block(Color color) {
		super(0,0,SIZE,SIZE);
		if(color == null)color = Color.WHITE;
		this.setStroke(Color.BLACK);
		this.setStrokeWidth(0.1);
		this.setFill(color);
	}
	public void setColor(Color color) {
		this.setFill(color);
	}
}