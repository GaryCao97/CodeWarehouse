package tetrisGame;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class TetrisTest extends Application {
	Tetris gamePane = new Tetris();
	public void start(Stage primaryStage) throws Exception {
		Scene gameScene = new Scene(gamePane);
		gameScene.setOnMouseClicked(mc -> {
			//gamePane.nowBlock.getAnime().play();
			//gamePane.nowBlock.setLayoutY(19 * Block.SIZE);
		});
		gameScene.setOnKeyPressed(kp -> {
			if(!gamePane.isEnd()) {
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
		primaryStage.setTitle("Ã∞≥‘…ﬂ”Œœ∑");
		primaryStage.show();
	}
	public static void main(String[] args) {
		launch(args);
	}
}
