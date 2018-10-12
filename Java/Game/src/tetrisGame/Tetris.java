package tetrisGame;

import javafx.collections.ObservableList;
import javafx.scene.Group;
import javafx.scene.Node;
import javafx.scene.layout.Pane;

public class Tetris extends Pane {
	static final int LENGTH = 12,HIGH = 20;
	static final double WIDTH = Block.SIZE * LENGTH,HEIGHT = Block.SIZE * HIGH;
	//static final double BORDER_SIZE = 1;
	private Group tetrisPane;
	TetrisBlock nowBlock;
	private TetrisBlock nextBlock;
	private int[] blockStack;
	private int[] lineStack;
	
	public Tetris() {
		this.setPrefSize(WIDTH, HEIGHT);
		tetrisPane = new Group();
		this.getChildren().add(tetrisPane);
		blockStack = new int[LENGTH];
		for(int i = 0;i < LENGTH;i++)
			blockStack[i] = HIGH;
		lineStack = new int [HIGH];
		for(int i = 0;i < HIGH;i++)
			lineStack[i] = 0;
		nextBlock = getRandBlock();
		nowBlock = nextBlock;
		nextBlock = getRandBlock();
		nowBlock.bindParent(tetrisPane);
		//nextBlock.bindParent(tetrisPane);
		nowBlock.setLayoutX((LENGTH - TetrisBlock.LENGTH) * Block.SIZE / 2);
		nowBlock.setLayoutY((- TetrisBlock.LENGTH + 1) * Block.SIZE);
		nextBlock.setLayoutX(WIDTH);
		nextBlock.setLayoutY(HEIGHT);
		nowBlock.getAnime().play();
		nowBlock.layoutYProperty().addListener(al -> {
			if(isDown(nowBlock))next();
		});
	}
	public boolean isEnd() {
		for(int i = 0;i < blockStack.length;i++) {
			if(blockStack[i] <= 0) {
				return true;
			}
		}
		return false;
	}
	public void speedUp() {
		nowBlock.getAnime().setRate(5.0);
	}
	public void speedBack() {
		nowBlock.getAnime().setRate(1.0);
	}
	public void fastDown() {
		nowBlock.getAnime().setRate(100.0);
	}
	public void moveLeft() {
		nowBlock.setLayoutX(nowBlock.getLayoutX() - Block.SIZE);
		if(outOfArea())moveRight();
	}
	public void moveRight() {
		nowBlock.setLayoutX(nowBlock.getLayoutX() + Block.SIZE);
		if(outOfArea())moveLeft();
	}
	public void rotateBlock() {
		//System.out.println(123);
		nowBlock.rotateBlock();
		if(outOfArea())nowBlock.rotateBlockBack();
	}
	public boolean outOfArea() {
		int[][] pos = nowBlock.getBlockPos();
		for(int i = 0;i < pos.length;i++) {
			if(pos[i][0] < 0 || pos[i][0] >= LENGTH)return true;
			if(pos[i][1] >= (blockStack[pos[i][0]] - 1))return true;
		}
		return false;
	}
	public TetrisBlock getRandBlock() {
		int n = (int)(Math.random() * TetrisBlock.TYPR_NUM);
		return new TetrisBlock(n);
	}
	public boolean isDown(TetrisBlock what) {
		System.out.println(1);
		int[][] pos = what.getBlockPos();
		for(int i = 0;i < pos.length;i++) {
			if(pos[i][1] == (blockStack[pos[i][0]] - 1)) {
				return true;
			}
		}
		return false;
	}
	public void pushValueToStack(TetrisBlock what) {
		int[][] pos = what.getBlockPos();
		for(int i = 0;i < pos.length;i++) {
			blockStack[pos[i][0]] = blockStack[pos[i][0]] > pos[i][1] ? pos[i][1] : blockStack[pos[i][0]];
			lineStack[pos[i][1]]++;
		}
	}
	public void clearLine(int y) {
/*		System.out.println(y);
		System.out.println((int)(nowBlock.blocks.get(0).getLayoutY() / Block.SIZE));
		System.out.println((int)(nowBlock.blocks.get(1).getLayoutY() / Block.SIZE));
		System.out.println((int)(nowBlock.blocks.get(2).getLayoutY() / Block.SIZE));
		System.out.println((int)(nowBlock.blocks.get(3).getLayoutY() / Block.SIZE));*/
		ObservableList<Node> olNodes = tetrisPane.getChildren();
		for(int i = 0;i < olNodes.size();i++) {
			if(olNodes.get(i).getLayoutY() == y * Block.SIZE) {
				System.out.print(1+" ");
				olNodes.remove(i--);
			}
		}
		for(int i = 0;i < LENGTH;i++)
			blockStack[i] = HIGH;
		for(int i = 0;i < olNodes.size();i++) {
			if(olNodes.get(i).getLayoutY() < y * Block.SIZE) {
				olNodes.get(i).setLayoutY(olNodes.get(i).getLayoutY() + Block.SIZE);
			}
			int n = (int)(olNodes.get(i).getLayoutY() / Block.SIZE);
			int m = (int)(olNodes.get(i).getLayoutX() / Block.SIZE);
			blockStack[m] = blockStack[m] > n ? n : blockStack[m];
		}
	}
	public boolean canClear(int y) {return lineStack[y] == LENGTH;}
	public void next() {
		nowBlock.getAnime().stop();
		pushValueToStack(nowBlock);
		for(int i = 0;i < HIGH;i++) {
			if(canClear(i))clearLine(i--);
		}
		if(!isEnd()) {
			nowBlock = nextBlock;
			nextBlock = getRandBlock();
			nowBlock.bindParent(tetrisPane);
			nowBlock.setLayoutX((LENGTH - TetrisBlock.LENGTH) * Block.SIZE / 2);
			nowBlock.setLayoutY((- TetrisBlock.LENGTH) * Block.SIZE);
			nextBlock.setLayoutX(WIDTH);
			nextBlock.setLayoutY(HEIGHT);
			nowBlock.getAnime().play();
			nowBlock.layoutYProperty().addListener(al -> {
				if(isDown(nowBlock))next();
			});
		}
		else {
			System.out.println("end");
		}
	}
}
