package tetrisGame2;

import javafx.beans.property.IntegerProperty;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.Pane;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;

public class TetrisStatus extends Pane {
	private GridPane nextBlockPane;
	private Text score;
	private TetrisBlock nextBlock;
	private Block[][] nextBlockMap;
	public TetrisStatus() {
		nextBlockPane = new GridPane();
		nextBlockMap = new Block[TetrisBlock.LENGTH][TetrisBlock.LENGTH];
		for(int i = 0;i < TetrisBlock.LENGTH;i++) {
			for(int j = 0;j < TetrisBlock.LENGTH;j++) {
				nextBlockMap[i][j] = new Block(null);
				nextBlockPane.add(nextBlockMap[i][j], j, i);
			}
		}
		score = new Text("0·Ö");
		score.setFont(Font.font("Times", FontWeight.BOLD,30));
		this.getChildren().add(nextBlockPane);
		this.getChildren().add(score);
		nextBlockPane.setLayoutX(0);
		nextBlockPane.setLayoutY(0);
		score.setLayoutX(0);
		score.setLayoutY(200);
	}
	public void bindScore(IntegerProperty ip) {
		ip.addListener(al -> {
			score.setText(ip.get() + "·Ö");
		});
	}
	public void setNextBlock(TetrisBlock tb) {
		for(int i = 0;i < TetrisBlock.LENGTH;i++) {
			for(int j = 0;j < TetrisBlock.LENGTH;j++) {
				nextBlockMap[i][j].setColor(TetrisBlock.blockColor[TetrisBlock.TYPR_NUM]);
			}
		}
		nextBlock = tb;
		int[][] pos = nextBlock.getBlockPos();
		for(int i = 0;i < pos.length;i++) {
			nextBlockMap[pos[i][1]][pos[i][0]].setColor(nextBlock.getBlockColor());
		}
	}
}
