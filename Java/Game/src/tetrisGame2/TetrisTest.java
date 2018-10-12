package tetrisGame2;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.HBox;
import javafx.stage.Stage;

public class TetrisTest extends Application {
	Tetris gamePane = new Tetris();
	TetrisStatus gameStatus = new TetrisStatus();
	public void start(Stage primaryStage) throws Exception {
		HBox mainPane = new HBox(5);
		gameStatus.bindScore(gamePane.scoreProperty());
		gameStatus.setNextBlock(gamePane.nextBlock);
		gamePane.bpChange.addListener(al -> {
			if(gamePane.bpChange.get()) {
				gameStatus.setNextBlock(gamePane.nextBlock);
			}
		});
		mainPane.getChildren().add(gamePane);
		mainPane.getChildren().add(gameStatus);
		Scene gameScene = new Scene(mainPane);
		gameScene.setOnKeyPressed(kp -> {
			if(!gamePane.isEnd()) {
				//System.out.println(1);
				switch(kp.getCode()) {
				case UP:
					gamePane.rotateBlock();
					break;
				case DOWN:
					gamePane.speedUp();
					break;
				case LEFT:
					gamePane.moveLeft();
					break;
				case RIGHT:
					gamePane.moveRight();
					break;
				case SPACE:
					gamePane.fastDown();
					break;
				default:
					break;
				}
			}
		});
		gameScene.setOnKeyReleased(kp -> {
			switch(kp.getCode()) {
			case DOWN:
				gamePane.speedBack();
				break;
			default:
				break;
			}
		});
		primaryStage.setScene(gameScene);
		primaryStage.setTitle("¶íÂÞË¹·½¿é");
		primaryStage.show();
	}
	public static void main(String[] args) {
		launch(args);
	}
}
