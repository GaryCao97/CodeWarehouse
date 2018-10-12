package matchIt;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class MatchItTest extends Application {
	public void start(Stage primaryStage) throws Exception {
		Scene scene = new Scene(new MatchPane());
		primaryStage.setScene(scene);
		primaryStage.setTitle("Á¬Á¬¿´");
		primaryStage.show();
	}
	public static void main(String[] args) {
		launch(args);
	}
}
