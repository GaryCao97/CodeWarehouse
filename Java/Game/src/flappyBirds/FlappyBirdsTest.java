package flappyBirds;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.input.KeyCode;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;

public class FlappyBirdsTest extends Application {
	public void start(Stage primaryStage) throws Exception {
		Pane gamePane = new Pane();
		Group game = new Group();
		FlappyBirds fb = new FlappyBirds(game);
		gamePane.getChildren().add(game);
		gamePane.setPrefSize(FlappyBirdsWall.WIDTH, FlappyBirdsWall.HEIGHT);
		FlappyBirdsWall.bindParent(game);
		FlappyBirdsWall.createWalls();
		FlappyBirdsWall.wallsMove();
		Scene gameScene = new Scene(gamePane);
		
		gameScene.setOnKeyPressed(kt ->{
			if(kt.getCode() == KeyCode.SPACE) {
				//System.out.print(0);
				fb.birdJump();
			}
		});
		
		primaryStage.setScene(gameScene);
		primaryStage.setTitle("FlappyBirds”Œœ∑");
		primaryStage.show();
	}
	public static void main(String[] args) {
		launch(args);
	}
}
