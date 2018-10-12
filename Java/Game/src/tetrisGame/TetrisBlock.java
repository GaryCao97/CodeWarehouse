package tetrisGame;

import java.util.ArrayList;

import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.beans.property.DoubleProperty;
import javafx.beans.property.SimpleDoubleProperty;
import javafx.scene.Group;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.util.Duration;

public class TetrisBlock {
	static final int LENGTH = 4;
	static final int TYPR_NUM = 7;
	private Group parent;
	private DoubleProperty thisX,thisY;
	ArrayList<Block> blocks;
	private Timeline dropAnime;
	private int type;
	private int[][] blockShape;
	private final Color[] blockColor = {
			Color.rgb(128, 0, 128),//×Ï
			Color.rgb(0, 0, 255),//À¶
			Color.rgb(175, 255, 47),//Çà
			Color.rgb(0, 255, 0),//ÂÌ
			Color.rgb(255, 255, 0),//»Æ
			Color.rgb(255, 165, 0),//³È
			Color.rgb(255, 0, 0)//ºì
	};
	private final int[][][] blockPos = {
			{{1,0},{1,1},{1,2},{1,3}},//----
			{{1,1},{2,1},{2,2},{2,3}},//|__
			{{2,1},{2,2},{2,3},{1,3}},//__|
			{{2,1},{2,2},{1,2},{2,3}},//_|_
			{{1,1},{1,2},{2,2},{2,1}},//|| ==
			{{1,1},{1,2},{2,2},{2,3}},//-|_
			{{2,1},{2,2},{1,2},{1,3}} //_|-
	};
	
	public TetrisBlock(int blockType) {
		thisX = new SimpleDoubleProperty(0);
		thisY = new SimpleDoubleProperty(0);
		type = blockType;
		blocks = new ArrayList<Block>();
		for(int i = 0;i < LENGTH;i++) {
			Block b = new Block(blockColor[type]);
			blocks.add(b);
			b.setLayoutX(blockPos[type][i][1] * Block.SIZE);
			b.setLayoutY(blockPos[type][i][0] * Block.SIZE);
		}
		blockShape = blockPos[type];
		dropAnime = new Timeline(new KeyFrame(Duration.millis(500), e1 -> {
			setLayoutY(thisY.get() + Block.SIZE);
			//System.out.println(blocks.get(0).getLayoutY());
			//this.setLayoutY(this.getLayoutY() + Block.SIZE);
		}));
		dropAnime.setCycleCount(Timeline.INDEFINITE);
	}
	public void bindParent(Group p) {
		if(parent == null) {
			parent = p;
			for(int i = 0;i < LENGTH;i++) {
				parent.getChildren().add(blocks.get(i));
			}
		}
		else {
			for(int i = 0;i < blocks.size();i++) {
				parent.getChildren().remove(blocks.get(i));
			}
			parent = p;
			for(int i = 0;i < LENGTH;i++) {
				parent.getChildren().add(blocks.get(i));
			}
		}
	}
	public void setLayoutX(double x) {
		for(int i = 0;i < LENGTH;i++) {
			blocks.get(i).setLayoutX(x + blockShape[i][1] * Block.SIZE);
		}
		thisX.set(x);
	}
	public void setLayoutY(double y) {
		for(int i = 0;i < blocks.size();i++) {
			blocks.get(i).setLayoutY(y + blockShape[i][0] * Block.SIZE);
		}
		thisY.set(y);
	}
	public double getLayoutX() {
		return thisX.get();
	}
	public double getLayoutY() {
		return thisY.get();
	}
	public Timeline getAnime() {
		return dropAnime;
	}
	public void rotateBlock() {
		for(int i = 0;i < LENGTH;i++) {
			int x = blockShape[i][1];
			int y = blockShape[i][0];
			blockShape[i][1] = (LENGTH - 1) - y;
			blockShape[i][0] = x;
			// System.out.println(blockShape[i][1] + "," + blockShape[i][0]);
		}
		for(int i = 0;i < LENGTH;i++) {
			Block b = blocks.get(i);
			b.setLayoutX(thisX.get() + blockShape[i][1] * Block.SIZE);
			b.setLayoutY(thisY.get() + blockShape[i][0] * Block.SIZE);
		}
	}
	public void rotateBlockBack() {
		for(int i = 0;i < LENGTH;i++) {
			int x = blockShape[i][1];
			int y = blockShape[i][0];
			blockShape[i][1] = y;
			blockShape[i][0] = (LENGTH - 1) - x;
			// System.out.println(blockShape[i][1] + "," + blockShape[i][0]);
		}
		for(int i = 0;i < LENGTH;i++) {
			Block b = blocks.get(i);
			b.setLayoutX(thisX.get() + blockShape[i][1] * Block.SIZE);
			b.setLayoutY(thisY.get() + blockShape[i][0] * Block.SIZE);
		}
	}
	public int[][] getBlockPos(){
		int[][] pos = new int[LENGTH][2];
		for(int i = 0;i < LENGTH;i++) {
			pos[i][0] = (int)(blocks.get(i).getLayoutX() / Block.SIZE);//x
			pos[i][1] = (int)(blocks.get(i).getLayoutY() / Block.SIZE);//y
			System.out.println(pos[i][0] + " " + pos[i][1]);
		}
		return pos;
	}
	public DoubleProperty layoutYProperty() {
		return thisY;
	}
}

class Block extends Rectangle {
	static final double SIZE = 20;
	public Block(Color color) {
		super(0,0,SIZE,SIZE);
		this.setStroke(Color.BLACK);
		this.setStrokeWidth(0.1);
		this.setFill(color);
	}
}